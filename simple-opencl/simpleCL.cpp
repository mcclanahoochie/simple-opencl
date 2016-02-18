/* #######################################################################
    Copyright 2011 Oscar Amoros Huguet, Cristian Garcia Marin

    This file is part of SimpleOpenCL

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

#include "simpleCL.h"

void sclPrintErrorFlags(cl_int flag)
{

    switch (flag) {

    case CL_DEVICE_NOT_FOUND:
        printf("\nCL_DEVICE_NOT_FOUND\n");
        break;
    case CL_DEVICE_NOT_AVAILABLE:
        printf("\nCL_DEVICE_NOT_AVAILABLE\n");
        break;
    case CL_COMPILER_NOT_AVAILABLE:
        printf("\nCL_COMPILER_NOT_AVAILABLE\n");
        break;
    case CL_PROFILING_INFO_NOT_AVAILABLE:
        printf("\nCL_PROFILING_INFO_NOT_AVAILABLE\n");
        break;
    case CL_MEM_COPY_OVERLAP:
        printf("\nCL_MEM_COPY_OVERLAP\n");
        break;
    case CL_IMAGE_FORMAT_MISMATCH:
        printf("\nCL_IMAGE_FORMAT_MISMATCH\n");
        break;
    case CL_IMAGE_FORMAT_NOT_SUPPORTED:
        printf("\nCL_IMAGE_FORMAT_NOT_SUPPORTED\n");
        break;
    case CL_INVALID_COMMAND_QUEUE:
        printf("\nCL_INVALID_COMMAND_QUEUE\n");
        break;
    case CL_INVALID_CONTEXT:
        printf("\nCL_INVALID_CONTEXT\n");
        break;
    case CL_INVALID_MEM_OBJECT:
        printf("\nCL_INVALID_MEM_OBJECT\n");
        break;
    case CL_INVALID_VALUE:
        printf("\nCL_INVALID_VALUE\n");
        break;
    case CL_INVALID_EVENT_WAIT_LIST:
        printf("\nCL_INVALID_EVENT_WAIT_LIST\n");
        break;
    case CL_MEM_OBJECT_ALLOCATION_FAILURE:
        printf("\nCL_MEM_OBJECT_ALLOCATION_FAILURE\n");
        break;
    case CL_OUT_OF_HOST_MEMORY:
        printf("\nCL_OUT_OF_HOST_MEMORY\n");
        break;
    case CL_INVALID_PROGRAM_EXECUTABLE:
        printf("\nCL_INVALID_PROGRAM_EXECUTABLE\n");
        break;
    case CL_INVALID_KERNEL:
        printf("\nCL_INVALID_KERNEL\n");
        break;
    case CL_INVALID_KERNEL_ARGS:
        printf("\nCL_INVALID_KERNEL_ARGS\n");
        break;
    case CL_INVALID_WORK_DIMENSION:
        printf("\nCL_INVALID_WORK_DIMENSION\n");
        break;
#ifndef __APPLE__
    case CL_INVALID_GLOBAL_WORK_SIZE:
        printf("\nCL_INVALID_GLOBAL_WORK_SIZE\n");
        break;
#endif
    case CL_INVALID_WORK_GROUP_SIZE:
        printf("\nCL_INVALID_WORK_GROUP_SIZE\n");
        break;
    case CL_INVALID_WORK_ITEM_SIZE:
        printf("\nCL_INVALID_WORK_ITEM_SIZE\n");
        break;
    case CL_INVALID_GLOBAL_OFFSET:
        printf("\nCL_INVALID_GLOBAL_OFFSET\n");
        break;
    case CL_OUT_OF_RESOURCES:
        printf("\nCL_OUT_OF_RESOURCES\n");
        break;
    case CL_INVALID_PROGRAM:
        printf("\nCL_INVALID_PROGRAM\n");
        break;
    case CL_INVALID_KERNEL_NAME:
        printf("\nCL_INVALID_KERNEL_NAME\n");
        break;
    case CL_INVALID_KERNEL_DEFINITION:
        printf("\nCL_INVALID_KERNEL_DEFINITION\n");
        break;
    case CL_INVALID_BUFFER_SIZE:
        printf("\nCL_INVALID_BUFFER_SIZE\n");
        break;
    case CL_BUILD_PROGRAM_FAILURE:
        printf("\nCL_BUILD_PROGRAM_FAILURE\n");
        break;
    case CL_INVALID_ARG_INDEX:
        printf("\nCL_INVALID_ARG_INDEX\n");
        break;
    case CL_INVALID_ARG_VALUE:
        printf("\nCL_INVALID_ARG_VALUE\n");
        break;
    case CL_MAP_FAILURE:
        printf("\nCL_MAP_FAILURE\n");
        break;
    case CL_MISALIGNED_SUB_BUFFER_OFFSET:
        printf("\nCL_MISALIGNED_SUB_BUFFER_OFFSET\n");
        break;
    case CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST:
        printf("\nCL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST\n");
        break;
    case CL_INVALID_DEVICE_TYPE:
        printf("\nCL_INVALID_DEVICE_TYPE\n");
        break;
    case CL_INVALID_PLATFORM:
        printf("\nCL_INVALID_PLATFORM\n");
        break;
    case CL_INVALID_DEVICE:
        printf("\nCL_INVALID_DEVICE\n");
        break;
    case CL_INVALID_QUEUE_PROPERTIES:
        printf("\nCL_INVALID_QUEUE_PROPERTIES\n");
        break;
    case CL_INVALID_HOST_PTR:
        printf("\nCL_INVALID_HOST_PTR\n");
        break;
    case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR:
        printf("\nCL_INVALID_IMAGE_FORMAT_DESCRIPTOR\n");
        break;
    case CL_INVALID_IMAGE_SIZE:
        printf("\nCL_INVALID_IMAGE_SIZE\n");
        break;
    case CL_INVALID_SAMPLER:
        printf("\nCL_INVALID_SAMPLER\n");
        break;
    case CL_INVALID_BINARY:
        printf("\nCL_INVALID_BINARY\n");
        break;
    case CL_INVALID_BUILD_OPTIONS:
        printf("\nCL_INVALID_BUILD_OPTIONS\n");
        break;
    case CL_INVALID_ARG_SIZE:
        printf("\nCL_INVALID_ARG_SIZE\n");
        break;
    case CL_INVALID_EVENT:
        printf("\nCL_INVALID_EVENT\n");
        break;
    case CL_INVALID_OPERATION:
        printf("\nCL_INVALID_OPERATION\n");
        break;
    case CL_INVALID_GL_OBJECT:
        printf("\nCL_INVALID_GL_OBJECT\n");
        break;
    case CL_INVALID_MIP_LEVEL:
        printf("\nCL_INVALID_MIP_LEVEL\n");
        break;
    case CL_INVALID_PROPERTY:
        printf("\nCL_INVALID_PROPERTY\n");
        break;
    default:
        printf("\nUnknown error code: %d\n", flag);
    }

    throw 1;//flag;
}

char* _sclLoadProgramSource(const char* filename)
{
    struct stat statbuf;
    FILE* fh;
    char* source;

    fh = fopen(filename, "r");
    if (fh == NULL) {
        fprintf(stderr, "Error on loadProgramSource");
        sclPrintErrorFlags(CL_INVALID_PROGRAM);
        return 0;
    }

    stat(filename, &statbuf);
    source = (char*)malloc(statbuf.st_size + 1);

    if (fread(source, statbuf.st_size, 1, fh) != 1) {
        fprintf(stderr, "Error on loadProgramSource");
        sclPrintErrorFlags(CL_INVALID_PROGRAM);
    }

    source[ statbuf.st_size ] = '\0';
    fclose(fh);
    return source;
}

cl_program _sclCreateProgram(char* program_source, cl_context context)
{
    cl_program program;
#ifdef DEBUG
    cl_int err;
    program = clCreateProgramWithSource(context, 1, (const char**)&program_source, NULL, &err);
    if (err != CL_SUCCESS) {
        printf("Error on createProgram\n");
        sclPrintErrorFlags(err);
    }
#else
    program = clCreateProgramWithSource(context, 1, (const char**)&program_source, NULL, NULL);
#endif
    return program;
}

void _sclBuildProgram(cl_program program, cl_device_id devices, const char* pName, const char* flags)
{
#ifdef DEBUG
    cl_int err;
    char build_c[4096];
    err = clBuildProgram(program, 0, NULL, flags, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("Error on buildProgram \n");
        sclPrintErrorFlags(err);
        fprintf(stdout, "\nRequestingInfo\n");
        clGetProgramBuildInfo(program, devices, CL_PROGRAM_BUILD_LOG, 4096, build_c, NULL);
        printf("Build Log for %s_program:\n%s\n", pName, build_c);
    }
#else
    clBuildProgram(program, 0, NULL, flags, NULL, NULL);
#endif
}

cl_kernel _sclCreateKernel(sclSoft software)
{
    cl_kernel kernel;
#ifdef DEBUG
    cl_int err;
    kernel = clCreateKernel(software.program, software.kernelName, &err);
    if (err != CL_SUCCESS) {
        printf("Error on createKernel %s \n", software.kernelName);
        sclPrintErrorFlags(err);
    }
#else
    kernel = clCreateKernel(software.program, software.kernelName, NULL);
#endif
    return kernel;
}

cl_event sclLaunchKernel(sclHard hardware, sclSoft software, size_t* global_work_size, size_t* local_work_size)
{
    cl_event myEvent = NULL;
#ifdef DEBUG
    cl_int err;
    err = clEnqueueNDRangeKernel(hardware.queue, software.kernel, 2, NULL, global_work_size, local_work_size, 0, NULL, &myEvent);
    if (err != CL_SUCCESS) {
        printf("Error on launchKernel %s \n", software.kernelName);
        sclPrintErrorFlags(err);
    }
#else
    clEnqueueNDRangeKernel(hardware.queue, software.kernel, 2, NULL, global_work_size, local_work_size, 0, NULL, NULL);
#endif
    sclFinish(hardware);
    return myEvent;
}

cl_event sclEnqueueKernel(sclHard hardware, sclSoft software, size_t* global_work_size, size_t* local_work_size)
{
    cl_event myEvent = NULL;
#ifdef DEBUG
    cl_int err;
    err = clEnqueueNDRangeKernel(hardware.queue, software.kernel, 2, NULL, global_work_size, local_work_size, 0, NULL, &myEvent);
    if (err != CL_SUCCESS) {
        printf("Error on launchKernel %s \n", software.kernelName);
        sclPrintErrorFlags(err);
    }
#else
    clEnqueueNDRangeKernel(hardware.queue, software.kernel, 2, NULL, global_work_size, local_work_size, 0, NULL, NULL);
#endif
    return myEvent;
}

void sclReleaseClSoft(sclSoft soft)
{
    clReleaseKernel(soft.kernel);
    clReleaseProgram(soft.program);
}

void sclReleaseClHard(sclHard hardware)
{
    clReleaseCommandQueue(hardware.queue);
    clReleaseContext(hardware.context);
}

void sclRetainClHard(sclHard hardware)
{
    clRetainCommandQueue(hardware.queue);
    clRetainContext(hardware.context);
}

void sclReleaseAllHardware(sclHard* hardList, int found)
{
    int i;
    for (i = 0; i < found; ++i) {
        sclReleaseClHard(hardList[i]);
    }
}

void sclRetainAllHardware(sclHard* hardList, int found)
{
    int i;
    for (i = 0; i < found; ++i) {
        sclRetainClHard(hardList[i]);
    }
}

void sclReleaseMemObject(cl_mem object)
{
    cl_int err;
    err = clReleaseMemObject(object);
    if (err != CL_SUCCESS) {
        printf("Error on sclReleaseMemObject \n");
        sclPrintErrorFlags(err);
    }
}

void sclPrintDeviceNamePlatforms(sclHard* hardList, int found)
{
    int i;
    cl_char deviceName[1024];
    cl_char platformVendor[1024];
    cl_char platformName[1024];
    for (i = 0; i < found; ++i) {
        clGetPlatformInfo(hardList[i].platform, CL_PLATFORM_NAME, sizeof(cl_char) * 1024, platformName, NULL);
        clGetPlatformInfo(hardList[i].platform, CL_PLATFORM_VENDOR, sizeof(cl_char) * 1024, platformVendor, NULL);
        clGetDeviceInfo(hardList[i].device, CL_DEVICE_NAME, sizeof(cl_char) * 1024, deviceName, NULL);
#ifdef DEBUG
        fprintf(stdout, "%d -  %d  %s  %s  %s\n", i,
                hardList[i].devNum, platformName, platformVendor, deviceName);
#endif
    }
}

void sclPrintHardwareStatus(sclHard hardware)
{
    cl_int err;
    char platform[100];
    cl_bool deviceAV;
    err = clGetPlatformInfo(hardware.platform,
                            CL_PLATFORM_NAME,
                            sizeof(char) * 100,
                            platform,
                            NULL);
    if (err == CL_SUCCESS) { fprintf(stdout, "Platform object alive \n"); }
    else { sclPrintErrorFlags(err); }
    err = clGetDeviceInfo(hardware.device,
                          CL_DEVICE_AVAILABLE,
                          sizeof(cl_bool),
                          (void*)(&deviceAV),
                          NULL);
    if (err == CL_SUCCESS && deviceAV) {
        fprintf(stdout, "Device object alive and device available. \n");
    } else if (err == CL_SUCCESS) {
        fprintf(stdout, "Device object alive and device NOT available.\n");
    } else {
        fprintf(stdout, "Device object not alive.\n");
    }
}

void _sclCreateQueues(sclHard* hardList, int found)
{
    int i;
#ifdef DEBUG
    cl_int err;
    for (i = 0; i < found; ++i) {
        hardList[i].queue = clCreateCommandQueue(hardList[i].context, hardList[i].device,
                            CL_QUEUE_PROFILING_ENABLE, &err);
        if (err != CL_SUCCESS) {
            fprintf(stdout, "Error creating command queue %d \n", i);
        }
    }
#else
    for (i = 0; i < found; ++i) {
        hardList[i].queue =
            clCreateCommandQueue(hardList[i].context, hardList[i].device, NULL, NULL);
    }
#endif
}

void _sclSmartCreateContexts(sclHard* hardList, int found)
{
    cl_device_id deviceList[16];
    cl_context context;
    char var_queries1[1024];
    char var_queries2[1024];
#ifdef DEBUG
    cl_int err;
#endif
    ptsclHard groups[10][20];
    int i, j, groupSet = 0;
    int groupSizes[10];
    int nGroups = 0;
    for (i = 0; i < found; ++i) {   /* Group generation */
        clGetPlatformInfo(hardList[i].platform, CL_PLATFORM_NAME, 1024, var_queries1, NULL);
        if (nGroups == 0) {
            groups[0][0] = &(hardList[0]);
            nGroups++;
            groupSizes[0] = 1;
        } else {
            groupSet = 0;
            for (j = 0; j < nGroups; ++j) {
                clGetPlatformInfo(groups[j][0]->platform, CL_PLATFORM_NAME, 1024, var_queries2, NULL);
                if (strcmp(var_queries1, var_queries2) == 0 &&
                        hardList[i].deviceType == groups[j][0]->deviceType &&
                        hardList[i].maxPointerSize == groups[j][0]->maxPointerSize) {
                    groups[j][ groupSizes[j] ] = &(hardList[i]);
                    groupSizes[j]++;
                    groupSet = 1;
                }
            }
            if (!groupSet) {
                groups[nGroups][0] = &(hardList[i]);
                groupSizes[nGroups] = 1;
                nGroups++;
            }
        }
    }

    for (i = 0; i < nGroups; ++i) {   /* Context generation */
#ifdef DEBUG
        fprintf(stdout, "Group %d with %d devices \n", i + 1, groupSizes[i]);
#endif
        for (j = 0; j < groupSizes[i]; ++j) {
            deviceList[j] = groups[i][j]->device;
        }
#ifdef DEBUG
        context = clCreateContext(0, groupSizes[i], deviceList, NULL, NULL, &err);
        if (err != CL_SUCCESS) {
            fprintf(stdout, "Error creating context on device %d \n", i);
        }
#else
        context = clCreateContext(0, groupSizes[i], deviceList, NULL, NULL, NULL);
#endif
        for (j = 0; j < groupSizes[i]; ++j) {
            groups[i][j]->context = context;
        }
    }
}

