#include <stdio.h>
#include <ctime>

int main()
{
    double a = 6.2456, b = 2.178;
    clock_t start = clock();
    for (int j = 0; j < 10; ++j)
    {
        for (int i = 0; i < 100000000; ++i)
        {
            a = a + b;
        }
    }

    clock_t end = clock();
    printf("Time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

// Compile:
// g++ .\benchmark-cpp.cc -o .\benchmark-cpp
// 优化编译
// g++ -O3 -ffast-math .\benchmark-cpp.cc -o .\benchmark-cpp-1
// Run:
// .\benchmark-cpp.exe


// totle:
// 3.546000 \ 0.000000 s
