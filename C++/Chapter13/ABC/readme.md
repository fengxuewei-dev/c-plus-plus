程序编译的流程：
g++ -fPIC -shared acctABC.cpp -o libacctAbc.so 生成动态链接库

查看引用关系：
fengxuewei@fengxuewei-Legion-Y7000-2019-PG0:~/C++/Chapter13/ABC$ ldd libacctAbc.so 
        linux-vdso.so.1 (0x00007ffc59da5000)
        libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f5fdc307000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f5fdc0ef000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f5fdbcfe000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f5fdb960000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f5fdc895000)

编译主文件：
g++ usebrass3.cpp -o main -L ./ -lacctAbc

执行出现了下面的错误，这是因为在 链接的时候，是默认从 /usr/lib/ 下寻找，而该库文件不在 该目录下，所以会报错
fengxuewei@fengxuewei-Legion-Y7000-2019-PG0:~/C++/Chapter13/ABC$ ./main 
./main: error while loading shared libraries: libacctAbc.so: cannot open shared object file: No such file or directory

使用下面的语句来生成 main 可执行文件， 当找不到动态链接的时候，带当前目录下进行寻找
g++ usebrass3.cpp -o main -L ./ -lacctAbc -Wl,-rpath ./

fengxuewei@fengxuewei-Legion-Y7000-2019-PG0:~/C++/Chapter13/ABC$ ldd main         linux-vdso.so.1 (0x00007ffdb7536000)
        libacctAbc.so => ./libacctAbc.so (0x00007f532e4cd000)
        libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f532e144000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f532df2c000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f532db3b000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f532d79d000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f532e8d5000)

这个时候执行 ./main 可以执行通过