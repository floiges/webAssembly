mergeInto(LibraryManager.library, {
    show_me_the_answer: function() {
        // 返回闭包函数，由 js 实现
        return jsShowMeTheAnswer();
    }
});