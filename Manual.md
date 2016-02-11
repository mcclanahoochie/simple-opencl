# Manual summary #



# Introduction #

This section shows how to use SimpleOpenCL. We only show First level functions in this section, that are the main goal of the project.

SimpleOpenCL eliminates the need of knowing about OpenCL objects. **The only thing a programmer needs to know in order to use SimpleOpenCL is C, two SimpleOpenCL types, and few functions**.

The functions and data types offer the following functionality:

  1. To select in which device you want to run your code.
  1. To select the code you want to execute (OpenCL Kernels).
  1. To execute the selected code in the selected device.

# Selecting the device #
SimpleOpenCL provides some functions in order to select the desired hardware. The user can choose any of those, depending on what he wants. All the functions use the "sclHard" SimpleOpenCL type, to represent a hardware device. Please refer to SimpleOpenCL Specification to know more about SimpleOpenCL types.

## sclGetAllHardware ##
This SimpleOpenCL function, returns a list with all the OpenCL compatible hardware on the system.
```
sclHard* sclGetAllHardware( int* found );
```

It returns a list of hardware devices found as sclHard pointers, and gets an integer pointer as parameter to store the number of devices found.

**WARNING:** this function was different before version 0.010\_27\_02\_2013. Download the latest SimpleOpenCL version to use it as explained on this section.

## sclGetFastestDevice ##

This function returns the fastest device considering the number of compute units, independently of the device type.

```
sclHard sclGetFastestDevice( sclHard* hardList, int found );
```

## sclGetGPUHardware ##

This function allows the programmer to select GPU hardware. The nDevice parameter allows to specify exactly which device if there are more than one.
```
sclHard                 sclGetGPUHardware( int nDevice, int* found );
```
## sclGetCPUHardware ##
This function allows the programmer to select CPU hardware. The nDevice parameter allows to specify exactly which device if there are more than one.
```
sclHard                 sclGetCPUHardware( int nDevice, int* found );
```
# Selecting the code #
SimpleOpenCL also provides a function that allows to load a .cl file with one or more kernels, compile it at runtime, and if there was a compiling error on the .cl file, the compiling error messages will be printed on the command line (stdout).

```
sclSoft sclGetCLSoftware( char* path, char* name, sclHard hardware );
```

This function is sclGetCLSoftware, and takes the path of the source file to be loaded, the name of the kernel function to be called when executing the code, and the hardware that will execute it. It is necessary to specify the hardware, in order to let the OpenCL C compiler to know which binary (assembler) code it has to produce. The assembler code is completely hardware dependent.

The function returns an sclSoft variable that reprents the compiled OpenCL kernel code. Please refer to SimpleOpenCL specification to know more about sclSoft and SimpleOpenCL types.

# Executing the code on the device #
Once we have selected the hardware and the software, we just have to execute it.

The function sclManageArgsLaunchKernel takes as arguments an "sclHard hardware" and an "sclSoft software", the NDRange kernel dimensions (global\_work\_size and local\_work\_size), a string that will contain the information about the parameters sent to the OpenCL Kernel (sizesValues), and a variable number of `void*` parameters (...). This `void*` parameters will be the parameter variables sent to the OpenCL kernel.

```
cl_event sclManageArgsLaunchKernel( sclHard hardware, 
                                   sclSoft software, 
                                   size_t *global_work_size, 
                                   size_t *local_work_size,
                                   const char* sizesValues, 
                                   ... );
```

This function takes all the kernel arguments, in the same order as in the kernel starting, on the "`...`". In order to automatically do all the OpenCL hard work left at this stage of the code, this SimpleOpenCL function needs you to indicate three main things:
  1. The size of each parameter variable.
  1. What to do with this variable ( is it the input data for the kernel? or the output, or just a variable to be exclusively used by the hardware? )
  1. In which memory layer should the variable be allocated? (Refer to OpenCL memory hierarchy to know more about memory layers in OpenCL C kernels).

To this end, SimpleOpenCL provides a short way to indicate this, with a printf-like codification. The programmer, should write a string as the "sizesValues" parameter. In this string, the information is written after a "%" like in the C printf standard function. A table of characters and its meaning is shown below.

