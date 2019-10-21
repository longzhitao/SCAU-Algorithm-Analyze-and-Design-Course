/*
 9718 整数因子分解（优先做）
时间限制:1000MS  内存限制:1000K
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC;VC
Description
大于1的正整数 n 都可以分解为 n = x1 * x2 * ... * xm， 每个xi为大于1的因子，即1<xi<=n 。

例如：当n=12时，共有8种不同的分解式：
12 = 12
12 = 6*2
12 = 4*3
12 = 3*4
12 = 3*2*2
12 = 2*6
12 = 2*3*2
12 = 2*2*3

对于给定正整数n，计算n共有多少种不同的分解式。
 */
#include <iostream>
using namespace std;

int solve(int n){
    int num = 0;
    if (n == 1)
        return 1;
    for (int i = 2; i <= n; ++i)
        if (n % i == 0)
            num += solve(n / i);
    return num;

}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}