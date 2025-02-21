/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_BACKENDS_GENERATED_TRACERS_H
#define TRACE_BACKENDS_GENERATED_TRACERS_H

#include "trace/control.h"

extern TraceEvent _TRACE_DBUS_VMSTATE_PRE_SAVE_EVENT;
extern TraceEvent _TRACE_DBUS_VMSTATE_POST_LOAD_EVENT;
extern TraceEvent _TRACE_DBUS_VMSTATE_LOADING_EVENT;
extern TraceEvent _TRACE_DBUS_VMSTATE_SAVING_EVENT;
extern TraceEvent _TRACE_IOMMUFD_BACKEND_CONNECT_EVENT;
extern TraceEvent _TRACE_IOMMUFD_BACKEND_DISCONNECT_EVENT;
extern TraceEvent _TRACE_IOMMU_BACKEND_SET_FD_EVENT;
extern TraceEvent _TRACE_IOMMUFD_BACKEND_MAP_DMA_EVENT;
extern TraceEvent _TRACE_IOMMUFD_BACKEND_UNMAP_DMA_NON_EXIST_EVENT;
extern TraceEvent _TRACE_IOMMUFD_BACKEND_UNMAP_DMA_EVENT;
extern TraceEvent _TRACE_IOMMUFD_BACKEND_ALLOC_IOAS_EVENT;
extern TraceEvent _TRACE_IOMMUFD_BACKEND_FREE_ID_EVENT;
extern uint16_t _TRACE_DBUS_VMSTATE_PRE_SAVE_DSTATE;
extern uint16_t _TRACE_DBUS_VMSTATE_POST_LOAD_DSTATE;
extern uint16_t _TRACE_DBUS_VMSTATE_LOADING_DSTATE;
extern uint16_t _TRACE_DBUS_VMSTATE_SAVING_DSTATE;
extern uint16_t _TRACE_IOMMUFD_BACKEND_CONNECT_DSTATE;
extern uint16_t _TRACE_IOMMUFD_BACKEND_DISCONNECT_DSTATE;
extern uint16_t _TRACE_IOMMU_BACKEND_SET_FD_DSTATE;
extern uint16_t _TRACE_IOMMUFD_BACKEND_MAP_DMA_DSTATE;
extern uint16_t _TRACE_IOMMUFD_BACKEND_UNMAP_DMA_NON_EXIST_DSTATE;
extern uint16_t _TRACE_IOMMUFD_BACKEND_UNMAP_DMA_DSTATE;
extern uint16_t _TRACE_IOMMUFD_BACKEND_ALLOC_IOAS_DSTATE;
extern uint16_t _TRACE_IOMMUFD_BACKEND_FREE_ID_DSTATE;
#define TRACE_DBUS_VMSTATE_PRE_SAVE_ENABLED 1
#define TRACE_DBUS_VMSTATE_POST_LOAD_ENABLED 1
#define TRACE_DBUS_VMSTATE_LOADING_ENABLED 1
#define TRACE_DBUS_VMSTATE_SAVING_ENABLED 1
#define TRACE_IOMMUFD_BACKEND_CONNECT_ENABLED 1
#define TRACE_IOMMUFD_BACKEND_DISCONNECT_ENABLED 1
#define TRACE_IOMMU_BACKEND_SET_FD_ENABLED 1
#define TRACE_IOMMUFD_BACKEND_MAP_DMA_ENABLED 1
#define TRACE_IOMMUFD_BACKEND_UNMAP_DMA_NON_EXIST_ENABLED 1
#define TRACE_IOMMUFD_BACKEND_UNMAP_DMA_ENABLED 1
#define TRACE_IOMMUFD_BACKEND_ALLOC_IOAS_ENABLED 1
#define TRACE_IOMMUFD_BACKEND_FREE_ID_ENABLED 1
#include "qemu/log-for-trace.h"
#include "qemu/error-report.h"


#define TRACE_DBUS_VMSTATE_PRE_SAVE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_DBUS_VMSTATE_PRE_SAVE) || \
    false)

