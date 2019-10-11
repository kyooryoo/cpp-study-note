# Sams Teach Yourself C++ in One Hour a Day
http://library.uc.edu.kh/userfiles/pdf/18.SAMS%20Teach%20Yourself%20C++%20in%20One%20Hour%20a%20Day.pdf

## Jump Start

CPP语言诞生于1979年的贝尔实验室。作为C语言的增强版添加了面向对象设计和继承、抽象、多态和封装等特性。CPP类可以包含成员数据和成员方法，编程人员可以方便的建立和使用自定义数据模型及其相关方法。

CPP是一种介于接近底层硬件和高层用户的中间语言，相对更新的编程语言，例如Java和DotNet提供运行中的内存垃圾收集功能，CPP适用于对性能和硬件资源控制有更高要求的应用。

CPP程序依赖编译器执行，为统一不同厂商的编译器规格，自1998年起，国际标准化组织ISO已制定了多个标准，最新的是CPP17。这些新的CPP标准引入了对`auto`声明类型，`Lambda`函数的支持等。

CPP程序无所不在，从操作系统到实用工具，大部分最基本的电脑程序都是由CPP语言编写，涉及编码（.cpp文件），生成目标文件（.o或.obj文件）和链接外部依赖项生成可执行文件，三个步骤。

实际上，编程过程难免遇到错误，可以说排错和调试的过程本身就是编程。集成开发环境（IDE）就是为编写、编译和调试提供方便的编程工具。注意：
* 保存编码文件为`.cpp`扩展名，不要用`.c`扩展名，因为某些编译器会将后者编译为C程序而非CPP程序。
* 使用简单文本编辑工具或集成开发环境编写代码，不要用带格式的文本编辑工具以免引入格式编码影响程序运行。

第一个程序总是所谓的`Hello World!`，就是把这个消息打印到屏幕上，编码文件`1_1.cpp`内容如下：
```
#include <iostream>
int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

对于以上程序，这里不做解释，编译和执行过程如下：
```
$ g++ -o 1_1 1_1.cpp -std=c++17
$ ./1_1
Hello World!
```

补充一些概念：
* 编译器编译整个程序代码，生成目标机器代码或中间代码。翻译器逐行翻译程序代码到中间代码或机器代码。在执行效率上翻译器没有编译器高。
* CPP还会使用到连接器，在生成可执行文件时将依赖的外部模块的代码打包到程序文件中，在连接器工作之前，目标文件只包含程序自身的代码。
* 再次回顾一般开发流程，即编写源代码、编译代码生成目标文件、链接目标文件和外部依赖文件生成可执行文件，其间不可避免的调试并排错。

## Break Down

回头来仔细看看之前创建的CPP程序：
```
#include <iostream>
int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

说明如下：
* #include <iostream>
预处理语句，指示系统加载外部模块以支持程序中调用的函数和方法。这里加载的输入输出流模块为输出文字的功能提供了支持。没有改预处理语句，`std::cout`功能就无法实现。括号`<>`用于标注标准模块或者头文件，自定义的头文件带相对路径地址`dir\file`用双引号`””`来标注。
* int main() {}
预处理语句后面是定义的函数和主程序体。这里没有自定义任何函数，所以直接进入主程序体部分。主程序体用`main`标识，参数部分`()`标识不带参数，返回值类型用`int`表示，注意这里定义的返回类型必须与主程序中最后返回的值类型一致。主程序体包括在`{}`之间或者说之中。
* std::cout << "Hello World!" << std::endl;
    * `cout`是`console-out`控制台输出的缩写，属于`std`命名空间。
    * `<<`表示添加对象到输入输出流
    * `endl`表示结束一行，同样属于`std`命名空间
    * `return 0`返回定义的整数，默认用`0`表示正常结束，`-1`表示异常结束。
    * 注意CPP程序区分大小写。

命名空间可以避免不同源的同名方法可能发生的冲突，如果确认只在程序中使用特定命名空间，可以在程序头部声明对命名空间的定义，以后再用相关方法就不必带命名空间名称了：
```
#include <iostream>
using namespace std;
int main() {
    cout << "Hello World!" << endl;
    return 0;
}
```

编译和运行验证如下：
```
$ g++ -o 2_1 2_1.cpp
$ ./2_1
Hello World!
```

更为严谨的声明方式是在使用相关方法的程序体内部逐个声明每个方法。在程序头部引用整个命名空间简洁，逐个声明使用方法所属的命名空间更精准：
```
#include <iostream>
/* 
a comment spans mutiple lines
*/
int main() {
    // inline comment
    using std::cout;
    using std::endl;
    cout << "Hello World!" << endl;
    return 0;
}
```