| **Character** | **Number of parameters** | **Action to be performed by SimpleOpenCL** | **Memory layer flags on the kernel code** |
|:--------------|:-------------------------|:-------------------------------------------|:------------------------------------------|
| **%a**        | 2 (size\_t varSize,`void*` var)| When SimpleOpenCL finds %a, it reads a size\_t argument, and a `void*` argument in this order. It is intended for non pointer arguments like int, float etc. size\_t size is the variable size in bytes and `void*` var is the pointer to the variable. **Only for experienced OpenCL programmers** SimpleOpenCL only sets this variable as a kernel parameter without creating any buffer. For this reason, a% can be also used for any cl\_mem variable manually controlled by the programmer. | `__global, __constant`                    |
| **%N**        | 1 (size\_t varSize)      | When SimpleOpenCL finds %N, it sets a local memory pointer with size "varSize" | `__local`                                 |
| **%w**        | 2 (size\_t varSize, `void*` var) | Wirte only. When SimpleOpenCL finds %w, it sets a global memory pointer with size "varSize". When the execution of the kernel is done, it automatically copies the results from the hardware to the variable "var". | `__global`                                |
| **%r**        | 2 (size\_t varSize, `void*` var) | Read only. When SimpleOpenCL finds %r it sets a global memory pointer with size "varSize". Before the execution of the kernel, the contents of "var" are copied to the hardware device selected. | `__global, __constant`                    |
| **%R**        | 2 (size\_t varSize, `void*` var) | Read write. When SimpleOpenCL finds %R it sets a global memory pointer with size "varSize". Before the execution of the kernel, the contents of "var" are copied to the hardware device selected. When the execution of the kernel is done, it automatically copies the results from the hardware to the variable "var". | `__global`                                |
| **%g**        | 1 (size\_t varSize)      | When SimpleOpenCL finds %g it sets a global memory pointer with size "varSize" in read write mode. Tis pointer will not be read or written from the main program. | `__global`                                |

# Short example #

In this example, we show a SimpleOpenCL program that does the following:

  1. It generates a vector of 134217728 float values that start at 0 and end at 134217728-1, and a float variable with the value "3" on the Host.
  1. Then the program initializes the OpenCL kernel code (`sclSoft software`) and the OpenCL hardware (`sclHard *hardware`).
  1. Finally, it sends the array and the value "3" to the first device found on the system, sets a 2DRange kernel, and executes it on the first device (`hardware[0]`).
  1. On the OpenCL NDRange kernel, each WorkItem multiplies the value of the vector corresponding to its global index in the x dimension (`vector[get_global_id(0)]`), by the value "3" (`float* value`) and stores the result on the same vector position (`vector[get_global_id(0)]`).

This is the SimpleOpenCL Host code (main.c):

```
#include "simpleCL.h"

int main( int argc, char *argv[] ){

        float* vector;
        float value;
        int i,found;
        /* SimpleOpenCL types declaration */
        sclHard* hardware;
        sclSoft software;

        /* NDRange 2D size initialization*/
        size_t global_size[2];
        size_t local_size[2];
        size_t dataLength=134217728;
        size_t dataSize=sizeof(float)*dataLength;
    
        global_size[0]=dataLength; global_size[1]=1;
        local_size[0]=64; local_size[1]=1;
        /*local_size[0]=1 might be necessary for Intel devices on apple machines*/


        /* Data generation */
        vector = (float*)malloc(dataSize);
        value = 3;
        for (i=0; i<dataLength; i++){
                vector[i] = (float)i;
        }   

        /* Hardware and Software initialization ##### HERE STARTS THE SimpleOpenCL CODE ####*/
        found=0;
        hardware = sclGetAllHardware(&found);
        software = sclGetCLSoftware("example2.cl","example2",hardware[0]);

        /* Kernel execution */
        sclManageArgsLaunchKernel( hardware[0], software,
                                   global_size, local_size,
                                   "%R %a %N",
                                   dataSize, (void*)vector, sizeof(float), (void*)&value, sizeof(float));

        /* Data is read back from the device automatically  ##### HERE ENDS THE SimpleOpenCL CODE ####*/
        /* We print some values to check the results */
        printf("\nExecution successful\n");
        printf("vector[0]=%f vector[10]=%f vector[200]=%f\n",vector[0],vector[10],vector[200]);

        return 0;
    
}
```

As we can see on the code above, we have used a read/write variable (%R), a read only variable (%r) and a local memory variable (%N).

Now the kernel code (example2.cl):

