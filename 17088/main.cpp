#include <iostream>
#include <algorithm>

using namespace std;

int max_times = 0;
int mode;

void findMode(int num[], int l, int r){
    int times = 1;
    int mid = (l + r) / 2;
    int l_index, r_index;
    l_index = mid;
    r_index = mid;

    bool l_flag = true;
    bool r_flag = true;
    while (l_flag || r_flag)
    {
        if (l_flag)
        {
            if (l_index - 1 < l)
                l_flag = false;
            else if (num[l_index - 1] != num[mid])
                l_flag = false;
            else
            {
                times++;
                l_index--;
            }
        }
        if (r_flag)
        {
            if (r_index + 1 > r)
                r_flag = false;
            else if (num[r_index + 1] != num[mid])
                r_flag = false;
            else
            {
                times++;
                r_index++;
            }

        }
    }

    if (times > max_times)
    {
        max_times = times;
        mode = num[mid];
    }


    if (l_index - l > times)
        findMode(num, l, l_index - 1);
    if (r - r_index > times)
        findMode(num, r_index + 1, r);


}

int main() {
    unsigned int n;
    cin >> n;
    int num[n];

    for (int i = 0; i < n; ++i)
        cin >> num[i];

    sort(num, num + n);

    findMode(num, 0, n - 1);
    cout << mode << " " << max_times;

    return 0;
}