//8603 子集和问题（优先做）
//时间限制:1000MS  内存限制:1000K
//提交次数:795 通过次数:262
//
//题型: 编程题   语言: G++;GCC;VC

#include <iostream>
using namespace std;
bool found = false;
int res = 0;
int input[1000] = {0};
int tag[1000] = {0};
int n;
int c;

void  Backtrack(int floor){
    if (found)
        return;
    if (floor > n){
        if (res == c){
            found = true;
        }
        if (found){
            for (int i = 0; i < n; ++i) {
                if (tag[i] == 1)
                    cout << input[i] << " ";
            }
        }
    } else{
        res += input[floor];
        tag[floor] = 1;
        Backtrack(floor + 1);
        res -= input[floor];
        tag[floor] = 0;
        Backtrack(floor + 1);
    }

}
int main() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    Backtrack(0);
    if (!found)
        cout << "No Solution";
    return 0;
}