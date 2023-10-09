#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

const int MAX=1e7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
int factorial[MAX], inverse[MAX];

int fexp(int b, int e){
    if (e==0) return 1;

    int ans = fexp(b, e/2);
    if(e%2) return (((ans*ans)%MOD)*b)%MOD;
    else return (ans*ans)%MOD;
}

int binomial(int n, int k) {
    return (factorial[n]*(fexp(factorial[k], MOD-2) * fexp(factorial[n - k], MOD-2) % MOD)) % MOD;
}



int32_t main(){
    factorial[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        factorial[i] = (factorial[i - 1] * i )% MOD;
    }

    // inverse[MAX] = fexp(factorial[MAX], MOD - 2);
	// for (int i = MAX; i >= 1; i--) { inverse[i - 1] = inverse[i] * i % MOD; }

   
        int n, k; cin >> n >> k;
        cout << binomial(n+k -1,k)<< endl;

}
