# 编译器未定义行为

## GCC 编译选项

- -fsanitize=undefined：可启用快速的未定义行为检测器 UBSAN。为了在运行时检测未定义的行为，需要对各种计算进行监控。当前子选项包含：
- -fsanitize=shift：此选项启用检查移位操作的结果是否未定义。请注意，在 C 和 C++ 之间以及 ISO C90 和 C99 等之间，确切认为未定义的内容略有不同。此选项有两个子选项：- -fsanitize=shift-base 和 -fsanitize=shift-exponent。
- -fsanitize=shift-exponent：此选项启动检查移位操作的第二个参数是否为负数并且小于提升后的第一个参数的精度。
- -fsanitize=shift-base：如果移位运算的第二个参数在范围内，检查移位运算的结果是否未定义。请注意，在 C 和 C++ 以及 ISO C90 和 C99 等之间对于未定义的不同之处。
- -fsanitize=integer-divide-by-zero：检测整数除以零以及 "INT_MIN / -1" 的除法。
- -fsanitize=unreachable：使用此选项，编译器将 "__builtin_unreachable" 调用转换为诊断消息调用。发生 "__builtin_unreachable" 调用时，则行为未定义。
- -fsanitize=vla-bound：此选项指示编译器检查可变长度数组的大小是否为正。
- -fsanitize=null：此选项启用指针检查。特别是，打开此选项构建的应用程序在尝试取消引用 NULL 指针，或者如果引用（可能是右值引用）绑定到 NULL 指针，或者调用 NULL 指针指向的- 对象上的方法时会发出错误消息。
- -fsanitize=return：此选项启用返回语句检查。打开此选项构建的程序将在到达返回值为非 void 的函数的末尾而没有实际返回值时发出错误消息。此选项仅适用于 C++。
- -fsanitize=signed-integer-overflow：此选项启用有符号整数溢出检查。检查 "+"、"*" 以及一元和二进制 "-" 的结果在有符号算术中是否溢出。注意，必须考虑整数提升规则。也就- 是说，以下不是溢出：
- signed char a = SCHAR_MAX;
- a++;
- -fsanitize=bounds：此选项启用对数组边界的检测。检测各种越界访问。不检测灵活的数组成员、类似灵活的数组成员的数组和具有静态存储的变量的初始化器。该选项不能与 - -fcheck-pointer-bounds 结合使用。
- -fsanitize=bounds-strict：此选项启用对数组边界的严格检测。检测大多数越界访问，包括灵活数组成员和类似数组成员的数组。不检测具有静态存储的变量的初始化器。该选项不能与 - -fcheck-pointer-bounds 结合使用。
- -fsanitize=alignment：当指针被取消引用时，或者当引用绑定到未充分对齐的目标时，或者在未充分对齐的对象上调用方法或构造函数时，此选项启用检查指针的对齐方式。
- -fsanitize=object-size：此选项启用使用 "__builtin_object_size" 函数检测内存引用。检测各种越界指针访问。
- -fsanitize=float-divide-by-zero：检测浮点除以零。 与其他类似选项不同，-fsanitize=float-divide-by-zero 不是由 -fsanitize=undefined 启用的，因为浮点除以零可- 能是获得无穷大和 NaN 的合法方式。
- -fsanitize=float-cast-overflow：此选项启用浮点类型到整数的转换检查。我们检查转换的结果是否溢出。与其他类似选项不同，-fsanitize=float-cast-overflow 不是由 - -fsanitize=undefined 启用的。此选项不适用于启用 "FE_INVALID" 异常。
- -fsanitize=nonnull-attribute：此选项启用函数调用检查，检查被函数属性 "nonnull" 标记为需要非空值的参数是否被传入了空值。
- -fsanitize=returns-nonnull-attribute：此选项启用在标有“returns_nonnull”函数属性的函数中检测返回语句，以检测从此类函数返回的空值。
- -fsanitize=bool：此选项启用对来自 bool 的负载的检测。如果加载了 0/1 以外的值，则会发出运行时错误。
- -fsanitize=enum：此选项启用对来自枚举类型的负载的检测。如果加载了超出枚举类型值范围的值，则会发出运行时错误。
- -fsanitize=vptr：此选项启用对 C++ 成员函数调用、成员访问以及指向基类和派生类的指针之间的某些转换的检测，以验证引用的对象具有正确的动态类型。
虽然 -ftrapv 会导致发出签名溢出的陷阱，但 -fsanitize=undefined 会给出诊断消息。 这目前仅适用于 C 系列语言。

参考地址：<https://zhuanlan.zhihu.com/p/516100729>
