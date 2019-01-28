mergeInto(LibraryManager.library, {
    // LibraryManager.library可以简单的理解为JavaScript注入C环境的库
    // 实现C导出的方法，注入到C环境中
    js_add: function(a, b) {
        console.log("js_add");
        return a + b;
    },
    js_console_log_int: function(param) {
        console.log("js_console_log_int:" + param);
    }
});