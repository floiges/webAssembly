#include "../em_port_api.h"

EM_PORT_API(void) js_print_fib(int *ptr, int count);

EM_PORT_API(void) fibonacci20() {
    static const int count = 20;
    int re[count];

    re[0] = 1;
    int i0 = 0, i1 = 1;
    for (int i = 1; i < count; i++) {
        re[i] = i0 + i1;
        i0 = i1;
        i1 = re[i];
    }
    js_print_fib(re, count);
}