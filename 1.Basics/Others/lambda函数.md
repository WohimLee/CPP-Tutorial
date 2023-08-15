
&emsp;
# 5 匿名函数
匿名函数（英文名：lambda）就是没有名字的函数。最简单的匿名函数是`[](){}`，它没有参数也没有返回值
- `[]`里面用来捕获函数外部的变量
- `()`里面就是匿名函数的参数
- `{}`里面就是函数的执行代码

捕获列表描述了lambda表达式可以访问上下文中的哪些变量
- `[]`: 表示不捕获任何变量
- `[=]`: 表示按值捕获变量
- `[&]`: 表示按引用捕获变量
- `[this]`: 值传递捕获当前的 this
- 可以连用如:`[=,&a,&b]`表示以引用传递的方式捕捉变量a和b，以值传递方式捕捉其它所有变量
- 注意:捕捉列表不允许变量重复传递比如[&,&a]

>示例
```c++
template<typename _T>
shared_ptr<_T> make_nvshared(_T* ptr){
    return shared_ptr<_T>(ptr, [](_T* p){p->destroy();})
}
```

>示例
```c++
// 计算 iou 的 lambda 函数
  auto iou = [](const Box& a, const Box& b){
      float cross_left   = std::max(a.left, b.left);
      float cross_top    = std::max(a.top, b.top);
      float cross_right  = std::min(a.right, b.right);
      float cross_bottom = std::min(a.bottom, b.bottom);

      float cross_area = std::max(0.0f, cross_right - cross_left)*std::max(0.0f, cross_bottom-cross_top);
      float union_area = std::max(0.0f, a.right-a.left)*std::max(0.0f, a.bottom-a.top) +
                          std::max(0.0f, b.right-b.left)*std::max(0.0f, b.bottom-b.top) -
                          cross_area;
      if(cross_area == 0 || union_area == 0) return 0.0f;
      return cross_area / union_area;
  }
```
