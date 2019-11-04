//11075 强盗分赃
//        时间限制:1000MS  内存限制:1000K
//提交次数:0 通过次数:0
//
//题型: 编程题   语言: G++;GCC;VC
//        Description
//有天夜里5个强盗A、B、C、D、E抢到一大堆金币（金币个数不超过n个，n<=100000000），可是怎么也无法平均分成5份，
//吵吵嚷嚷……
//
//吵累了，只好先睡觉，准备第二天再分。
//
//夜深了，一个强盗A偷偷爬起来，先拿了一个金币私下放自己口袋藏好，再将金币分为5等份，将自己的那一份再私藏好
//        就去睡觉了。
//
//随着第二个强盗B也爬起来，也是私拿了一个金币再分5等份，也私藏起自己那份就睡觉去了。
//
//后来的三个强盗C、D、E也都是这样办的。
//
//问最初有多少个金币？（最初的金币个数有多种可能，请输出不超过n的所有可能，从小到大排列）
#include <iostream>

using namespace std;
int count = 0;
int func(int num)
{
    int temp = num-1;
    if(temp%5 == 0 && count<5)
    {
        count++;
        return func(temp/5*4);
    }
    else if (count==5)
        return 1;
    else
        return 0;
}
int main() {

    int n;
    cin >>n;
    if(n < 3121)
        cout <<"impossible";

    int sum = 0;
    for(int x = 255; x > 0 ;x++){
        sum=(12 * x + 8) + 53 * (x + 1) / 256;
        if(sum > n) break;
        if((53 * (x + 1) % 256) == 0)
            cout << sum <<" ";
    }

    return 0;
}