int _sclGetMaxComputeUnits(cl_device_id device)
{
    cl_uint nCompU;
    clGetDeviceInfo(device, CL_DEVICE_MAX_COMPUTE_UNITS, 4, (void*)&nCompU, NULL);
    return (int)nCompU;
}

unsigned long int _sclGetMaxMemAllocSize(cl_device_id device)
{
    cl_ulong mem;
    clGetDeviceInfo(device, CL_DEVICE_MAX_MEM_ALLOC_SIZE, 8, (void*)&mem, NULL);
    return (unsigned long int)mem;
}

int _sclGetDeviceType(cl_device_id device)
{
    int out = 2;
    char var_queries[1024];
    clGetDeviceInfo(device, CL_DEVICE_TYPE, 1024, var_queries, NULL);
    if (strcmp(var_queries, "CL_DEVICE_TYPE_GPU") == 0) {
        out = 0;
    } else if (strcmp(var_queries, "CL_DEVICE_TYPE_CPU") == 0) {
        out = 1;
    }
    return out;
}

sclHard sclGetDeviceByID(sclHard* hardList, int found, int idx)
{
    int device = 0;
    size_t returned_size = 0;
    cl_char vendor_name[1024];
    cl_char device_name[1024];
    cl_int err;
    device = idx < found ? idx : found - 1;
    device = device < 0 ? 0 : device;
// #ifdef DEBUG
    if (found) {
        returned_size = 0;
        vendor_name[0] = '\0';
        device_name[0] = '\0';
        err  = clGetDeviceInfo(hardList[device].device, CL_DEVICE_VENDOR, sizeof(vendor_name), vendor_name, &returned_size);
        err |= clGetDeviceInfo(hardList[device].device, CL_DEVICE_NAME, sizeof(device_name), device_name, &returned_size);
        if (err != CL_SUCCESS) {
            printf("Error 2 \n");
            sclPrintErrorFlags(err);
        }
        fprintf(stdout, "OpenCL device %d/%d selected: \t%s %s | %d Compute Units \n",
                device + 1, found, vendor_name, device_name, hardList[device].nComputeUnits);
    }
// #endif
    return hardList[ device ];
}

