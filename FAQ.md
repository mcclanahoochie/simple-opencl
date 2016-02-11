# What is SimpleOpenCL #

SimpleOpenCL is a library written in ANSI C that aims to offer alternative functions to the default ones in OpenCL that are more simple. It encapsulates some functionalities in a single function call in order to reduce the code needed to write the most common OpenCL Host codes.

As such it doesn't need any special compiler. It only needs a properly installed OpenCL implementation and OpenCL compatible devices. The compilers being used for development and use of the library are gcc and g++.

# What isn't SimpleOpenCL #

This project doesn't aim to replace native OpenCL host code usage, neither to be used on complex production software. There are some complex tasks that can only be performed using native OpenCL. You can mix SimpleOpenCL and native OpenCL code at your convenience. Maybe in the future it becomes more complete, with more complex data transfer management, and more production ready but it is not the main goal. The main goal is to reduce code on most common host code tasks in a simple way.

It also isn't a CUDA like library for OpenCL. It is written with ANSI C and OpenCL working in mind, and functions are created with the single goal of code reduction, regardless of the similarity or dissimilarity with CUDA of the resulting functions.

# Can I use SimpleOpenCL for easy OpenCL Kernel unitary tests? #

Yes. SimpleOpenCL is mainly intended for testing OpenCL kernels, with far less work than with plain OpenCL, and without the need of knowing anything about OpenCL objects (devices, contexts, buffers etc).
SimpleOpenCL is divided in tree levels. The first level, or Unitary Test Level (UTL), is what we are describing here.

# What can I do with SimpleOpenCL First Level or Unitary Test Level (UTL)? #

Every thing. You end up calling an OpenCL kernel with a single C function call. You can set the device you want to test, or let SimpleOpenCL to automatically find the fastest device in your system. You also can test NDRange kernel dimensions for tuning the performance of your kernel. Also, you get the kernel call event in order to ask the OpenCL runtime for the execution time of the Kernel, with a simple SimpleOpenCL call.

# Can I use SimpleOpenCL Unitary Test Level (UTL) for a full application? #

Yes, you can. But depending on the hardware and your performance needs, it might not be the best option. If you need more control over memory management and performance we advise you to use SimpleOpenCL Second Level functions.