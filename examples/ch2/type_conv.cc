#include <stdio.h>
#include "../em_port_api.h"

EM_PORT_API(void) print_int(int a) {
    printf("C{print_int() a:%d}", a);
}

EM_PORT_API(void) print_float(float a) {
    printf("C{print_float() a:%f}\n", a);
}

EM_PORT_API(void) print_double(double a) {
    printf("C{print_double() a:%lf}\n", a);
}

// 很多编译器支持在C/C++代码直接嵌入汇编代码，
// Emscripten采用类似的方式，提供了一组以“EM_ASM”为前缀的宏，
// 用于以内联的方式在C/C++代码中直接嵌入JavaScript代码
int main() {
    // EM_ASM宏只能执行嵌入的JavaScript代码, 无法传入参数或获取返回结果。
    EM_ASM(console.log('你好，Emscripten！'));

    // EM_ASM_支持输入数值类型的可变参数, 同时返回整数类型的结果
    // EM_ASM_宏嵌入的JavaScript代码必须放到{}包围的代码块中（以区隔代码与参数），且至少必须含有一个输入参数。
    // 嵌入的JavaScript代码通过$n访问第n+1个参数
    int sum = EM_ASM_({return $0 + $1 + $2;}, 1, 2, 3);
    printf("sum(1, 2, 3): %d\n", sum);

    // EM_ASM_/EM_ASM_DOUBLE宏中嵌入的JavaScript代码会被展开为一个独立的JavaScript方法，
    // 因此在嵌入的JavaScript中除了用$n之外，也可以用内置的arguments对象来访问参数
    EM_ASM_(
        {
            console.log("arguments count:", arguments.length);
            for (var i = 0; i < arguments.length; i++) {
                console.log('$', i, ':', arguments[i]);
            }
        },
        42, 13
    );

    // 如果嵌入的JavaScript代码不需要参数，可以使用EM_ASM_INT_V/EM_ASM_DOUBLE_V宏。
    // 由于没有参数，嵌入的代码无需用{}包围
    int answer = EM_ASM_INT_V(return 42);
    printf("The answer is:%d\n", answer);
    double pi_js = EM_ASM_DOUBLE_V(return 3.14159);
    printf("PI:%lf\n", pi_js);
    return 0;
}