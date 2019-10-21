#include <iostream>
using namespace std;

int times = 0;
inline void Swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

bool Findsame(string list, int k, int i){

    for (int j = k; j <= i - 1; ++j) {
        if (list[j] == list[i])
            return true;
    }
    return false;
}


void Perm(string list, int k, int m){
    if (k == m){
        for (int i = 0; i <= m; ++i)
            cout << list[i];
        cout << endl;
        times++;
    } else{
        for (int i = k; i <= m; ++i) {
            if (Findsame(list, k, i))
                continue;
            Swap(list[k], list[i]);
            Perm(list, k+1, m);
            Swap(list[k], list[i]);
        }
    }
}




int main() {
    string s;
    cin >> s;
    cin >> s;

    Perm(s, 0, s.length() - 1);
    cout << times;
    return 0;
}