sclHard sclGetFastestDevice(sclHard* hardList, int found)
{
    int i, maxCpUnits = 0, device = 0;
    size_t returned_size = 0;
    cl_char vendor_name[1024];
    cl_char device_name[1024];
    cl_int err;
    for (i = 0; i < found ; ++i) {
#ifdef DEBUG
        fprintf(stdout, "Device %d Compute Units %d \n", i, hardList[i].nComputeUnits);
#endif
        if (maxCpUnits < hardList[i].nComputeUnits) {
            device = i;
            maxCpUnits = hardList[i].nComputeUnits;
        }
    }
// #ifdef DEBUG
    if (found) {
        returned_size = 0;
        vendor_name[0] = '\0';
        device_name[0] = '\0';
        err  = clGetDeviceInfo(hardList[device].device, CL_DEVICE_VENDOR, sizeof(vendor_name), vendor_name, &returned_size);
        err |= clGetDeviceInfo(hardList[device].device, CL_DEVICE_NAME, sizeof(device_name), device_name, &returned_size);
        if (err != CL_SUCCESS) {
            printf("Error 2 \n");
            sclPrintErrorFlags(err);
        }
        fprintf(stdout, "OpenCL device %d/%d selected: \t%s %s | %d Compute Units \n",
                device + 1, found, vendor_name, device_name, hardList[device].nComputeUnits);
    }
// #endif
    return hardList[ device ];
}

