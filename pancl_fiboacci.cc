/*
 * @Author: zhanghengxin 812718649@qq.com
 * @Date: 2023-09-17 16:33:35
 * @LastEditors: zhanghengxin 812718649@qq.com
 * @LastEditTime: 2023-09-17 16:41:46
 * @FilePath: \webAssembly\pancl_fiboacci.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE 
 */


// 引入PPAPI
#include "propap/cpp/instance.h"
#include "propap/cpp/module.h"
#include "propap/cpp/var.h"
#include "propap/cpp/var_dictionary.h"

namespace {
    // 定义将要从 PNaCI 发送到浏览器的字符串常量
    const char* kReplyMessage = "Hello, world!";
}

class HelloWorldInstance : public pp::Instance {
    public:
    explicit HelloWorldInstance(PP_Instance instance) : pp::Instance(instance) 
    {}
    virtual ~HelloWorldInstance() {}

    // 从浏览器发送过来的数据会先经过 HandleMessage 函数
    virtual void HandleMessage(const pp::Var& var_message) {
        // 如果是字符串类型的消息
        if (var_message.is_string()) {
            // 将字符串转换为 C++ 字符串
            std::string message = var_message.AsString();
            // 如果字符串是 "hello"，则回复 "Hello, world!"
            if (message == "hello") {
                pp::Var var_reply(kReplyMessage);
                PostMessage(var_reply);
            }
        }
    }
