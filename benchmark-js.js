/*
 * @Author: zhanghengxin ezreal.zhang@icewhale.org
 * @Date: 2023-09-19 09:56:18
 * @LastEditTime: 2023-09-19 10:17:52
 * @LastEditors: zhanghengxin ezreal.zhang@icewhale.org
 * @FilePath: /webAssembly/benchmark-js.js
 * @Description: Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
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
})();

// total:
// 1346ms
// 1268ms
// 1238ms
// 1511ms
// 1407ms