#pragma once

#define DEBUG_FUNCTION_STACK_SIZE 64

struct __fstack {
        const char  *func[DEBUG_FUNCTION_STACK_SIZE];
        const char  *file[DEBUG_FUNCTION_STACK_SIZE];
        int         line[DEBUG_FUNCTION_STACK_SIZE];
        label_t     size;
};
