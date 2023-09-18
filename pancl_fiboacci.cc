/*
 * @Author: zhanghengxin 812718649@qq.com
 * @Date: 2023-09-17 16:33:35
 * @LastEditors: zhanghengxin 812718649@qq.com
 * @LastEditTime: 2023-09-19 01:17:36
 * @FilePath: \webAssembly\pancl_fiboacci.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 引入PPAPI
#include "propap/cpp/instance.h"
#include "propap/cpp/module.h"
#include "propap/cpp/var.h"
#include "propap/cpp/var_dictionary.h"

namespace
{
    // 定义将要从 PNaCI 发送到浏览器的字符串常量
    const char *kReplyMessage = "Hello, world!";
}

class HelloWorldInstance : public pp::Instance
{
public:
    explicit HelloWorldInstance(PP_Instance instance) : pp::Instance(instance)
    {
    }
    virtual ~HelloWorldInstance() {}

    // 从浏览器发送过来的数据会先经过 HandleMessage 函数
    virtual void HandleMessage(const pp::Var &var_message)
    {
        // 处理从浏览器端发送过来的数据
        if (!var_message.is_number())
            return;
        // 通过 Pepper API 处理从 Javascript 发送过来的数据
        int message = var_message.AsInt();
        pp::VarDictionary var_message;
        // 构造一个字典对象
        var_dict.Set(pp::Var("echo"), pp::Var(kReplyString));
        var_dict.Set(pp::Var("result"), pp::Var(this->fib(message)));
        // 通过 PostMessage 方法将数据发送回浏览器
        PostMessage(var_dict);
    }

private:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }

    // 浏览器会检查 HTML 页面中所有用于声明PN啊CI应用的 <embed> 标签
    // 每一个有效的标签都会生成一个与之对应的pp::Module 对象
    class HelloWorldModule : public pp::Module
    {
    public:
        HelloWorldModule() : pp::Module() {}
        virtual ~HelloWorldModule() {}

        // 创建一个 HelloWorldInstance 实例
        virtual pp::Instance *CreateInstance(PP_Instance instance)
        {
            return new HelloWorldInstance(instance);
        }
    };

    namespace pp
    {
        // 实现一个工厂函数，用于创建 HelloWorldModule 对象
        Module *CreateModule()
        {
            return new HelloWorldModule();
        }
    } // namespace pp

    // 完整的PNaCI 由三部分组成
    // 1、CreateModule
    // 2、<embed>
    // 3、实例类