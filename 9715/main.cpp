#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int heights[n];
    for (int i = 0; i < n; ++i)
        cin >> heights[i];

    int right[n];
    int left[n];

    //向右查找从右端开始，记录查找减少时间复杂度（必须从右端开始
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        if (heights[i] > heights[i + 1])
            right[i] = 1;
        else{
            int j = i + 1;//向右查找
            while (j < n && heights[j] >= heights[i])
                j += right[j];
            right[i] = j - i;//记录向右延伸最远个数
        }
    }

    //同上不过向左查找
    left[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (heights[i] > heights[i - 1])
            left[i] = 1;
        else{
            int j = i - 1;
            while (j >= 0 && heights[j] >= heights[i])
                j -= left[j];
            left[i] = i - j;
        }
    }

    int area = heights[0];
    for (int i = 0; i < n; ++i) {
        area = max(heights[i] * (left[i] + right[i] - 1), area);//重叠一块 -1
    }


    cout << area;

    return 0;
}