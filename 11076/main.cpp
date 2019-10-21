#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using std::cin;
using std::string;
using std::cout;
using std::endl;

unsigned long long gcdFunc(unsigned long long a,unsigned long long b)
{
    unsigned long long temp;
    if (a < b)
    {
        unsigned long long c = a;
        a = b;
        b = c;
    }

    while (b > 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


int main()
{
    string num;
    cin >> num;

    unsigned long long a, b;

    if (num[num.size() - 1] != ')')
    {
        unsigned long long gcd;

        num = num.substr(2);

        b = 1;
        for (int i = 0; i < num.size(); ++i)
            b *= 10;

        a = 0;
        for (int i = 0; i < num.size(); ++i) {
            a = a * 10;
            a = a + ((int)num[i] - 48);
        }

        gcd = gcdFunc(a, b);
        a = a / gcd;
        b = b / gcd;
    } else{
        unsigned int index;
        index = num.find('(');

        unsigned long long a1, b1, a2, b2;

        string a1_str = num.substr(2, index - 2);
        a1 = 0;
        for (int i = 0; i < a1_str.size(); ++i)
        {
            a1 = a1 * 10;
            a1 = a1 + ((int)a1_str[i] - 48);
        }


        b1 = 1;
        for (int i = 0; i < index - 2; ++i)
            b1 *= 10;

        string a2_str = num.substr(index + 1, num.size() - index - 2);
        a2 = 0;

        for (int i = 0; i < a2_str.size(); ++i)
        {
            a2 = a2 * 10;
            a2 = a2 + ((int)a2_str[i] - 48);

        }


        b2 = 1;
        for (int i = 0; i < num.size() - 2 - index; ++i)
            b2 *= 10;
        b2 = b2 - 1;
        for (int i = 0; i < index - 2; ++i)
            b2 *= 10;



        unsigned long long gcd1 = gcdFunc(a1, b1);
        a1 = a1 / gcd1;
        b1 = b1 / gcd1;

        unsigned long long gcd2 = gcdFunc(a2, b2);
        a2 = a2 / gcd2;
        b2 = b2 / gcd2;

        unsigned long long gcd3 = gcdFunc(b1, b2);

        a = a1 * (b2 / gcd3) + a2 * (b1 / gcd3);
        b = b1 * (b2 / gcd3);

        unsigned long long gcd4 = gcdFunc(a, b);
        a = a / gcd4;
        b = b / gcd4;



    }
    cout << a << " " << b;



    return 0;
}

