//
//11077 最长公共子字符串（优先做）
//时间限制:1000MS  内存限制:65535K
//提交次数:0 通过次数:0
//
//题型: 编程题   语言: G++;GCC;VC
//Description
//求两个输入序列的最长的公共子字符串的长度。子字符串中的所有字符在源字符串中必须相邻。
//
//如字符串：21232523311324和字符串312123223445，他们的最长公共子字符串为21232，长度为5。

#include <iostream>
#include <vector>

int dp[10005][10005];


using namespace std;
int main() {
    string s_1;
    string s_2;
    cin >> s_1;
    cin >> s_2;
    int res = min(s_1.size(), s_2.size());

    for (int i = 0; i <= res; ++i) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    int max = 0;
    vector<char> res_string;


    for (int i = 1; i <= s_1.size(); ++i) {
        for (int j = 1; j <= s_2.size(); ++j) {
            if (s_1[i - 1] == s_2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = 0;
            }
            if (dp[i][j] > max){
                max = dp[i][j];
                res_string.clear();
                for (int k = 0; k < max; ++k) {
                    res_string.push_back(s_1[i - max + k]);
                }
            }
        }
    }


    cout << max << endl;
    for (int i = 0; i < res_string.size(); ++i) {
        cout << res_string[i];
    }

    return 0;
}