```
/* Kernel and kernel parameters declaration*/
__kernel void example2( __global float *vector,
                        float value,
                        __local float *valueLocal){
        /* Reading the WorkItem index*/
        int local_x = get_local_id(0);
        int global_x = get_global_id(0);
            
        /* Copying the read only value to local memory for faster broadcast reads */
        if (local_x == 0) {
                *valueLocal=value;
        }
        /* Barrier for avoiding valueLocal to be used by any thread before it is fully written. 
        Thanks Bryan Little*/ 
        barrier(CLK_LOCAL_MEM_FENCE); 
        /* Final multiplication, stored on the same vector */
        vector[global_x] = vector[global_x] * *valueLocal;
        /* Barrier to avoid that some OpenCL implementation optimizations 
            make the system to start reading results from the Device to the Host
            before they are completely stored in global memory. */ 
        barrier(CLK_GLOBAL_MEM_FENCE);
}
```

This code is executed super fast both on the GPU and the CPU. Note that NDRange kernels, even designed for GPU's, when executed on the CPU are not simulated but compiled and optimized for the target CPU. So performance must be very competitive on the CPU, comparing to other CPU parallelization standards.

Also note, that the vector array size may be too big for some GPU devices. Try to make it smaller if you get the error CL\_INVALID\_BUFFER\_SIZE.

# Compiling the code #

SimpleOpenCL code consists by now of only one C file (simpleCL.c), and it's header file (simpleCL.h). To compile your program, you have to compile your code along with simpleCL.c. It is very fast to compile since it is a quite short, but useful code.

Each OpenCL implementation comes with a manual for compiling it, indicating necessary libraries and compiler flags. The question is, if you know how to compile OpenCL, you know how to compile SimpleOpenCL, since it is an OpenCL code.

Note, that the next examples work when simpleCL.c and simpleCL.h are on the same folder as the example code main.c and example2.cl.

Compiling in Linux with AMD OpenCL 1.2 implementation:

```
gcc -O3 -I/opt/AMDAPP/include main.c simpleCL.c -o myapp -lOpenCL
```

Compiling in Ubuntu Linux 12.10 with CUDA toolkit installed through aptitude (sudo apt-get install nvidia-cuda-toolkit):

```
gcc -O3 main.c simpleCL.c -o myapp -lOpenCL
```

Compiling in OS X:

```
gcc -O3 main.c simpleCL.c -o myapp -framework OpenCL
```

Executing the code both in Linux and OS X looks like this:
```
./myapp
```

Execution output for an AMD machine (in this case Device 1 is selected, "`hardware[1]`" on the Host code):

```
Group 1 with 1 devices
Group 2 with 1 devices
Group 3 with 1 devices
 Device 0 
 Platform name: AMD Accelerated Parallel Processing 
 Vendor: Advanced Micro Devices, Inc. 
 Device name: Juniper
 Device 1 
 Platform name: AMD Accelerated Parallel Processing 
 Vendor: Advanced Micro Devices, Inc. 
 Device name: Tahiti
 Device 2 
 Platform name: AMD Accelerated Parallel Processing 
 Vendor: Advanced Micro Devices, Inc. 
 Device name: AMD Phenom(tm) II X4 955 Processor
Execution successful
vector[0]=0.000000 vector[10]=30.000000 vector[200]=600.000000
```

Execution output for an NVIDIA machine:

```
Group 1 with 1 devices
 Device 0 
 Platform name: NVIDIA CUDA 
 Vendor: NVIDIA Corporation 
 Device name: GeForce 8800 GTX
Execution successful
vector[0]=0.000000 vector[10]=30.000000 vector[200]=600.000000
```

Execution output for an Apple machine:

```
Group 1 with 1 devices
Group 2 with 1 devices
 Device 0 
 Platform name: Apple 
 Vendor: Apple 
 Device name: Intel(R) Core(TM) i7-3667U CPU @ 2.00GHz
 Device 1 
 Platform name: Apple 
 Vendor: Apple 
 Device name: HD Graphics 4000
Execution successful
vector[0]=0.000000 vector[10]=30.000000 vector[200]=600.000000
```

Note that the "Group" term, refers to memory context in OpenCL. SimpleOpenCL automatically creates different or the same context for devices of different vendors, types or memory capacities, or the same vendor, type and memory capacity respectively. Only devices that use the same OpenCL platform, are of the same type and have the same amount of memory, will share the same OpenCL context. Refer to OpenCL documentation to know more about OpenCL context.