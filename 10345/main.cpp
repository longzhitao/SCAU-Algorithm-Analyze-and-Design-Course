#include <iostream>
#include <cstdio>

using namespace std;
int main() {
    int n;
    cin >> n;
    double num[n];
    double mean[n];
    double sum;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    mean[0] = num[0];
    sum = num[0];
    printf("%.2lf ", sum);
    for (int i = 1; i < n; ++i) {
        printf("%.2lf ", (sum + num[i]) / (i + 1));
        sum += num[i];
    }


    return 0;
}