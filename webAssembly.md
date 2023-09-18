<!--
 * @Author: zhanghengxin 812718649@qq.com
 * @Date: 2023-09-17 14:01:16
 * @LastEditors: zhanghengxin 812718649@qq.com
 * @LastEditTime: 2023-09-17 16:33:11
 * @FilePath: \webAssembly\webAssembly.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->

# webAssembly

> web端正在扩充各种能力。
> 视频应用、大型3D游戏、在线的机器学习等，需要大量的计算资源。
> js的引擎解析执行效率决定这些应用的流畅。

```code
Non Zero Digit -> Update Expression -> Unary Expression -> Exponentiation Expression -> Multiplicative Expression -> Additive Expression

非零位数->更新表达式->一元表达式->指数表达式->乘法表达式->加法表达式
```

## V8 是怎么跑起来的 - V8 的 JavaScript 执行管道 2021 https://zhuanlan.zhihu.com/p/424240889

老版本v8 （chrome 58 以下版本）
compiler Pipeline （编译器管道结构图）

pre-Parsing
full-Parsing
    Top-Level
    NotTop-Level

新版V8 新增了ignition

### 性能优化的其他尝试

1、减少编译过程中的类型判断 ASM.js （2013年生-2014年终）

ASM是一个 js 子集，
使用'use asm' 启用asm 语法。

涉及到的工具链：
Emscripten： 将静态语言转为ASM
    part1.源代码生成LLVM中间代码的 Emscripten Compiler Frontend。
    part2.将LLVM编译成目标语言的Fastcomp

```bash
sudo emcc -o3 -s ASM_JS=1 -std=c++11 bubble._sort.cc
```

```node
node  -trance_asm_parser -validate_asm a.out.js
```

ASM 局限性：
只定义了数值类型的声明方式。

2、想将原生的C应用运行在浏览器端 —— NaCI（2011年）

NaCI 受限于架构，推荐使用PaCI
    区别 —— :
    1.PaCI 使用LLVM 生成.pexe 文件，他不依赖具体的cpu架构。
    2.NaCI 支持动态链接。

