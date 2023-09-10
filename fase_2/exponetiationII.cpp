#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef pair<ll, ll> ii;
const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
int a, c, b, e;

ll fexp_modular(int b, int e, int mod){
    if (e==0) return 1;

    ll ans = fexp_modular(b, e/2, mod);
    if(e%2) return (((ans*ans)%mod)*b)%mod;
    else return (ans*ans)%mod;
}

int main(){
    int t; cin >> t;
    while (t--){
        cin >>a>>b>>c;
        e =fexp_modular(b,c, MOD-1);
        cout << fexp_modular(a, e, MOD)<< endl;
    }

}