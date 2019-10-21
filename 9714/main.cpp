//9714 圣诞礼物
//Description
//圣诞节到了，圣诞老人给 N 个小朋友准备了 M 个礼物。每个小朋友有一个袜子（袜子不编号，无区别，
//认为袜子都相同），
//圣诞老人将 M 个礼物装到 N 个袜子中的放法有多少种？
//
//注意：
//
//1）若M=7 N=3，那么5,1,1的放法和1,5,1的放法算是同一种装法。
//
//2）允许袜子为空。
//
//3）M和N无大小关系，M可以比N大，M也可以比N小。

#include <iostream>
using namespace std;
/*
 * 整数划分问题
 */
int res(int m, int n)
{
    if (m < 1 || n < 1)
        return 0;
    if (m == 1 || n == 1)
        return 1;
    if (m < n)
        return res(m, m);
    if (m == n)
        return res(m, n - 1) + 1;

    return res(m, n - 1) + res(m - n, n);
}

int main() {
    int m, n;
    cin >> m >> n;

    cout << res(m, n);

    return 0;
}