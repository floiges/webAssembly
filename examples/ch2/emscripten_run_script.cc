#include <stdio.h>
#include <emscripten.h>

const char* get_js_code() {
    static char buf[1024];
    sprintf(buf, "console.log('你好，Emscripten！');");
    return buf;
}

int main() {
    // emscripten_run_script系列函数可以接受动态输入的字符串，
    // 该系列辅助函数可以类比于JavaScript中的eval()方法
    emscripten_run_script("console.log(42);");
    emscripten_run_script(get_js_code());

    // 为了避免使用转义符方便阅读，使用了C++11标准的raw字符串定义方法 R前缀
    // 使用emcc命令编译时，必须增加-std=c++11参数
    emscripten_run_script(R"(
        function my_print(s) {
            console.log("JS:my_print():", s);
        }
        my_print("Hello!");
    )");
    return 0;
}