//9716 矩形的并
//        时间限制:1000MS  内存限制:65535K
//提交次数:119 通过次数:27
//
//题型: 编程题   语言: G++;GCC;VC
//        Description
//在 X-Y 坐标平面上，给定多个矩形，它们的边分别与坐标轴平行。请计算它们的并的面积。
//
//
//
//输入格式
//        输入第一行为一个整数 n，1<=n<=100，表示矩形的数量。
//接下来有 n 行，每行包括四个数：x1,y1,x2,y2 (0<=x1<x2<=100000;0<=y1<y2<=100000)，
//用空格分开，不一定为整数。
//(x1,y1)表示一个长方形的左下顶点坐标，(x2,y2)表示右上顶点坐标。
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;

    double rectangle[n][2];
    for (int i = 0; i < n; ++i)
        cin >> rectangle[i][0] >> rectangle[i][1];
    vector

    return 0;
}