static inline void _nocheck__trace_dbus_vmstate_pre_save(void)
{
    if (trace_event_get_state(TRACE_DBUS_VMSTATE_PRE_SAVE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 4 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:dbus_vmstate_pre_save "  "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     );
#line 64 "trace/trace-backends.h"
        } else {
#line 4 "../backends/trace-events"
            qemu_log("dbus_vmstate_pre_save "  "\n");
#line 68 "trace/trace-backends.h"
        }
    }
}

static inline void trace_dbus_vmstate_pre_save(void)
{
    if (true) {
        _nocheck__trace_dbus_vmstate_pre_save();
    }
}

#define TRACE_DBUS_VMSTATE_POST_LOAD_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_DBUS_VMSTATE_POST_LOAD) || \
    false)

static inline void _nocheck__trace_dbus_vmstate_post_load(int version_id)
{
    if (trace_event_get_state(TRACE_DBUS_VMSTATE_POST_LOAD) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 5 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:dbus_vmstate_post_load " "version_id: %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , version_id);
#line 95 "trace/trace-backends.h"
        } else {
#line 5 "../backends/trace-events"
            qemu_log("dbus_vmstate_post_load " "version_id: %d" "\n", version_id);
#line 99 "trace/trace-backends.h"
        }
    }
}

static inline void trace_dbus_vmstate_post_load(int version_id)
{
    if (true) {
        _nocheck__trace_dbus_vmstate_post_load(version_id);
    }
}

#define TRACE_DBUS_VMSTATE_LOADING_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_DBUS_VMSTATE_LOADING) || \
    false)

static inline void _nocheck__trace_dbus_vmstate_loading(const char * id)
{
    if (trace_event_get_state(TRACE_DBUS_VMSTATE_LOADING) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 6 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:dbus_vmstate_loading " "id: %s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , id);
#line 126 "trace/trace-backends.h"
        } else {
#line 6 "../backends/trace-events"
            qemu_log("dbus_vmstate_loading " "id: %s" "\n", id);
#line 130 "trace/trace-backends.h"
        }
    }
}

static inline void trace_dbus_vmstate_loading(const char * id)
{
    if (true) {
        _nocheck__trace_dbus_vmstate_loading(id);
    }
}

#define TRACE_DBUS_VMSTATE_SAVING_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_DBUS_VMSTATE_SAVING) || \
    false)

static inline void _nocheck__trace_dbus_vmstate_saving(const char * id)
{
    if (trace_event_get_state(TRACE_DBUS_VMSTATE_SAVING) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 7 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:dbus_vmstate_saving " "id: %s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , id);
#line 157 "trace/trace-backends.h"
        } else {
#line 7 "../backends/trace-events"
            qemu_log("dbus_vmstate_saving " "id: %s" "\n", id);
#line 161 "trace/trace-backends.h"
        }
    }
}

static inline void trace_dbus_vmstate_saving(const char * id)
{
    if (true) {
        _nocheck__trace_dbus_vmstate_saving(id);
    }
}

#define TRACE_IOMMUFD_BACKEND_CONNECT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOMMUFD_BACKEND_CONNECT) || \
    false)

static inline void _nocheck__trace_iommufd_backend_connect(int fd, bool owned, uint32_t users, int ret)
{
    if (trace_event_get_state(TRACE_IOMMUFD_BACKEND_CONNECT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 10 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:iommufd_backend_connect " "fd=%d owned=%d users=%d (%d)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , fd, owned, users, ret);
#line 188 "trace/trace-backends.h"
        } else {
#line 10 "../backends/trace-events"
            qemu_log("iommufd_backend_connect " "fd=%d owned=%d users=%d (%d)" "\n", fd, owned, users, ret);
#line 192 "trace/trace-backends.h"
        }
    }
}

static inline void trace_iommufd_backend_connect(int fd, bool owned, uint32_t users, int ret)
{
    if (true) {
        _nocheck__trace_iommufd_backend_connect(fd, owned, users, ret);
    }
}

#define TRACE_IOMMUFD_BACKEND_DISCONNECT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOMMUFD_BACKEND_DISCONNECT) || \
    false)

