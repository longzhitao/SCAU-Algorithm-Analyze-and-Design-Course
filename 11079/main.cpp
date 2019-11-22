//11079 可以移动的石子合并（优先做）
//时间限制:1000MS  内存限制:1000K
//提交次数:0 通过次数:0
//
//题型: 编程题   语言: G++;GCC;VC
//        Description
//有n堆石子形成一行(a1,a2,…,an，ai为第i堆石子个数)，现要将石子合并成一堆，规定每次可
//        选择至少2堆最多k堆移出然后合并，每次合并的分值为新堆的石子数。
//
//若干次合并后，石子最后肯定被合并为一堆，得分为每次合并的分值之和。
//
//现在求解将这n堆石子合并成一堆的最低得分和最高得分。


#include <iostream>
#include <algorithm>

using namespace std;
int input[1000];
int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    int min_res = 0;
    int max_res = 0;


    sort(input, input + n);

    int index = n - 1;
    int max_temp = input[index];
    while(index != 0){
        max_temp = max_temp + input[index - 1];
        max_res += max_temp;
        index--;
    }

    while (n % (k - 1 ) != 1){
        input[n++] = 0;
    }
    sort(input, input + n);
    index = 0;
    int  min_temp = input[index];
    while (index <= n - k){
        for (int i = 0; i < k - 1; ++i) {
            input[index + k - 1] += input[index + i];
        }
        min_res += input[index + k - 1];
        index += k - 1;
        sort(input, input + n);
    }
    cout << min_res << " " << max_res << endl;

    return 0;
}