以上程序还使用了注释，作为程序内的文档，用来解释程序或其中的方法等。注意：
* 对于复杂的程序或算法，添加必要的注释有利于对程序源代码的解读。
* 注释的读者是所有可能看到代码的人，应该对代码作者以外的他人易于理解。
* 不重复解释明显的内容，不用注释合理化不明确的代码，代码更新后也更新注释。

定义函数可以将代码分配到更小单位，方便开发和排错：
```
#include <iostream>
using namespace std;

// declare a function
void DemoConsoleOutput();

int main() {
    // call the function
    DemoConsoleOutput();
    return 0;
}

// define the function
void DemoConsoleOutput() {
    cout << "This is a simple string literal" << endl;
    cout << "Pi is close to: " << 22 / 7 << endl;
    cout << "Pi is more close to: " << 22.0 / 7 << endl;
}
```

函数遵循先声明后使用的原则，声明后的函数可以在主函数后定义具体内容。如果函数本身不返回值，可以在函数定义中使用`void`标识符。

当然也可以在主函数调用子函数前直接定义子函数，这样就免去了声明的步骤。子函数的返回值也可以直接作为主函数的返回值。如此，以上程序代码可以进一步简化如下：
```
#include <iostream>
using namespace std;

int DemoConsoleOutput() {
    cout << "This is a simple string literal" << endl;
    cout << "Pi is close to: " << 22 / 7 << endl;
    cout << "Pi is more close to: " << 22.0 / 7 << endl;
    return 0;
}

int main() {
    return DemoConsoleOutput();
}
```

程序的基本输入和输出分别来自键盘和指向控制台，使用`cout`和`cin`配合`<<`与`>>`实现：
```
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age;
    string name;

    cout << "your name: ";
    cin >> name;
    cout << "your age:" ;
    cin >> age; 
    cout << name << " is " << age << " years old." << endl;
    return 0;
}
```

回顾一下：
* `#include`作为预处理命令，在程序头部插入必要的依赖模块或文件。
* `//`和`/* */`分别用于单行和多行注释，标注程序内的说明文档。
* CPP代码对大小写敏感，也就是说`int`和`Int`是不同的，后者不合法。
* CPP对空格和换行符不敏感，过长的命令可以在语义间断处做换行处理。

## Variables and Constants

这部分介绍变量和常量，分别用来在程序中保存可变更的数据或不可变更的数据。

### 变量

编译器负责：
* 将用户友好的变量名映射到内存地址，
* 根据指定的变量类型分配适当的内存空间，
* 在变量初始化或赋值后保存或更新值到相应的内存地址，
* 在程序调用变量时从相应内存地址提取保存的变量值

使用变量时注意以下原则：
* 注意变量保存到的是内存地址（RAM随机访问内存）
* 变量名不可以数字开头或包含空格或关键字（如return）
* 过长的变量名，虽然不建议使用，可以用`_`做语义分隔符
* 定义在函数内的变量仅在函数体内有效，叫做局部变量
* 定义在函数外的变量可以跨函数有效，叫做全局变量
* 避免过多使用全局变量，用子函数返回值传递信息

如下程序定义了变量用于储存参与计算的值和结果：
```
#include <iostream>
using namespace std;

int main() {
    cout << "multiply two numbers" << endl;
    cout << "first number: ";
    int firstnum = 0;
    cin >> firstnum;
    cout << "second number: ";
    int secondnum = 0;
    cin >> secondnum;
    int res = firstnum * secondnum;
    cout << firstnum << " * " << secondnum;
    cout << " = " << res << endl;
    return 0;
}
```

但以上程序可以进行如下优化：
* 提前声明和初始化所有变量，简化代码并增加可读性。
* 将计算功能独立为子函数，通过返回值传递结果。
* 变量名使用驼峰规则，即第一个首字符小写，其后大写。
* 函数名称使用帕斯卡规则，及所有首字符都大写。
* 变量和函数名应对代码读者友好，避免含义不清或歧义。

优化后的程序如下：
```
#include <iostream>
using namespace std;

int MultiplyNumbers() {
    int firstNum = 0, secondNum = 0;
    cout << "multiply two numbers" << endl;
    cout << "first number: ";
    cin >> firstNum;
    cout << "second number: ";
    cin >> secondNum;
    return firstNum * secondNum;
}

void DisplayResult(int res) {
    cout << "the result is: " << res << endl;
}

int main() {
    int res = 0;
    res = MultiplyNumbers();
    DisplayResult(res);
    return 0;
}
```

