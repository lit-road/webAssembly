import java.util.Date;

class Benchmark {
    public static void main(String[] args) {
        double a = 6.2456, b = 2.178;
        long start = new Date().getTime();
        for (int j = 0; j < 10; ++j)
        {
            for (int i = 0; i < 100000000; ++i)
            {
                a = a + b;
            }
        }
        long end = new Date().getTime();
        System.out.printf("%d ms\n", end - start);
    }
}
// class main {
//     public static void main(String[] args) {
//         Benchmark.main(args);
//     }
// }
// compile: 
// javac benchmark-java.java
// run:
// java Benchmark

// total:
// 128 ms
// 132 ms