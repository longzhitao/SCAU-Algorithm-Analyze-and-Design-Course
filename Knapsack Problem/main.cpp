#include <iostream>
#include <cmath>

using namespace std;

void weight_sort();
void value_sort();
void w_v_ration_sort();

struct Item{
    int weight;
    int value;
    float  w_v_ratio;
}item[100];

int greedy(int n, int C){
    int max_value = 0;
    int sum_value = 0;
    int sum_weight = 0;

//    weight_sort();
    for (int i = 1; i <= n; ++i)
    {
        if (sum_weight + item[i].weight < C)
        {
            sum_weight += item[i].weight;
            sum_value += item[i].value;
        }
        else
            break;
    }
    max_value = sum_value;
    sum_value = 0;
    sum_weight = 0;

//    value_sort();
    for (int i = 1; i <= n; ++i)
    {
        if (sum_weight + item[i].weight < C)
        {
            sum_weight += item[i].weight;
            sum_value += item[i].value;
        }
        else
            break;
    }
    if (sum_value > max_value)
        max_value = sum_value;
    sum_value = 0;
    sum_weight = 0;

//    w_v_ration_sort();
    for (int i = 0; i < n; ++i)
    {
        if (sum_weight + item[i].weight < C)
        {
            sum_weight += item[i].weight;
            sum_value += item[i].value;
        }
        else
            break;
    }
    if (sum_value > max_value)
        max_value = sum_value;

    return max_value;
}

int brute_force(int w[], int v[], int n, int C){
    int max_value = 0;
    for (int i = 0; i < pow(2, n); ++i)
    {
        int case_i = i;
        int case_i_weight = 0;
        int case_i_value = 0;
        bool isBeyond = false;
        for (int j = 0; j < n; ++j)
        {
            if (case_i & 1)           //判断二进制串是否为1
            {
                case_i_weight += w[j];
                case_i_value += v[j];
            }
            if (case_i_weight > C)
            {
                isBeyond = true;
                break;
            }
            case_i = case_i >> 1;    //字符串右移  等价于 case_i /= 2
        }
        if (case_i_value > max_value && !isBeyond)
            max_value = case_i_value;
    }
    return max_value;
}

int dynamic_programming(int w[], int v[], int n, int C)
{
    int dp[n + 1][C + 1];

    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < C + 1; ++j)
            dp[i][j] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if (j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    return dp[n][C];
}

int main() {
    int C;
    int n;
    cin >> C >> n;
    int w[n + 1], v[n + 1];
    w[0] = v[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    cout << dynamic_programming(w,v,n,C);
    return 0;
}