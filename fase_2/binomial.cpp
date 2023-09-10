#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

const int MAX=1e7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
int factorial[MAX], inverse[MAX];

int binomial(int n, int k) {
    return (factorial[n]*(inverse[k] * inverse[n - k] % MOD)) % MOD;
}

int exp(int x, int aux) {
	x %= MOD;
	int res = 1;
	while (aux > 0) {
		if (aux % 2 == 1) { res = res * x % MOD; }
		x = x * x % MOD;
		aux /= 2;
	}
	return res;
}


int32_t main(){
    factorial[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        factorial[i] = (factorial[i - 1] * i )% MOD;
    }

    inverse[MAX] = exp(factorial[MAX], MOD - 2);
	for (int i = MAX; i >= 1; i--) { inverse[i - 1] = inverse[i] * i % MOD; }

    int t;cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        cout << binomial(n,k)<< endl;
    }

}
