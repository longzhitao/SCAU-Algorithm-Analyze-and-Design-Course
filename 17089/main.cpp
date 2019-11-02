//
//17089 最大m子段和
//        时间限制:1000MS  内存限制:65535K
//提交次数:0 通过次数:0
//
//题型: 编程题   语言: G++;GCC;VC
//        Description
//“最大m子段和”问题：给定由n个整数（可能为负）组成的序列a1、a2、a3、...、an，以及一个正整数m，
//要求确定序列的m个不相交子段，使这m个子段的总和最大！
//
//m是子段的个数。当m个子段的每个子段和都是负值时，定义m子段和为0。


#include <iostream>
using namespace std;
int res(int m, int n, int *a){
    int i,max,j,sum;
    if(n<m||m<1)
        return 0;

    int *b=new int[n+1];
    int *c=new int[n+1];
    b[0]=0;
    for(int i=0; i<=n; i++) c[i]=0;
    for(i=1;i<=m;i++)
    {
        b[i]=b[i-1]+a[i];
        c[i-1]=b[i];
        max=b[i];
        for(j=i+1;j<=i+n-m;j++)
        {
            b[j]=b[j-1]>c[j-1]?b[j-1]+a[j]:c[j-1]+a[j];
            c[j-1]=max;
            if(max<b[j])
                max=b[j];
        }
        c[i+n-m]=max;
    }

    sum=0;
    for(j=m;j<=n;j++)
        if(sum<b[j])
            sum=b[j];
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[n+1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cout << res(m, n, a);

    return 0;
}