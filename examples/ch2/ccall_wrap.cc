#include <stdio.h>
#include <memory>
#include "../em_port_api.h"

// 使用ccall/cwrap时需要格外注意传入的字符串/数组的大小，避免爆栈

// ccall/cwrap辅助函数默认没有导出，
// 在编译时需要通过-s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']"选项显式导出
EM_PORT_API(double) add(double a, int b) {
    return a + (double)b;
}

// ccall的优势在于可以直接使用字符串/Uint8Array/Int8Array作为参数
EM_PORT_API(void) print_string(const char *str) {
    printf("C:print_string(): %s\n", str);
}

EM_PORT_API(int) sum(uint8_t* ptr, int count) {
    int total = 0, temp;
    for (int i = 0; i < count; i++) {
        memcpy(&temp, ptr + i * 4, 4);
        total += temp;
    }
    return total;
}

// 如果C导出函数返回了无需释放的字符串（静态字符串，或存放在由C代码自行管理的地址中的字符串），
// 在JavaScript中使用ccall调用，亦可直接获取返回的字符串
EM_PORT_API(const char *) get_string() {
    const static char str[] = "This is a test.";
    return str;
}