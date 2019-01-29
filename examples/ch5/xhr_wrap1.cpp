// XMLHttpRequest对象的C封装
#include <stdio.h>
#include "../em_port_api.h"

//imp by JavaScript, call by C
EM_PORT_API(void) XHRGet(const char *url);

// imp by C, call by javascript
EM_PORT_API(void) XHROnMessage(const char *url, const char *data) {
    printf("http request succeeded. URL: %s  contex: %s\n", url, data);
}

EM_PORT_API(void) XHROnError(const char *url, const int error_code) {
    printf("http request failed. URL: %s  error code:%d\n", url, error_code);
}

int main() {
    XHRGet("./t1.txt");
    XHRGet("./t2.txt");
    XHRGet("./t3.txt");
    return 0;
}