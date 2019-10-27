//11074 平面分割
//        时间限制:1000MS  内存限制:65535K
//提交次数:0 通过次数:0
//
//题型: 编程题   语言: G++;GCC;VC

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ln, cn, zn, zzn;
    if (n != 0){
        ln = 1.0/2.0 * n * (n + 1) + 1;
        cn = n * n - n + 2;
        zn = 2 * n * n - n + 1;
        zzn = 4.5 * n * n - 3.5 * n + 1;
    } else
        ln = cn = zn = zzn = 0;
    cout << ln << " " << cn << " " << zn << " " << zzn;
    return 0;
}