sclHard* sclGetAllHardware(int* found, cl_device_type compute_type)
{
    int i, j;
    cl_uint nPlatforms = 0, nDevices = 0;
    char* platformName;
    sclHard* hardList;
    *found = 0;
    cl_platform_id* GPUplatforms, *platforms;
    cl_int err;
    cl_device_id* devices;
    platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * 8);
    GPUplatforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * 8);
    platformName = (char*)malloc(sizeof(char) * 30);
    devices = (cl_device_id*)malloc(sizeof(cl_device_id) * 16);
    hardList = (sclHard*)malloc(16 * sizeof(sclHard));
    err = clGetPlatformIDs(8, platforms, &nPlatforms);
    if (nPlatforms == 0) {
        printf("No OpenCL plantforms found.\n");
    } else {
        for (i = 0; i < (int)nPlatforms; ++i) {
            err = clGetDeviceIDs(platforms[i], compute_type, 16, devices, &nDevices);
            if (nDevices == 0) {
                printf("No OpenCL enabled device found. \n");
                if (err != CL_SUCCESS) {
                    printf("Error clGetDeviceIDs \n");
                    sclPrintErrorFlags(err);
                }
            } else {
                for (j = 0; j < (int)nDevices; ++j) {
                    hardList[ *found ].platform       = platforms[ i ];
                    hardList[ *found ].device         = devices[ j ];
                    hardList[ *found ].nComputeUnits  = _sclGetMaxComputeUnits(hardList[ *found ].device);
                    hardList[ *found ].maxPointerSize = _sclGetMaxMemAllocSize(hardList[ *found ].device);
                    hardList[ *found ].deviceType     = _sclGetDeviceType(hardList[ *found ].device);
                    hardList[ *found ].devNum         = *found;
                    (*found)++;
                }
            }
        }
        _sclSmartCreateContexts(hardList, *found);
        _sclCreateQueues(hardList, *found);
    }
