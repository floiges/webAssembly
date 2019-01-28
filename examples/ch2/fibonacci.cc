// 需要在JavaScript与C/C++之间交换大块的数据时，
// 直接使用参数传递数据显然不可行，此时可以通过内存来交换数据

#include <stdio.h>
#include <malloc.h>
#include "../em_port_api.h"

EM_PORT_API(int*) fibonacci(int count) {
    if (count <= 0) return NULL;

    int* re = (int*)malloc(count * 4);
    if (NULL == re) {
        printf("Not enough memory.\n");
        return NULL;
    }

    re[0] = 1;
    int i0 = 0, i1 = 1;
    for (int i = 1; i < count; i++) {
        re[i] = i0 + i1;
        i0 = i1;
        i1 = re[i];
    }
    return re;
} 


EM_PORT_API(void) free_buf(void* buf) {
    free(buf);
}