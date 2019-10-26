#include <iostream>
using namespace std;
int num[22];
int res(int n){
    if (num[n] != 0)
        return num[n];
    if (n == 1){
        num[n] = 1;
        return 1;
    }
    else if (n > 1){
        int sum = 0;
        for (int i = 1; i <= n - 1; ++i) {
            sum += res(i) * res(n - i);
        }
        num[n] = sum;
        return sum;
    }
}
int main() {
    int n;
    cin >> n;
    cout << res(n);
    return 0;
}