#ifdef DEBUG
    sclPrintDeviceNamePlatforms(hardList, *found);
#endif
    sclRetainAllHardware(hardList, *found);
    return hardList;
}

sclHard sclGetGPUHardware(int nDevice, int* found)
{
    int i, nTotalDevs = 0;
    int nGPUplatforms = 0;
    cl_platform_id* GPUplatforms;
    sclHard hardware;
    cl_int err;
    cl_uint nPlatforms, nDevices = 0;
    cl_platform_id* platforms;
    cl_device_id* devices;
    size_t returned_size;
    cl_char vendor_name[1024];
    cl_char device_name[1024];
    char* platformName;

    *found = 1;
    platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * 8);
    GPUplatforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * 8);
    platformName = (char*)malloc(sizeof(char) * 30);
    devices = (cl_device_id*)malloc(sizeof(cl_device_id) * 8);
    /*Get platform info ###################################################### */
    err = clGetPlatformIDs(8, platforms, &nPlatforms);
    /*printf("Number of platforms found: %d \n",nPlatforms);*/
    /* ###################################################### */

    if (nPlatforms == 0) {
        printf("No OpenCL platforms found.\n");
        *found = 0;
    } else if (nPlatforms == 1) {
        hardware.platform = platforms[0];
        err = clGetDeviceIDs(hardware.platform, CL_DEVICE_TYPE_GPU, 8, devices, &nDevices);
        /*if ( err != CL_SUCCESS ) {
        	printf( "Error clGetDeviceIDs\n" );
        	sclPrintErrorFlags( err ); }*/
        if (nDevices == 0) {
            printf("No OpenCL enabled GPU found.\n");
            *found = 0;
        }
    } else {
        for (i = 0; i < (int)nPlatforms; ++i) {
            err = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_GPU, 8, devices + nTotalDevs, &nDevices);
            /*if ( err != CL_SUCCESS ) {
            	printf( "Error clGetDeviceIDs\n" );
            	sclPrintErrorFlags( err ); }*/
            nTotalDevs += (int)nDevices;
            if (nDevices > 0) {
                GPUplatforms[nGPUplatforms] = platforms[i];
                nGPUplatforms++;
            }
        }
        if (nGPUplatforms == 0) {
            printf("No OpenCL enabled GPU found.\n");
            *found = 0;
        } else if (nGPUplatforms == 1) {
            hardware.platform = GPUplatforms[0];
            hardware.device = devices[nDevice];
        } else {
            err = clGetPlatformInfo(GPUplatforms[0], CL_PLATFORM_VENDOR, (size_t)30, (void*)platformName, NULL);
            if (err != CL_SUCCESS) {
                printf("Error clGetPlatformInfo \n");
                sclPrintErrorFlags(err);
            }
#ifdef DEBUG
            printf("More than one OpenCL platform with enabled GPU's.\nUsing: %s\n", platformName);
#endif
            hardware.platform = GPUplatforms[0];
            hardware.device = devices[nDevice];
        }
    }

#ifdef DEBUG
    printf("Number of devices found: %d \n", nDevices);
#endif
    if (nDevice < 0) {
        *found  = nDevices;
    } else {
        for (i = 0; i < nTotalDevs; ++i) {
            /*printf("Device %d id: %d\n",i+1,(int)(devices[i]));*/
            if (i == nDevice) {
                returned_size = 0;
                vendor_name[0] = '\0';
                device_name[0] = '\0';
                err  = clGetDeviceInfo(devices[i], CL_DEVICE_VENDOR, sizeof(vendor_name), vendor_name, &returned_size);
                err |= clGetDeviceInfo(devices[i], CL_DEVICE_NAME, sizeof(device_name), device_name, &returned_size);
                if (err != CL_SUCCESS) {
                    printf("Error 2 \n");
                    sclPrintErrorFlags(err);
                }
#ifdef DEBUG
                printf("Using device: %s %s\n", vendor_name, device_name);
#endif
            }
        }
        if (*found) {
            /* Create context ########################################################### */
            hardware.device = devices[nDevice];
            hardware.context = clCreateContext(0, 1, &hardware.device, NULL, NULL, &err);
            if (err != CL_SUCCESS) {
                printf("Error 3\n");
                sclPrintErrorFlags(err);
            }
            /* Create command queue ########################################################### */
            hardware.queue = clCreateCommandQueue(hardware.context, hardware.device, CL_QUEUE_PROFILING_ENABLE, &err);
            if (err != CL_SUCCESS) {
                printf("Error 3.1\n");
                sclPrintErrorFlags(err);
            }
        }
    }
    free(platforms);
    free(GPUplatforms);
    free(platformName);
    free(devices);
    return hardware;
}

