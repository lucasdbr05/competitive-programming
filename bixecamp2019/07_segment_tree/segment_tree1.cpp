/*

Versão mais simples:

query: soma dos elementos de ql a qr
update: atualiza valor na posição p para x

*/


#include <bits\stdc++.h>
using namespace std;

const int N = 112345;

int t[4 * N];

int query(int i, int l, int r, int ql, int qr)
{
    if (ql <= l && qr <= r)
    {
        return t[i];
    }
    if (qr < l || r < ql)
        return 0;
    int m = (l + r) / 2;
    return query(2 * i, l, m, ql, qr) + query(2 * i + 1, m + 1, r, ql, qr);
}

void update(int i, int l, int r, int p, int x)
{
    if (l == r)
    {
        t[i] = x;
    }
    else
    {
        int m = (l + r) / 2;
        if (p <= m)
            update(2 * i, l, m, p, x);
        else
            update(2 * i + 1, m + 1, r, p, x);
        t[i] = t[2 * i] + t[2 * i + 1];
    }
}

int main()
{

    return 0;
}
