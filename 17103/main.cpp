//
//
//17103 基站建设（优先做）
//时间限制:1000MS  内存限制:65535K
//提交次数:0 通过次数:0
//
//题型: 编程题   语言: G++;GCC;VC
//        Description
//一条很长的乡村公路（我们可以想象这条公路是一条长线段，有一个西端点和一个东端点），公路旁稀疏的分布着一些房子。
//我们把公路的西端点固定在坐标0上，东端点为某远处。
//假设这些房子的居民都使用蜂窝移动电话，现在需要把移动电话基站放在这条路旁的某些点上，使得每个房子都在其中一个
//        基站4公里之内。
//
//注意：房子和基站都建立在公路旁而不远离公路，即可以认为房子和基站都是公路直线上的点。
//
//给出一个有效算法，使得用尽可能少的基站来实现这个目标。
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    int count = 1;
    sort(input, input + n);

    int pos = input[0] + 4;
    for (int i = 0; i < n; ++i) {
        if (pos + 4 < input[i]){
            count++;
            pos = input[i] + 4;
        }
    }

    cout << count;
    return 0;
}