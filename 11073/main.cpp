#include <iostream>
using namespace std;
int k;

int res(int arr[], int  )

int main() {
    int n;
    cin >> n >> k;
    int num[n];
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    Qsort(num,0, n - 1);
    for (int j = 0; j < n; ++j) {
        cout << num[j];
    }
    return 0;
}