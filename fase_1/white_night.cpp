#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <typeinfo>
// #include <bits/stdc++.h>

using namespace std;
#define mod 1500
int fb[2000];
int fibo(int x)
{
    return fb[x];
}
int exp(int x, int y)
{
    int p = 1;
    while (y != 0)
    {
        if (y % 2 == 1)
        {
            p = (p * x) % mod;
            y--;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return p;
}
int fibonacci(int num)
{
    if (num == 1 || num == 2)
    {
        return 1;
    }
    else
    {
        return (fibonacci(num - 1) + fibonacci(num - 2)) % 1000;
    }
}

int main()
{
    int n, i, j, k, l, m, d;
    string bin;
    fb[1] = fb[2] = 1;
    for (i = 3; i < 1510; i++)
        fb[i] = (fb[i - 1] + fb[i - 2]) % 1000;
    cin >> n;
    while (n--)
    {
        cin >> bin;
        d = l = 0;
        for (i = bin.size() - 1; i >= 0; i--)
        {
            if (bin[i] == '1')
                d = (d + exp(2, l)) % mod;
            l++;
        }
        d = fb[d];
        if (d < 10)
            cout << "00" << d << endl;
        else if (d >= 10 && d < 100)
            cout << "0" << d << endl;
        else
            cout << d << endl;
    }
    return 0;
}