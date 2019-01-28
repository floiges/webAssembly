#include "../em_port_api.h"

EM_PORT_API(int) js_add(int a, int b); // 导出函数签名，由js实现
EM_PORT_API(void) js_console_log_int(int param);

EM_PORT_API(void) print_the_answer() {
    int i = js_add(21, 21);
    js_console_log_int(i);
}