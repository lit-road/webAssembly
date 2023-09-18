/*
 * @Author: zhanghengxin 812718649@qq.com
 * @Date: 2023-09-17 13:37:51
 * @LastEditors: zhanghengxin 812718649@qq.com
 * @LastEditTime: 2023-09-17 13:43:40
 * @FilePath: \webAssembly\benchmark-js.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
(function(){
    let a = 6.2456, b = 2.178;
    const start = performance.now();
    for (let j = 0; j < 10; ++j)
    {
        for (let i = 0; i < 100000000; ++i)
        {
            a = a + b;
        }
    }

    const end = performance.now();
    console.log(`${end - start} ms`)
    return 0;
})()

// total:
// 1346ms
// 1268ms
// 1238ms
// 1511ms
// 1407ms