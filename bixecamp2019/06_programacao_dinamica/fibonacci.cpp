#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const ll MOD = 1e9 + 7;

ll memo[200200];

ll fib(ll x)
{
    if (x <= 2)
        return 1;
    ll &memom = memo[x];
    if (memom != -1)
        return memom;

    return memom = (fib(x - 1) + fib(x - 2)) % MOD;
}

int main(int argc, char *argv[])
{
    int n = stoi(argv[1]);

    // ll fib = 0; ll next = 1;

    // for (int i = 0; i<=n;i++){
    //     fib+=next;
    //     swap(fib, next);
    //     fib%= MOD; next%=MOD;
    // }
    // cout<< fib<<endl

    memset(memo, -1, sizeof(memo)); // Valores não passados de memo são definidos como -1
    printf("%lld\n", fib(n));
}