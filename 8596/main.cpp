#include <iostream>
using namespace std;
int main() {
    int n;
    while(true){
        cin >> n;
        if (n == 0)
            break;
        int num[n + 1];
        int f[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> num[i];
            f[i] = 1;
        }

        for (int i = 1; i <=n; i++){
            for(int j = 1; j < i; j++){
                if(num[j] < num[i])
                    f[i] = max(f[i], f[j] + 1);
            }
        }
        int ans = 0;
        for (int k = 1; k <= n; ++k) {
            ans = max(ans, f[k]);
        }
        cout << ans << endl;


    }
    return 0;
}