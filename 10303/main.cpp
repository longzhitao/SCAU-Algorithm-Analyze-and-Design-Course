//
//10303 数字三角（优先做）
//时间限制:1000MS  内存限制:65535K
//提交次数:117 通过次数:56
//
//题型: 编程题   语言: G++;GCC;VC
//        Description
//问题描述：给定一个由n行数字组成的数字三角形，如下图所示。试用动态规划算法，计算出从三角
//        顶部至底部的一条路径，使得该路径经过的数字总和最大。
//
//注意每个数字只能走向下一行左边或右边的数字，而不能跳跃的走。
//

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int input[n][n];
    int input_max[n][n];
    int input_next_max[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> input[i][j];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            if (i == n - 1)
                input_max[i][j] = input[i][j];
            else{
                if (input_max[i+1][j+1] >= input_max[i+1][j])
                {
                    input_max[i][j] = input_max[i+1][j+1] + input[i][j];
                    input_next_max[i][j] = j+1;
                }else{
                    input_max[i][j] = input_max[i+1][j] + input[i][j];
                    input_next_max[i][j] = j;
                }
            }
        }
    }
    cout << input_max[0][0] << endl;
    cout << input[0][0] << " ";
    int max_j_index = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j >= 0; --j) {
            if (j == input_next_max[i][max_j_index])
            {
                cout << input[i+1][j];
                if (i != n - 2)
                    cout << " ";
                max_j_index = j;
                break;
            }

        }

    }

    return 0;
}