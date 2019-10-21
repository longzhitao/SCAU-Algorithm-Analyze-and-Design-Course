//10304 平面域着色
//        时间限制:1000MS  内存限制:1000K
//提交次数:188 通过次数:53
//
//题型: 编程题   语言: G++;GCC;VC
//        Description
//平面上有一点P，它是n个域D1、D2、……，Dn的共同交点，
//现取k种颜色对这n个域进行着色，要求相邻两个域着的颜色不同，求着色方案数。
//这里，2<=n<=10，1<=k<=9。
#include <iostream>
using namespace std;
int k;
int res(int n){
    if (n == 1)
        return k;
    else if(n == 2)
        return k * (k - 1);
    else if(n == 3)
        return k * (k - 1) * (k - 2);
    else
        return (k - 2) * res(n - 1) + (k - 1) * res(n - 2);
}

int main() {
    int n;
    int ans;
    cin >> n >> k;
    if (n >= 4) {
        if (n & 1 && k < 3)
            ans = 0;
        else if(k < 2)
            ans = 0;
        else
            ans = res(n);
    }
    else{
        if (n == 1)
            ans = k;
        if (n == 2)
            ans = k * (k - 1);
        if (n == 3)
            ans = k * (k - 1) * (k - 2);
    }

    if (ans < 0)
        cout << 0;
    else
        cout << ans;

    return 0;
}