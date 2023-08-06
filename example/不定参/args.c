#define _GNU_SOURCE
#include <stdio.h>
/*学习不定参宏函数的使用*/

// #define LOG(fmt, ...) printf("[%s:%d]" fmt, __FILE__, __LINE__, ##__VA_ARGS__); // ... 表示不定参 ##__VA_ARGS__ 表示使用不定参
// int main()
// {
//     // printf("[%s:%d]%s-%d\n", __FILE__, __LINE__, "hello world", 666);
//     // LOG("%s, %d\n", "hello world", 666);
//     LOG("hello world\n"); // 不定参为空时，使用会出现问题，需要添加##__VA_ARGS__ 告诉编译器，如果不定参为空就取消前面的逗号
//     return 0;
// }

/*C语言不定参函数的使用，以及不定参数据访问*/

// #include <stdarg.h>
// void va_start(va_list ap, last); // 宏
// type va_arg(va_list ap, type);
// void va_end(va_list ap);
// void va_copy(va_list dest, va_list src);

#include <stdarg.h>
#include <stdlib.h>
void printNum(int count, ...)
{
    va_list ap;
    va_start(ap, count); // last 表示获取的是哪一个参数后第一个不定参的地址(获取指定参数的起始地址，这里就是获取count参数后的第一个参数的起始地址)
    for (int i = 0; i < count; ++i)
    {
        int num = va_arg(ap, int);
        printf("param[%d]:%d\n", i, num);
    }
    va_end(ap); // 将ap指针置空
}

// int vasprintf(char **strp, const char *fmt, va_list ap);
void myPrintf(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    char *res;
    int ret = vasprintf(&res, fmt, ap); // res需要free
    if (ret != -1)
    {
        printf(res);
        free(res);
    }
    va_end(ap);
}

int main()
{
    printNum(5, 1, 2, 3, 4, 5);
    myPrintf("%s-%d\n", "hello", 666);
}


