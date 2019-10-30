//
//11085 买票找零
//时间限制:800MS  内存限制:65535K
//提交次数:0 通过次数:0
//
//题型: 编程题   语言: G++;GCC;VC
//Description
//一场激烈足球赛即将开始，售票员紧张地卖票着……。
//每张球票50元，现在有2n（1<=n<=18）个球迷排队购票，其中n个手持50元钞票，另外n个手持100元钞票。
//假设开始售票时售票处没有零钱可以找零。
//问这2n个人有多少种排队方式，不至使售票处出现找不出零的局面？
//
//例如当n=3时，共6人，3人持50元，3人持100元。可以找零的排队方式有如下5种：
//50	50	50	100	100	100
//50	50	100	100	50	100
//50	50	100	50	100	100
//50	100	50	50	100	100
//50	100	50	100	50	100
long long temp[20];
#include <iostream>
long long res(int n){//2n
    long long sum = 0;

    if (temp[n] != 0)
        return temp[n];
    if (n == 0)
    {
        temp[n] = 1;
        return 1;
    }
    else{
        for (int i = 1; i <= n / 2; ++i) {
            sum = sum + res(2 * i - 2) * res(n - 2 * i);
        }
        temp[n] = sum;
        return sum;
    }
}
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << res(2*n);
    return 0;
}