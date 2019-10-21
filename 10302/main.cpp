#include <iostream>
#include <cmath>

using namespace std;
long long dp[10010][10010];
long long res(int n, int k){
    if (dp[n][k] != 0)
        return dp[n][k];

    if (k == 0 || n == 0){
        dp[k][n] = 1;
        return 1;
    }

    else if (k > (int)log2(n)){
        return res(n, (int)log2(n));
    }
    else if (k > 0){
        long long sum = 0;
        for (int i = 0; i <= k; ++i)
            sum += res(n - (int)(pow(2, i)), i);
        dp[n][k] = sum;
        return sum;
    }
}


int main() {
    int n;
    cin >> n;

    cout << res(n,n) %1000000000;
    return 0;
}