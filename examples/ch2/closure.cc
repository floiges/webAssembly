#include <stdio.h>
#include "../em_port_api.h"

EM_PORT_API(int) show_me_the_answer();

EM_PORT_API(void) func() {
    printf("%d\n", show_me_the_answer());
}