sclHard sclGetCPUHardware(int nDevice, int* found)
{
    int i, nTotalDevs = 0;
    int nCPUplatforms = 0;
    cl_platform_id* CPUplatforms;
    sclHard hardware;
    cl_int err;
    cl_uint nPlatforms, nDevices = 0;
    cl_platform_id* platforms;
    cl_device_id* devices;
    size_t returned_size;
    cl_char vendor_name[1024];
    cl_char device_name[1024];
    char* platformName;

    *found = 1;
    platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * 8);
    CPUplatforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * 8);
    platformName = (char*)malloc(sizeof(char) * 30);
    devices = (cl_device_id*)malloc(sizeof(cl_device_id) * 8);
    /*Get platform info ###################################################### */
    err = clGetPlatformIDs(8, platforms, &nPlatforms);
    /*printf(" Number of platforms found: %d \n",nPlatforms);*/
    /* ###################################################### */

    if (nPlatforms == 0) {
        printf("No OpenCL platforms found.\n");
        *found = 0;
    } else if (nPlatforms == 1) {
        hardware.platform = platforms[0];
        err = clGetDeviceIDs(hardware.platform, CL_DEVICE_TYPE_CPU, 8, devices, &nDevices);
        if (err != CL_SUCCESS) {
            printf("Error clGetDeviceIDs\n");
            sclPrintErrorFlags(err);
        }
        if (nDevices == 0) {
            printf("No OpenCL enabled CPU found.\n");
            *found = 0;
        }
    } else {
        for (i = 0; i < (int)nPlatforms; ++i) {
            err = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_CPU, 8, devices + nTotalDevs, &nDevices);
            /*if ( err != CL_SUCCESS ) {
            	printf( "\nError clGetDeviceIDs" );
            	sclPrintErrorFlags( err ); }*/
            nTotalDevs += (int)nDevices;
            if (nDevices > 0) {
                CPUplatforms[nCPUplatforms] = platforms[i];
                nCPUplatforms++;
            }
        }
        if (nCPUplatforms == 0) {
            printf("No OpenCL enabled CPU found.\n");
            *found = 0;
        } else if (nCPUplatforms == 1) {
            hardware.platform = CPUplatforms[0];
            hardware.device = devices[nDevice];
        } else {
            err = clGetPlatformInfo(CPUplatforms[0], CL_PLATFORM_VENDOR, (size_t)30, (void*)platformName, NULL);
            if (err != CL_SUCCESS) {
                printf("Error clGetPlatformInfo\n");
                sclPrintErrorFlags(err);
            }
#ifdef DEBUG
            printf("More than one OpenCL platform with enabled CPU's.\nUsing: %s\n", platformName);
#endif
            hardware.platform = CPUplatforms[0];
            hardware.device = devices[nDevice];
        }
    }

#ifdef DEBUG
    printf("Number of devices found: %d \n", nDevices);
#endif
    if (nDevice < 0) {
        *found  = nDevices;
    } else {
        for (i = 0; i < (int)nTotalDevs; ++i) {
            /*printf("Device %d id: %d\n",i+1,(int)(devices[i]));*/
            if (i == nDevice) {
                returned_size = 0;
                vendor_name[0] = '\0';
                device_name[0] = '\0';
                err  = clGetDeviceInfo(devices[i], CL_DEVICE_VENDOR, sizeof(vendor_name), vendor_name, &returned_size);
                err |= clGetDeviceInfo(devices[i], CL_DEVICE_NAME, sizeof(device_name), device_name, &returned_size);
                if (err != CL_SUCCESS) {
                    printf("Error 2\n");
                    sclPrintErrorFlags(err);
                }
#ifdef DEBUG
                printf("Using device: %s %s\n", vendor_name, device_name);
#endif
            }
        }
        if (*found) {
            /* Create context ########################################################### */
            hardware.device = devices[nDevice];
            hardware.context = clCreateContext(0, 1, &hardware.device, NULL, NULL, &err);
            if (err != CL_SUCCESS) {
                printf("Error 3\n");
                sclPrintErrorFlags(err);
            }
            /* Create command queue ########################################################### */
            hardware.queue = clCreateCommandQueue(hardware.context, hardware.device, CL_QUEUE_PROFILING_ENABLE, &err);
            if (err != CL_SUCCESS) {
                printf("Error 3.1\n");
                sclPrintErrorFlags(err);
            }
        }
    }
    free(platforms);
    free(CPUplatforms);
    free(platformName);
    free(devices);
    return hardware;
}

sclSoft sclGetCLSoftware(char* path, char* name, sclHard hardware, char* flags)
{
    sclSoft software;
    FILE* fp = fopen(path, "r");
    if (fp) {
        fclose(fp);
        /* Load program source                */
        char* source = _sclLoadProgramSource(path);
        sprintf(software.kernelName, "%s", name);
        /* Create program objects from source                */
        software.program = _sclCreateProgram(source, hardware.context);
        /* Build the program (compile it)                */
        _sclBuildProgram(software.program, hardware.device, name, flags);
        /* Create the kernel object\                */
        software.kernel = _sclCreateKernel(software);
    } else {
        printf("[OpenCL] file not found: %s \n", path);
        exit(-1);
    }
    return software;
}

sclSoft sclGetCLSoftwareFromSource(char* source, char* name, sclHard hardware, char* flags)
{
    sclSoft software;
    sprintf(software.kernelName, "%s", name);
    /* Create program objects from source            */
    software.program = _sclCreateProgram(source, hardware.context);
    /* Build the program (compile it)            */
    _sclBuildProgram(software.program, hardware.device, name, flags);
    /* Create the kernel object            */
    software.kernel = _sclCreateKernel(software);
    return software;
}