变量可以有如下类型：
* 变量在内存中以字节为单位保存。
* 每字节包含8比特，每比特位可取值0或1。
* 少了符号比特位（MSB最重要比特），无符整形容量更大。
* 无符整型只能保存正整数，不可用于可能取负值的变量。
* 注意各种数据类型的容量边界，防止发生溢出错误。
* C++14标准添加对位数标识符`’`的支持。

主要的数据类型如下：
* 布尔型`bool`保存逻辑值`false`或`true`。
* 字符型`char`保存单字符，即ASCII中的对象。
* 一般整型`short`，`int`，`long`，`long long`。
* 无符整型即`unsigned`加以上一般整型类别。
* 浮点型，即小数型`float`和`double`。

演示溢出错误的后果：
```
#include <iostream>
using namespace std;

int main() {
    unsigned short uShort = 65’535;
    cout << "Incrementing unsigned short " << uShort << " gives: ";
    cout << ++uShort << endl;

    short sShort = 32'767;
    cout << "Incrementing signed short " << sShort << " gives: ";
    cout << ++sShort << endl;

    return 0;
}
```

运行结果：
```
$ g++ -o 3_3 3_3.cpp 
$ ./3_3
Incrementing unsigned short 65535 gives: 0
Incrementing signed short 32767 gives: -32768
```

演示不同数据类型在内存中占用的字节数：
```
#include <iostream>
using namespace std;

int main() {
    cout << "Computing the size of some C++ inbuilt variable types" << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
    cout << "Size of unsigned short int: " << sizeof(unsigned short) << endl;
    cout << "Size of short int: " << sizeof(short) << endl;
    cout << "Size of unsigned long int: " << sizeof(unsigned long) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of unsigned long long: "<< sizeof(unsigned long long) << endl;
    cout << "Size of long long: " << sizeof(long long) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "The output changes with compiler, hardware and OS" << endl;
    return 0;
}
```

运行结果：
```
$ g++ -o 3_4 3_4.cpp
$ ./3_4
Computing the size of some C++ inbuilt variable types
Size of bool: 1
Size of char: 1
Size of int: 4
Size of unsigned int: 4
Size of unsigned short int: 2
Size of short int: 2
Size of unsigned long int: 8
Size of long: 8
Size of unsigned long long: 8
Size of long long: 8
Size of float: 4
Size of double: 8
The output changes with compiler, hardware and OS
```

从C++11开始，支持定义直接指定比特位的整数：
```
#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    cout << "Computing the size of C++11 fixed-width integer types:" << endl;

    cout << "Size of int8_t: " << sizeof(int8_t) << endl;
    cout << "Size of uint8_t: " << sizeof(uint8_t) << endl;
    cout << "Size of int16_t: " << sizeof(int16_t) << endl;
    cout << "Size of uint16_t: " << sizeof(uint16_t) << endl;
    cout << "Size of int32_t: " << sizeof(int32_t) << endl;
    cout << "Size of uint32_t: " << sizeof(uint32_t) << endl;
    cout << "Size of int64_t: " << sizeof(int64_t) << endl;
    cout << "Size of uint64_t: " << sizeof(uint64_t) << endl;
    return 0;
}
```

运行结果：
```
$ g++ -o 3_5 3_5.cpp
$ ./3_5
Computing the size of C++11 fixed-width integer types:
Size of int8_t: 1
Size of uint8_t: 1
Size of int16_t: 2
Size of uint16_t: 2
Size of int32_t: 4
Size of uint32_t: 4
Size of int64_t: 8
Size of uint64_t: 8
```

将值域更大的变量赋值到值域更小的变量，会有丢失数据的风险。C++编译器对此类风险默认只提供警告，不做处理。C++11引入了使用括号的初始化方法，在编译阶段就可以对此类风险报错。
```
int largeNum = 5000000; short anotherNum{ largeNum }; // error! Amend types int anotherNum{ largeNum }; // OK! float someFloat{ largeNum }; // error! An int may be narrowed 
float someFloat{ 5000000 }; // OK! 5000000 can be accommodated 
```

选择合适的数据类型可能是个挑战，C++11引入了让编译器自动选择数据类型的`auto`类别标识符：
```
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    auto coinFlippedHeads = true;
    auto largeNumber = 2500000000000;

    cout << "coinFlippedHeads: value: " << coinFlippedHeads;
    cout << ", type: " << typeid(coinFlippedHeads).name();
    cout << ", size: " << sizeof(coinFlippedHeads) << endl;

    cout << “largeNumber: value: " << largeNumber;
    cout << ", type: " << typeid(largeNumber).name();
    cout << ", size: " << sizeof(largeNumber) << endl;

    return 0;
}
```