static inline void _nocheck__trace_iommufd_backend_disconnect(int fd, uint32_t users)
{
    if (trace_event_get_state(TRACE_IOMMUFD_BACKEND_DISCONNECT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 11 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:iommufd_backend_disconnect " "fd=%d users=%d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , fd, users);
#line 219 "trace/trace-backends.h"
        } else {
#line 11 "../backends/trace-events"
            qemu_log("iommufd_backend_disconnect " "fd=%d users=%d" "\n", fd, users);
#line 223 "trace/trace-backends.h"
        }
    }
}

static inline void trace_iommufd_backend_disconnect(int fd, uint32_t users)
{
    if (true) {
        _nocheck__trace_iommufd_backend_disconnect(fd, users);
    }
}

#define TRACE_IOMMU_BACKEND_SET_FD_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOMMU_BACKEND_SET_FD) || \
    false)

static inline void _nocheck__trace_iommu_backend_set_fd(int fd)
{
    if (trace_event_get_state(TRACE_IOMMU_BACKEND_SET_FD) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 12 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:iommu_backend_set_fd " "pre-opened /dev/iommu fd=%d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , fd);
#line 250 "trace/trace-backends.h"
        } else {
#line 12 "../backends/trace-events"
            qemu_log("iommu_backend_set_fd " "pre-opened /dev/iommu fd=%d" "\n", fd);
#line 254 "trace/trace-backends.h"
        }
    }
}

static inline void trace_iommu_backend_set_fd(int fd)
{
    if (true) {
        _nocheck__trace_iommu_backend_set_fd(fd);
    }
}

#define TRACE_IOMMUFD_BACKEND_MAP_DMA_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOMMUFD_BACKEND_MAP_DMA) || \
    false)

static inline void _nocheck__trace_iommufd_backend_map_dma(int iommufd, uint32_t ioas, uint64_t iova, uint64_t size, void * vaddr, bool readonly, int ret)
{
    if (trace_event_get_state(TRACE_IOMMUFD_BACKEND_MAP_DMA) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 13 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:iommufd_backend_map_dma " " iommufd=%d ioas=%d iova=0x%"PRIx64" size=0x%"PRIx64" addr=%p readonly=%d (%d)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , iommufd, ioas, iova, size, vaddr, readonly, ret);
#line 281 "trace/trace-backends.h"
        } else {
#line 13 "../backends/trace-events"
            qemu_log("iommufd_backend_map_dma " " iommufd=%d ioas=%d iova=0x%"PRIx64" size=0x%"PRIx64" addr=%p readonly=%d (%d)" "\n", iommufd, ioas, iova, size, vaddr, readonly, ret);
#line 285 "trace/trace-backends.h"
        }
    }
}

static inline void trace_iommufd_backend_map_dma(int iommufd, uint32_t ioas, uint64_t iova, uint64_t size, void * vaddr, bool readonly, int ret)
{
    if (true) {
        _nocheck__trace_iommufd_backend_map_dma(iommufd, ioas, iova, size, vaddr, readonly, ret);
    }
}

#define TRACE_IOMMUFD_BACKEND_UNMAP_DMA_NON_EXIST_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOMMUFD_BACKEND_UNMAP_DMA_NON_EXIST) || \
    false)

static inline void _nocheck__trace_iommufd_backend_unmap_dma_non_exist(int iommufd, uint32_t ioas, uint64_t iova, uint64_t size, int ret)
{
    if (trace_event_get_state(TRACE_IOMMUFD_BACKEND_UNMAP_DMA_NON_EXIST) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 14 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:iommufd_backend_unmap_dma_non_exist " " Unmap nonexistent mapping: iommufd=%d ioas=%d iova=0x%"PRIx64" size=0x%"PRIx64" (%d)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , iommufd, ioas, iova, size, ret);
#line 312 "trace/trace-backends.h"
        } else {
#line 14 "../backends/trace-events"
            qemu_log("iommufd_backend_unmap_dma_non_exist " " Unmap nonexistent mapping: iommufd=%d ioas=%d iova=0x%"PRIx64" size=0x%"PRIx64" (%d)" "\n", iommufd, ioas, iova, size, ret);
#line 316 "trace/trace-backends.h"
        }
    }
}