cl_mem sclMalloc(sclHard hardware, cl_int mode, size_t size)
{
    cl_mem buffer;
#ifdef DEBUG
    cl_int err;
    buffer = clCreateBuffer(hardware.context, mode, size, NULL, &err);
    if (err != CL_SUCCESS) {
        printf("clMalloc Error\n  %lu \n", size);
        sclPrintErrorFlags(err);
    }
#else
    buffer = clCreateBuffer(hardware.context, mode, size, NULL, NULL);
#endif
    return buffer;
}

cl_mem sclMallocWrite(sclHard hardware, cl_int mode, size_t size, void* hostPointer)
{
    cl_mem buffer;

    buffer = sclMalloc(hardware, mode, size);

#ifdef DEBUG
    cl_int err;

    if (buffer == NULL) {
        fprintf(stderr,  "clMallocWrite Error on clCreateBuffer\n");
    }
    err = clEnqueueWriteBuffer(hardware.queue, buffer, CL_TRUE, 0, size, hostPointer, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("clMallocWrite Error on clEnqueueWriteBuffer\n");
        sclPrintErrorFlags(err);
    }
#else
    clEnqueueWriteBuffer(hardware.queue, buffer, CL_TRUE, 0, size, hostPointer, 0, NULL, NULL);
#endif
    return buffer;
}

void sclWrite(sclHard hardware, size_t size, cl_mem buffer, void* hostPointer, size_t offset)
{
#ifdef DEBUG
    cl_int err;
    err = clEnqueueWriteBuffer(hardware.queue, buffer, CL_TRUE, offset, size, hostPointer, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("clWrite Error\n");
        sclPrintErrorFlags(err);
    }
#else
    clEnqueueWriteBuffer(hardware.queue, buffer, CL_TRUE, offset, size, hostPointer, 0, NULL, NULL);
#endif
}

void sclRead(sclHard hardware, size_t size, cl_mem buffer, void* hostPointer)
{
#ifdef DEBUG
    cl_int err;
    err = clEnqueueReadBuffer(hardware.queue, buffer, CL_TRUE, 0, size, hostPointer, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("clRead Error\n");
        sclPrintErrorFlags(err);
    }
#else
    clEnqueueReadBuffer(hardware.queue, buffer, CL_TRUE, 0, size, hostPointer, 0, NULL, NULL);
#endif
}

void sclCopy(sclHard hardware, size_t size, cl_mem buffer_src, cl_mem buffer_dst)
{
#ifdef DEBUG
    cl_int err;
    err = clEnqueueCopyBuffer(hardware.queue, buffer_src, buffer_dst, 0, 0, size, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("clCopy Error\n");
        sclPrintErrorFlags(err);
    }
#else
    clEnqueueCopyBuffer(hardware.queue, buffer_src, buffer_dst, 0, 0, size, 0, NULL, NULL);
#endif
}

void sclMemset0(sclHard hardware, size_t size, cl_mem buffer)
{
    unsigned char zero = 0;
#ifdef DEBUG
    cl_int err;
    err = clEnqueueFillBuffer(hardware.queue, buffer, &zero, sizeof(unsigned char), 0, size, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("clFill Error\n");
        sclPrintErrorFlags(err);
    }
#else
    clEnqueueFillBuffer(hardware.queue, buffer, &zero, sizeof(unsigned char), 0, size, 0, NULL, NULL);
#endif
}

cl_int sclFinish(sclHard hardware)
{
    cl_int err;
#ifdef DEBUG
    err = clFinish(hardware.queue);
    if (err != CL_SUCCESS) {
        printf("Error clFinish\n");
        sclPrintErrorFlags(err);
        exit(-1);
    }
#else
    clFinish(hardware.queue);
#endif
    return err;
}

cl_ulong sclGetEventTime(sclHard hardware, cl_event event)
{
    cl_ulong elapsedTime, startTime, endTime;
    sclFinish(hardware);
    clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, NULL);
    clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, NULL);
    elapsedTime = endTime - startTime;
    return elapsedTime;
}

void sclSetKernelArg(sclSoft software, int argnum, size_t typeSize, void* argument)
{
#ifdef DEBUG
    cl_int err;
    err = clSetKernelArg(software.kernel, argnum, typeSize, argument);
    if (err != CL_SUCCESS) {
        printf("Error clSetKernelArg number %d\n", argnum);
        sclPrintErrorFlags(err);
    }
#else
    clSetKernelArg(software.kernel, argnum, typeSize, argument);
#endif
}

void _sclWriteArgOnAFile(int argnum, void* arg, size_t size, const char* diff)
{
    FILE* out;
    char filename[150];
    sprintf(filename, "../data/arg%d%s", argnum, diff);
    out = fopen(filename, "w+");
    fwrite(arg, 1, size, out);
    fclose(out);
}

