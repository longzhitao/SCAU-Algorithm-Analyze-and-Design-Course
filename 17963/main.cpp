//
//17963 完美数
//时间限制:10000MS  内存限制:65535K
//提交次数:0 通过次数:0
//
//题型: 编程题   语言: G++;GCC;VC
//Description
//圣经上写着：“神6天创造天地万有，第7日安歇。”  这个世界用6天创造，暗示这个创造是多么完美！
//
//任何一个自然数的约数中都有1和它本身，而所有小于它本身的因数叫做这个自然数的真约数。例如，6的所有真约数
//是1、2、3；8的所有真约数是1、2、4。如果一个数的真约数之和等于这个自然数本身，则这个自然数就称为完美数。
//比如6就是一个完美数，而8却不是。
//
//完美数只有6吗？还有一些，但找到的完美数是非常少的（完美的东西都比较稀缺），用沧海一粟来形容也不为过，因
//为到目前为止，科学家们借助计算机的帮助也只找到约47个完美数，第一个完美数就是数字6。
//
//实际上，在非常遥远的古代，古代数学家就开始探寻完美数了。公元前3世纪，古希腊著名数学家欧几里得发现了一个
//计算完美数的公式：如果2^n-1是一个质数，那么，由公式N(n)=2^(n-1)*(2^n-1)算出的数一定是一个完美数。例如，
//当n=2时，2^2-1=3是一个质数，于是N(2)=2^(2-1)*(2^2-1)=2*3=6是一个完美数；当n=3时，2^3-1=7也是一个质数，
//N(3)=4*7=28是一个完美数；当n=5时，N(5)=496也是一个完美数。
//
//18世纪时，大数学家欧拉又从理论上证明：每一个偶完美数必定是由上述公式算出的。
//
//所以，寻找新的完美数与寻找新的质数密切相关。
//
//也曾经有人验证过位数少于36位的所有自然数，始终也没有发现奇完美数的踪迹。不过，在浩瀚的自然数海洋里，奇
//完美数是否存在，也没有任何证明能证实这一结论。
//
//尽管有欧拉和欧几里德的公式，寻找完美数的工作仍然非常艰巨。
//例如，当n=31时，N(31) = 2^(31-1)*(2^31-1) = 2305843008139952128，这是一个19位数。
//
//1979年，当人们知道2^44497-1是一个新的质数时，随之也就知道了2^44496*（2^44497-1）是一个新的完美数；1983年
//，人们知道2^86243-1是一个更大的质数时，也就知道了 2^86242*（2^86243-1）是一个更大的完美数。迄今所知最大的
//一个完美数是2^43112608*(2^43112609-1)。
//
//出这个题目，是让大家体会分离出一个比较大的整数的因子有多难？判断一个比较大的整数是质数有多难？不信？你按照
//前述完美数的定义来写程序，看你能输出到第几个完美数。
//
//现在请你以下列格式输出前8个完美数，每行一个完美数，前面是序号后面是完美数，中间用空格间隔。如：
//1 6
//2 xx
//3 xxx
//……


#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int p[8] = {2, 3, 5, 7, 13, 17, 19, 31};
    for (int i = 0; i < 8; ++i) {
        long long res = pow(2, p[i] - 1) * (pow(2, p[i]) - 1);
        cout << i + 1 << ' ' << res << endl;
    }
    return 0;
}