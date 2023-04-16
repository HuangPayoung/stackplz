#ifndef __STACKPLZ_TYPES_H__
#define __STACKPLZ_TYPES_H__

#include "common/consts.h"

typedef struct common_filter {
    u32 uid;
    u32 pid;
    u32 tid;
    u32 is_32bit;
} common_filter_t;

typedef struct args {
    unsigned long args[6];
} args_t;

typedef struct config_entry {
    u32 stackplz_pid;
} config_entry_t;

enum event_id_e
{
    SECURITY_FILE_MPROTECT = 456,
    SU_FILE_ACCESS,
    VMA_SET_PAGE_PROT
};

typedef struct event_context {
    u32 eventid;
    u32 host_tid;
    u32 host_pid;
    u32 tid;
    u32 pid;
    u32 uid;
    char comm[TASK_COMM_LEN];
    u64 ts;
    u8 argnum;
} event_context_t;

typedef struct event_data {
    event_context_t context;
    char args[ARGS_BUF_SIZE];
    u32 buf_off;
    struct task_struct *task;
} event_data_t;

#define MAX_EVENT_SIZE sizeof(event_context_t) + ARGS_BUF_SIZE

typedef struct program_data {
    config_entry_t *config;
    event_data_t *event;
    void *ctx;
} program_data_t;

typedef struct simple_buf {
    u8 buf[MAX_PERCPU_BUFSIZE];
} buf_t;


typedef struct vma_arg {
    u64 vma_ptr;
} vma_arg_t;

#define MAX_CACHED_PATH_SIZE 64

typedef u32 __kernel_dev_t;

typedef __kernel_dev_t dev_t;

typedef struct file_info {
    union {
        char pathname[MAX_CACHED_PATH_SIZE];
        char *pathname_p;
    };
    dev_t device;
    unsigned long inode;
    u64 ctime;
} file_info_t;

#endif