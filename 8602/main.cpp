#include <iostream>
#include <algorithm>

using namespace std;
struct input{
    int s;
    int t;
};

bool cmp(const input &a, const input &b){
    return a.t <= b.t;
}

int GreedySelector(int n, input section[], bool selected[])
{
    int sum = 1;
    selected[0] = true;
    int preEnd = 0;
    for (int i = 1; i < n; ++i) {
        if (section[i].s >= section[preEnd].t)
        {
            selected[i] = true;
            preEnd = i;
            sum++;
        }
    }
    return sum;
}
int main() {
    int n;
    cin >> n;
    input section[n];
    for (int i = 0; i < n; ++i) {
        cin >> section[i].s >> section[i].t;
    }
    sort(section, section + n, cmp);

    bool selected[n];
    cout << n - GreedySelector(n, section, selected);

    return 0;
}