inline void _sclVSetKernelArgs(sclSoft software, const char* sizesValues, va_list argList)
{
    const char* p;
    int argCount = 0;
    void* argument;
    size_t actual_size;
    for (p = sizesValues; *p != '\0'; p++) {
        if (*p == '%') {
            switch (*++p) {
            case 'a':
                actual_size = va_arg(argList, size_t);
                argument = va_arg(argList, void*);
                sclSetKernelArg(software, argCount, actual_size, argument);
                argCount++;
                break;
            case 'v':
                argument = va_arg(argList, void*);
                sclSetKernelArg(software, argCount, sizeof(cl_mem) , argument);
                argCount++;
                break;
            case 'N':
                actual_size = va_arg(argList, size_t);
                sclSetKernelArg(software, argCount, actual_size, NULL);
                argCount++;
                break;
            default:
                break;
            }
        }
    }
}

void sclSetKernelArgs(sclSoft software, const char* sizesValues, ...)
{
    va_list argList;
    va_start(argList, sizesValues);
    _sclVSetKernelArgs(software, sizesValues, argList);
    va_end(argList);
}

cl_event sclSetArgsLaunchKernel(sclHard hardware, sclSoft software, size_t* global_work_size, size_t* local_work_size,
                                const char* sizesValues, ...)
{
    va_list argList;
    cl_event event;
    va_start(argList, sizesValues);
    _sclVSetKernelArgs(software, sizesValues, argList);
    va_end(argList);
    event = sclLaunchKernel(hardware, software, global_work_size, local_work_size);
    return event;
}

cl_event sclSetArgsEnqueueKernel(sclHard hardware, sclSoft software, size_t* global_work_size, size_t* local_work_size,
                                 const char* sizesValues, ...)
{
    va_list argList;
    cl_event event;
    va_start(argList, sizesValues);
    _sclVSetKernelArgs(software, sizesValues, argList);
    va_end(argList);
    event = sclEnqueueKernel(hardware, software, global_work_size, local_work_size);
    return event;
}

cl_event sclManageArgsLaunchKernel(sclHard hardware, sclSoft software, size_t* global_work_size, size_t* local_work_size,
                                   const char* sizesValues, ...)
{
    va_list argList;
    cl_event event;
    const char* p;
    int argCount = 0, outArgCount = 0, inArgCount = 0, i;
    void* argument;
    size_t actual_size;
    cl_mem outBuffs[30];
    cl_mem inBuffs[30];
    size_t sizesOut[30];
    typedef unsigned char* puchar;
    puchar outArgs[30];

    va_start(argList, sizesValues);

    for (p = sizesValues; *p != '\0'; p++) {
        if (*p == '%') {
            switch (*++p) {
            case 'a': /* Single value non pointer argument */
                actual_size = va_arg(argList, size_t);
                argument = va_arg(argList, void*);
                sclSetKernelArg(software, argCount, actual_size, argument);
                argCount++;
                break;
            case 'v': /* Buffer or image object void* argument */
                argument = va_arg(argList, void*);
                sclSetKernelArg(software, argCount, sizeof(cl_mem) , argument);
                argCount++;
                break;
            case 'N': /* Local memory object using NULL argument */
                actual_size = va_arg(argList, size_t);
                sclSetKernelArg(software, argCount, actual_size, NULL);
                argCount++;
                break;
            case 'w': /* */
                sizesOut[ outArgCount ] = va_arg(argList, size_t);
                outArgs[ outArgCount ] = (unsigned char*)va_arg(argList, void*);
                outBuffs[ outArgCount ] = sclMalloc(hardware, CL_MEM_WRITE_ONLY,
                                                    sizesOut[ outArgCount ]);
                sclSetKernelArg(software, argCount, sizeof(cl_mem), &outBuffs[ outArgCount ]);
                argCount++;
                outArgCount++;
                break;
            case 'r': /* */
                actual_size = va_arg(argList, size_t);
                argument = va_arg(argList, void*);
                inBuffs[ inArgCount ] = sclMallocWrite(hardware, CL_MEM_READ_ONLY, actual_size, argument);
                sclSetKernelArg(software, argCount, sizeof(cl_mem), &inBuffs[ inArgCount ]);
                inArgCount++;
                argCount++;
                break;
            case 'R': /* */
                sizesOut[ outArgCount ] = va_arg(argList, size_t);
                outArgs[ outArgCount ] = (unsigned char*)va_arg(argList, void*);
                outBuffs[ outArgCount ] = sclMallocWrite(hardware, CL_MEM_READ_WRITE,
                                          sizesOut[ outArgCount ],
                                          outArgs[ outArgCount ]);
                sclSetKernelArg(software, argCount, sizeof(cl_mem), &outBuffs[ outArgCount ]);
                argCount++;
                outArgCount++;
                break;
            case 'g':
                actual_size = va_arg(argList, size_t);
                inBuffs[ inArgCount ] = sclMalloc(hardware, CL_MEM_READ_WRITE, actual_size);
                sclSetKernelArg(software, argCount, sizeof(cl_mem), &inBuffs[ inArgCount ]);
                inArgCount++;
                argCount++;
                break;
            default:
                break;
            }
        }
    }

    va_end(argList);
    event = sclLaunchKernel(hardware, software, global_work_size, local_work_size);
    for (i = 0; i < outArgCount; i++) {
        sclRead(hardware, sizesOut[i], outBuffs[i], outArgs[i]);
    }
    sclFinish(hardware);
    for (i = 0; i < outArgCount; i++) {
        sclReleaseMemObject(outBuffs[i]);
    }
    for (i = 0; i < inArgCount; i++) {
        sclReleaseMemObject(inBuffs[i]);
    }
    return event;
}

#ifdef __cplusplus
}
#endif
