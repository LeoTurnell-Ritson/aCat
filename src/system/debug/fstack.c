#include <cat/private/catimpl.h>

#define DEBUG_FUNCTION_STACK_SIZE 64

struct __fstack {
        const char  *func[DEBUG_FUNCTION_STACK_SIZE];
        const char  *file[DEBUG_FUNCTION_STACK_SIZE];
        int         line[DEBUG_FUNCTION_STACK_SIZE];
        label_t     size;
};

static struct __fstack stack;

void __FunctionStackPush(const char *file, const char *func, const int line)
{
        if (stack.size < DEBUG_FUNCTION_STACK_SIZE) {
                stack.file[stack.size] = file;
                stack.func[stack.size] = func;
                stack.line[stack.size] = line;
        }
        ++stack.size;
}

void __FunctionStackPop(void)
{
        --stack.size;
        stack.file[stack.size] = NULL;
        stack.func[stack.size] = NULL;
        stack.line[stack.size] = 0;
}

void __FunctionStackUpdateLine(const char *func, const int line)
{
        if (stack.size > 0 && stack.func[stack.size - 1] == func) {
                stack.line[stack.size - 1] = line;
        }
}

void __FunctionStackCheck(void)
{
        label_t i;

        for (i = stack.size; i > 0; i--) {
                (void)CatFMeowf(MPI_COMM_SELF, CAT_STDERR,
                                "\033[1;36m%s:%d: \033[1;31mtrace: \033[0mIn function ‘\033[1;36m%s\033[0m’\n",
                                stack.file[i - 1], stack.line[i - 1], stack.func[i - 1]);
        }
}
