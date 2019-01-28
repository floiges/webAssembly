(module
    (table 2 anyfunc) ;; 表格的初始化大小 存储2个引用;anyfunc声明的是这些引用的元素类型是“一个具有任何签名的函数”
    (elem (i32.const 0) $f1 $f2) ;; 元素段 能够将一个模块中的任意函数子集以任意顺序列入其中，并允许出现重复。列入其中的函数将会被表格引用并，且引用顺序是其出现的顺序。(i32.const 0)值是一个偏移量
    (func $f1 (result i32)
        i32.const 42)
    (func $f2 (result i32)
        i32.const 13)
    (type $return_32 (func (result i32)));; if this was f32, type checking would fail 使用一个引用名字定义了一个类型。该类型被用来在后续的表格函数引用调用时进行类型检查
    (func (export "callByIndex") (param $i i32) (result i32)
        ;;get_local $i
        ;;call_indirect $return_32);; 使用call_indirect指令调用表格中的函数——这隐含的意思是$i的值从栈顶出栈。最终的结果就是callByIndex函数会调用表格中的第$i个函数。
        (call_indirect $return_32 (get_local $i))
)