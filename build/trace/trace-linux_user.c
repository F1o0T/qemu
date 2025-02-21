/* This file is autogenerated by tracetool, do not edit. */

#include "qemu/osdep.h"
#include "qemu/module.h"
#include "trace-linux_user.h"

uint16_t _TRACE_SIGNAL_TABLE_INIT_DSTATE;
uint16_t _TRACE_SIGNAL_DO_SIGACTION_GUEST_DSTATE;
uint16_t _TRACE_SIGNAL_DO_SIGACTION_HOST_DSTATE;
uint16_t _TRACE_USER_SETUP_FRAME_DSTATE;
uint16_t _TRACE_USER_SETUP_RT_FRAME_DSTATE;
uint16_t _TRACE_USER_DO_RT_SIGRETURN_DSTATE;
uint16_t _TRACE_USER_DO_SIGRETURN_DSTATE;
uint16_t _TRACE_USER_DUMP_CORE_AND_ABORT_DSTATE;
uint16_t _TRACE_USER_HANDLE_SIGNAL_DSTATE;
uint16_t _TRACE_USER_HOST_SIGNAL_DSTATE;
uint16_t _TRACE_USER_QUEUE_SIGNAL_DSTATE;
uint16_t _TRACE_USER_S390X_RESTORE_SIGREGS_DSTATE;
uint16_t _TRACE_TARGET_MPROTECT_DSTATE;
uint16_t _TRACE_TARGET_MMAP_DSTATE;
uint16_t _TRACE_TARGET_MMAP_COMPLETE_DSTATE;
uint16_t _TRACE_TARGET_MUNMAP_DSTATE;
TraceEvent _TRACE_SIGNAL_TABLE_INIT_EVENT = {
    .id = 0,
    .name = "signal_table_init",
    .sstate = TRACE_SIGNAL_TABLE_INIT_ENABLED,
    .dstate = &_TRACE_SIGNAL_TABLE_INIT_DSTATE 
};
TraceEvent _TRACE_SIGNAL_DO_SIGACTION_GUEST_EVENT = {
    .id = 0,
    .name = "signal_do_sigaction_guest",
    .sstate = TRACE_SIGNAL_DO_SIGACTION_GUEST_ENABLED,
    .dstate = &_TRACE_SIGNAL_DO_SIGACTION_GUEST_DSTATE 
};
TraceEvent _TRACE_SIGNAL_DO_SIGACTION_HOST_EVENT = {
    .id = 0,
    .name = "signal_do_sigaction_host",
    .sstate = TRACE_SIGNAL_DO_SIGACTION_HOST_ENABLED,
    .dstate = &_TRACE_SIGNAL_DO_SIGACTION_HOST_DSTATE 
};
TraceEvent _TRACE_USER_SETUP_FRAME_EVENT = {
    .id = 0,
    .name = "user_setup_frame",
    .sstate = TRACE_USER_SETUP_FRAME_ENABLED,
    .dstate = &_TRACE_USER_SETUP_FRAME_DSTATE 
};
TraceEvent _TRACE_USER_SETUP_RT_FRAME_EVENT = {
    .id = 0,
    .name = "user_setup_rt_frame",
    .sstate = TRACE_USER_SETUP_RT_FRAME_ENABLED,
    .dstate = &_TRACE_USER_SETUP_RT_FRAME_DSTATE 
};
TraceEvent _TRACE_USER_DO_RT_SIGRETURN_EVENT = {
    .id = 0,
    .name = "user_do_rt_sigreturn",
    .sstate = TRACE_USER_DO_RT_SIGRETURN_ENABLED,
    .dstate = &_TRACE_USER_DO_RT_SIGRETURN_DSTATE 
};
TraceEvent _TRACE_USER_DO_SIGRETURN_EVENT = {
    .id = 0,
    .name = "user_do_sigreturn",
    .sstate = TRACE_USER_DO_SIGRETURN_ENABLED,
    .dstate = &_TRACE_USER_DO_SIGRETURN_DSTATE 
};
TraceEvent _TRACE_USER_DUMP_CORE_AND_ABORT_EVENT = {
    .id = 0,
    .name = "user_dump_core_and_abort",
    .sstate = TRACE_USER_DUMP_CORE_AND_ABORT_ENABLED,
    .dstate = &_TRACE_USER_DUMP_CORE_AND_ABORT_DSTATE 
};
TraceEvent _TRACE_USER_HANDLE_SIGNAL_EVENT = {
    .id = 0,
    .name = "user_handle_signal",
    .sstate = TRACE_USER_HANDLE_SIGNAL_ENABLED,
    .dstate = &_TRACE_USER_HANDLE_SIGNAL_DSTATE 
};
TraceEvent _TRACE_USER_HOST_SIGNAL_EVENT = {
    .id = 0,
    .name = "user_host_signal",
    .sstate = TRACE_USER_HOST_SIGNAL_ENABLED,
    .dstate = &_TRACE_USER_HOST_SIGNAL_DSTATE 
};
TraceEvent _TRACE_USER_QUEUE_SIGNAL_EVENT = {
    .id = 0,
    .name = "user_queue_signal",
    .sstate = TRACE_USER_QUEUE_SIGNAL_ENABLED,
    .dstate = &_TRACE_USER_QUEUE_SIGNAL_DSTATE 
};
TraceEvent _TRACE_USER_S390X_RESTORE_SIGREGS_EVENT = {
    .id = 0,
    .name = "user_s390x_restore_sigregs",
    .sstate = TRACE_USER_S390X_RESTORE_SIGREGS_ENABLED,
    .dstate = &_TRACE_USER_S390X_RESTORE_SIGREGS_DSTATE 
};
TraceEvent _TRACE_TARGET_MPROTECT_EVENT = {
    .id = 0,
    .name = "target_mprotect",
    .sstate = TRACE_TARGET_MPROTECT_ENABLED,
    .dstate = &_TRACE_TARGET_MPROTECT_DSTATE 
};
TraceEvent _TRACE_TARGET_MMAP_EVENT = {
    .id = 0,
    .name = "target_mmap",
    .sstate = TRACE_TARGET_MMAP_ENABLED,
    .dstate = &_TRACE_TARGET_MMAP_DSTATE 
};
TraceEvent _TRACE_TARGET_MMAP_COMPLETE_EVENT = {
    .id = 0,
    .name = "target_mmap_complete",
    .sstate = TRACE_TARGET_MMAP_COMPLETE_ENABLED,
    .dstate = &_TRACE_TARGET_MMAP_COMPLETE_DSTATE 
};
TraceEvent _TRACE_TARGET_MUNMAP_EVENT = {
    .id = 0,
    .name = "target_munmap",
    .sstate = TRACE_TARGET_MUNMAP_ENABLED,
    .dstate = &_TRACE_TARGET_MUNMAP_DSTATE 
};
TraceEvent *linux_user_trace_events[] = {
    &_TRACE_SIGNAL_TABLE_INIT_EVENT,
    &_TRACE_SIGNAL_DO_SIGACTION_GUEST_EVENT,
    &_TRACE_SIGNAL_DO_SIGACTION_HOST_EVENT,
    &_TRACE_USER_SETUP_FRAME_EVENT,
    &_TRACE_USER_SETUP_RT_FRAME_EVENT,
    &_TRACE_USER_DO_RT_SIGRETURN_EVENT,
    &_TRACE_USER_DO_SIGRETURN_EVENT,
    &_TRACE_USER_DUMP_CORE_AND_ABORT_EVENT,
    &_TRACE_USER_HANDLE_SIGNAL_EVENT,
    &_TRACE_USER_HOST_SIGNAL_EVENT,
    &_TRACE_USER_QUEUE_SIGNAL_EVENT,
    &_TRACE_USER_S390X_RESTORE_SIGREGS_EVENT,
    &_TRACE_TARGET_MPROTECT_EVENT,
    &_TRACE_TARGET_MMAP_EVENT,
    &_TRACE_TARGET_MMAP_COMPLETE_EVENT,
    &_TRACE_TARGET_MUNMAP_EVENT,
  NULL,
};

static void trace_linux_user_register_events(void)
{
    trace_event_register_group(linux_user_trace_events);
}
trace_init(trace_linux_user_register_events)