运行结果如下：
```
$ ./3_6
coinFlippedHeads: value: 1, type: b, size: 1
coinFlippedHeads: value: 2500000000000, type: l, size: 8
```

需要注意的是，声明为`auto`的变量需要在声明同时初始化，否则编译器无法根据初始化的值选择合适的数据类类型，会报编译错误。

使用`typedef`可以自定义方便的类型名称，在使用模板的复杂类型上尤其适用，这里先不涉及模板，给出一个示例：

```
    typedef unsigned int STRICTLY_POSITIVE_INTEGER;
    STRICTLY_POSITIVE_INTEGER numEggInBusket = 4'321;

    cout << "numEggInBusket: value: " << numEggInBusket;
    cout << ", type: " << typeid(numEggInBusket).name();
    cout << ", size: " << sizeof(numEggInBusket) << endl;
```

### 常量

常量与变量遵循同样的命名规则，一样使用内存空间和数据类型。在一般变量初始化和程序过程中使用的值，实际上都是常量，只是常量不可以修改。如以下字符串和各种进制下的数字：
```
#include <iostream>
using namespace std;

int main() {
    cout << "THis is a constant as well." << endl;

    int decNum = 10;
    int octNum = 012;
    int binNum = 0b1010;

    cout << "Decimal 10: " << decNum << endl;
    cout << "Octal 012: " << octNum << endl;
    cout << "Binary 1010: " << binNum << endl;

    return 0;
}
```

运行结果如下：
```
$ g++ -o 3_7 3_7.cpp -std=c++17
~/Workspace/CPP/OneHourPerDay $ ./3_7
THis is a constant as well.
Decimal 10: 10
Octal 012: 10
Binary 1010: 10
```

但是以上都是直接使用了常量，为了使用常量需要先定义常量，使用`const`标记在数据类型之前，或用`constexpr`标记在函数之前：

```
#include <iostream>
using namespace std;
constexpr double GetPi() { return 22.0/7; }
constexpr double TwicePi() { return 2 * GetPi();}

int main() {
    const double pi = 22.0 / 7;
    cout << "constant pi contains value " << pi << endl;
    cout << "constexpr GetPi() returns value " << GetPi() << endl;
    cout << "constexpr TwicePi() returns value " << TwicePi() << endl;

    return 0;
}
```

虽然已经不再建议使用，声明常量可以用`#define`。这种方法对于编译器来说只是做文字上的转换，没有触发关于数据类型等其他方面智能处理，因此已经再不建议使用，请不要使用如下方式声明常量：
```
#define pi 3.14286
```

常量的一个常用应用是枚举，也就是只允许变量从指定的一系列值中取值，其中的每个值叫做一个枚举值。编译器会将枚举值转换为唯一的整数值，默认从`0`开始，也接受用户自定义该唯一整数值。
```
#include <iostream>
using namespace std;

enum CardinalDirections {
    North = 25,
    South,
    East,
    West
};

int main() {
    cout << "Displaying directions and their symbolic values" << endl;
    cout << "North: " << North << endl;
    cout << "South: " << South << endl;
    cout << "East:" << East << endl;
    cout << "West: " << West << endl;
    CardinalDirections windDirection = South;
    cout << "Variable withDirection = " << windDirection << endl;
    
    return 0;
}
```

运行结果：
```
$ g++ -o 3_7 3_7.cpp -std=c++17
$ ./3_7
Displaying directions and their symbolic values
North: 25
South: 26
East:27
West: 28
Variable withDirection = 26
```

以上程序的运行结果可以看到，系统根据用户自定义初始化的第一个枚举值`25`，自动为其他枚举值赋值为`26`、`27`和`28`。

最后关于变量和常量的命名，注意如下：
* 系统保留的关键词不可以用作变量或常量名。
* 不必记忆系统关键词，IDE或编译器会指出他们。
* 命名需要有描述性，符合团队的统一命名规则。
* 用`{}`初始化，可以防止数据容量边界溢出问题。
* 不使用过短或甚至只有一个字母的变量或常量名。
* 不使用意义不广为人知的名字做变量或常量名。

补充本节重点如下：
* 常量保存不许变更或防止意外变更的值，如圆周率等。
* 最好在声明常量的同时初始化，防止出现垃圾值。
* 为节省计算资源和提高效率，选择适当长度的数据类型。
* 慎用全局变量，因为大程序很难保证变量名全局唯一。
* 注意数据容量边界和跨越边界引发的溢出问题，