static inline void trace_iommufd_backend_unmap_dma_non_exist(int iommufd, uint32_t ioas, uint64_t iova, uint64_t size, int ret)
{
    if (true) {
        _nocheck__trace_iommufd_backend_unmap_dma_non_exist(iommufd, ioas, iova, size, ret);
    }
}

#define TRACE_IOMMUFD_BACKEND_UNMAP_DMA_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOMMUFD_BACKEND_UNMAP_DMA) || \
    false)

static inline void _nocheck__trace_iommufd_backend_unmap_dma(int iommufd, uint32_t ioas, uint64_t iova, uint64_t size, int ret)
{
    if (trace_event_get_state(TRACE_IOMMUFD_BACKEND_UNMAP_DMA) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 15 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:iommufd_backend_unmap_dma " " iommufd=%d ioas=%d iova=0x%"PRIx64" size=0x%"PRIx64" (%d)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , iommufd, ioas, iova, size, ret);
#line 343 "trace/trace-backends.h"
        } else {
#line 15 "../backends/trace-events"
            qemu_log("iommufd_backend_unmap_dma " " iommufd=%d ioas=%d iova=0x%"PRIx64" size=0x%"PRIx64" (%d)" "\n", iommufd, ioas, iova, size, ret);
#line 347 "trace/trace-backends.h"
        }
    }
}

static inline void trace_iommufd_backend_unmap_dma(int iommufd, uint32_t ioas, uint64_t iova, uint64_t size, int ret)
{
    if (true) {
        _nocheck__trace_iommufd_backend_unmap_dma(iommufd, ioas, iova, size, ret);
    }
}

#define TRACE_IOMMUFD_BACKEND_ALLOC_IOAS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOMMUFD_BACKEND_ALLOC_IOAS) || \
    false)

static inline void _nocheck__trace_iommufd_backend_alloc_ioas(int iommufd, uint32_t ioas, int ret)
{
    if (trace_event_get_state(TRACE_IOMMUFD_BACKEND_ALLOC_IOAS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 16 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:iommufd_backend_alloc_ioas " " iommufd=%d ioas=%d (%d)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , iommufd, ioas, ret);
#line 374 "trace/trace-backends.h"
        } else {
#line 16 "../backends/trace-events"
            qemu_log("iommufd_backend_alloc_ioas " " iommufd=%d ioas=%d (%d)" "\n", iommufd, ioas, ret);
#line 378 "trace/trace-backends.h"
        }
    }
}

static inline void trace_iommufd_backend_alloc_ioas(int iommufd, uint32_t ioas, int ret)
{
    if (true) {
        _nocheck__trace_iommufd_backend_alloc_ioas(iommufd, ioas, ret);
    }
}

#define TRACE_IOMMUFD_BACKEND_FREE_ID_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOMMUFD_BACKEND_FREE_ID) || \
    false)

static inline void _nocheck__trace_iommufd_backend_free_id(int iommufd, uint32_t id, int ret)
{
    if (trace_event_get_state(TRACE_IOMMUFD_BACKEND_FREE_ID) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 17 "../backends/trace-events"
            qemu_log("%d@%zu.%06zu:iommufd_backend_free_id " " iommufd=%d id=%d (%d)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , iommufd, id, ret);
#line 405 "trace/trace-backends.h"
        } else {
#line 17 "../backends/trace-events"
            qemu_log("iommufd_backend_free_id " " iommufd=%d id=%d (%d)" "\n", iommufd, id, ret);
#line 409 "trace/trace-backends.h"
        }
    }
}

static inline void trace_iommufd_backend_free_id(int iommufd, uint32_t id, int ret)
{
    if (true) {
        _nocheck__trace_iommufd_backend_free_id(iommufd, id, ret);
    }
}
#endif /* TRACE_BACKENDS_GENERATED_TRACERS_H */
