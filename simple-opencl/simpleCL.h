/* #######################################################################
    Copyright 2011 Oscar Amoros Huguet, Cristian Garcia Marin

    This file is part of SimpleOpenCL.

    SimpleOpenCL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3.

    SimpleOpenCL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SimpleOpenCL. If not, see <http://www.gnu.org/licenses/>.

   #######################################################################

   SimpleOpenCL Version 0.020_17_02_2016

   Modified by Chris McClanahan 11/01/11 & 11/03/15 & 02/17/16
*/

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#ifndef MAC
#define MAC
#endif
#else
#include <CL/cl.h>
#endif



     // #define SKIP_IGPU  // xxx  define to not use integrated cpu/gpu.  (recommended)
    // #define DEBUG  // XXX  cl_event memory leak



#ifndef _OCLUTILS_STRUCTS
typedef struct {
    cl_platform_id platform;
    cl_context context;
    cl_device_id device;
    cl_command_queue queue;
    int nComputeUnits;
    unsigned long int maxPointerSize;
    int deviceType; /* deviceType 0 = GPU | deviceType 1 = CPU | deviceType 2 = other */
    int devNum;
} sclHard;
typedef sclHard* ptsclHard;
typedef struct {
    cl_program program;
    cl_kernel kernel;
    char kernelName[96];
} sclSoft;
#define _OCLUTILS_STRUCTS
#endif

/* USER FUNCTIONS */
/* ####### Device memory allocation read and write  ####### */

cl_mem 			sclMalloc(sclHard hardware, cl_int mode, size_t size);
cl_mem 			sclMallocWrite(sclHard hardware, cl_int mode, size_t size, void* hostPointer);
void 			sclWrite(sclHard hardware, size_t size, cl_mem buffer, void* hostPointer, size_t offset=0);
void			sclRead(sclHard hardware, size_t size, cl_mem buffer, void* hostPointer, size_t offset=0);
void			sclCopy(sclHard hardware, size_t size, cl_mem buffer_src, cl_mem buffer_dst);
void			sclMemset0(sclHard hardware, size_t size, cl_mem buffer); // ocl v1.2+ !!!

/* ######################################################## */

/* ####### initialization of sclSoft structs  ############## */

sclSoft 		sclGetCLSoftware(const char* path, const char* name, sclHard hardware, const char* flags=NULL);
sclSoft			sclGetCLSoftwareFromSource(const char* source, const char* name, sclHard hardware, const char* flags=NULL);

/* ######################################################## */

/* ####### Release and retain OpenCL objects ############## */

void 			sclReleaseClSoft(sclSoft soft);
void 			sclReleaseClHard(sclHard hard);
void 			sclRetainClHard(sclHard hardware);
void 			sclReleaseAllHardware(sclHard* hardList, int found);
void 			sclRetainAllHardware(sclHard* hardList, int found);
void			sclReleaseMemObject(cl_mem object);

/* ######################################################## */

/* ####### Debug functions ################################ */

void 			sclPrintErrorFlags(cl_int flag);
void 			sclPrintHardwareStatus(sclHard hardware);
void 			sclPrintDeviceNamePlatforms(sclHard* hardList, int found);

/* ######################################################## */

/* ####### Device execution ############################### */

cl_event 		sclLaunchKernel(sclHard hardware, sclSoft software, size_t* global_work_size, size_t* local_work_size);
cl_event		sclEnqueueKernel(sclHard hardware, sclSoft software, size_t* global_work_size, size_t* local_work_size);
cl_event		sclSetArgsLaunchKernel(sclHard hardware, sclSoft software, size_t* global_work_size, size_t* local_work_size, const char* sizesValues, ...);
cl_event		sclSetArgsEnqueueKernel(sclHard hardware, sclSoft software, size_t* global_work_size, size_t* local_work_size, const char* sizesValues, ...);
cl_event		sclManageArgsLaunchKernel(sclHard hardware, sclSoft software, size_t* global_work_size, size_t* local_work_size, const char* sizesValues, ...);

/* ######################################################## */

/* ####### Event queries ################################## */

cl_ulong 		sclGetEventTime(sclHard hardware, cl_event event);

/* ######################################################## */

/* ####### Queue management ############################### */

cl_int			sclFinish(sclHard hardware);

/* ######################################################## */

/* ####### Kernel argument setting ######################## */

void 			sclSetKernelArg(sclSoft software, int argnum, size_t typeSize, void* argument);
void			sclSetKernelArgs(sclSoft software, const char* sizesValues, ...);
void 			_sclVSetKernelArgs(sclSoft software, const char* sizesValues, va_list argList);

/* ######################################################## */

/* ####### Hardware init and selection #################### */

sclHard 		sclGetGPUHardware(int nDevice, int* found);
sclHard 		sclGetCPUHardware(int nDevice, int* found);
sclHard*		sclGetAllHardware(int* found, cl_device_type compute_type=CL_DEVICE_TYPE_ALL);
sclHard 		sclGetFastestDevice(sclHard* hardList, int found);
sclHard 		sclGetDeviceByID(sclHard* hardList, int found, int idx);

/* ######################################################## */

/* INTERNAL FUNCITONS */

/* ####### debug ########################################## */

void 			_sclWriteArgOnAFile(int argnum, void* arg, size_t size, const char* diff);

/* ######################################################## */

/* ####### cl software management ######################### */

void 			_sclBuildProgram(cl_program program, cl_device_id devices, const char* pName, const char* flags=NULL);
cl_kernel 		_sclCreateKernel(sclSoft software);
cl_program 		_sclCreateProgram(const char* program_source, cl_context context);
char* 			_sclLoadProgramSource(const char* filename);

/* ######################################################## */

/* ####### hardware management ############################ */

int 			  _sclGetMaxComputeUnits(cl_device_id device);
unsigned long int _sclGetMaxMemAllocSize(cl_device_id device);
int 			  _sclGetDeviceType(cl_device_id device);
void 			  _sclSmartCreateContexts(sclHard* hardList, int found);
void 			  _sclCreateQueues(sclHard* hardList, int found);

/* ######################################################## */

#ifdef __cplusplus
}
#endif
