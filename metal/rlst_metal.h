#ifndef RLST_METAL_H
#define RLST_METAL_H

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import <MetalPerformanceShaders/MetalPerformanceShaders.h>

enum RLSTMtlResourceOptions {
  RLST_MTL_RESOURCE_STORAGE_MODE_SHARED =
      (unsigned int)MTLResourceStorageModeShared,
  RLST_MTL_RESOURCE_STORAGE_MODE_MANAGED =
      (unsigned int)MTLResourceStorageModeManaged,
  RLST_MTL_RESOURCE_STORAGE_MODE_PRIVATE =
      (unsigned int)MTLResourceStorageModePrivate,
  RLST_MTL_RESOURCE_STORAGE_MODE_MEMORYLESS =
      (unsigned int)MTLResourceStorageModeMemoryless,
  RLST_MTL_RESOURCE_HAZARD_TRACKING_MODE_DEFAULT =
      (unsigned int)MTLResourceHazardTrackingModeDefault,
  RLST_MTL_RESOURCE_HAZARD_TRACKING_MODE_UNTRACKED =
      (unsigned int)MTLResourceHazardTrackingModeUntracked,
  RLST_MTL_RESOURCE_HAZARD_TRACKING_MODE_TRACKED =
      (unsigned int)MTLResourceHazardTrackingModeTracked,
  RLST_MTL_RESOURCE_CPU_CACHE_MODE_WRITE_COMBINED =
      (unsigned int)MTLResourceCPUCacheModeWriteCombined,
  RLST_MTL_RESOURCE_CPU_CACHE_MODE_DEFAULT =
      (unsigned int)MTLResourceCPUCacheModeDefaultCache,

};

enum RLSTMtlMpsDataType {
    RLST_MTL_MPS_FLOAT32 = (unsigned int) MPSDataTypeFloat32,
};

enum RLSTMtlDispatchType {
    RLST_MTL_DISPATCH_TYPE_CONCURRENT = (unsigned int) MTLDispatchTypeConcurrent,
    RLST_MTL_DISPATCH_TYPE_SERIAL = (unsigned int) MTLDispatchTypeSerial,
};

typedef struct rlst_mtl_autorelease_pool_s *rlst_mtl_autorelease_pool_p;
typedef struct rlst_mtl_device_s *rlst_mtl_device_p;
typedef struct rlst_mtl_buffer_s *rlst_mtl_buffer_p;
typedef struct rlst_mtl_command_queue_s *rlst_mtl_command_queue_p;
typedef struct rlst_mtl_command_buffer_s *rlst_mtl_command_buffer_p;
typedef struct rlst_mtl_compute_command_encoder_s *rlst_mtl_compute_command_encoder_p;

/* Autorelease pool */

rlst_mtl_autorelease_pool_p rlst_mtl_new_autorelease_pool();
void rlst_mtl_autorelease_pool_drain(rlst_mtl_autorelease_pool_p p_pool);

/* Device definitions */

rlst_mtl_device_p rlst_mtl_new_default_device();
char *rlst_mtl_device_name(rlst_mtl_device_p p_device);
rlst_mtl_buffer_p rlst_mtl_device_new_buffer(rlst_mtl_device_p p_device,
                                             unsigned long length,
                                             unsigned int options);
rlst_mtl_command_queue_p rlst_mtl_device_new_command_queue(rlst_mtl_device_p p_device);

/* Buffer definitions */
void rlst_mtl_buffer_release(rlst_mtl_buffer_p p_buffer);
void *rlst_mtl_buffer_contents(rlst_mtl_buffer_p p_buffer);

/* Command Queue */
void rlst_mtl_command_queue_release(rlst_mtl_command_queue_p p_queue);
rlst_mtl_command_buffer_p rlst_mtl_command_queue_command_buffer(rlst_mtl_command_queue_p p_queue);

/* Command Buffer */

void rlst_mtl_command_buffer_wait_until_completed(rlst_mtl_command_buffer_p p_buffer);
void rlst_mtl_command_buffer_commit(rlst_mtl_command_buffer_p p_buffer);
rlst_mtl_compute_command_encoder_p rlst_mtl_command_buffer_compute_command_encoder(rlst_mtl_command_buffer_p p_buffer, unsigned long dispatch_type);



#endif /* RLST_METAL_H */