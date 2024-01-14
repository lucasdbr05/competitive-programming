#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef pair<ll, ll> ii;
const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
int b, e;

int fexp(int b, int e){
    if (e==0) return 1;

    int ans = fexp(b, e/2);
    if(e%2) return (((ans*ans)%MOD)*b)%MOD;
    else return (ans*ans)%MOD;
}

int main(){
    int t; cin >> t;
    while (t--){
        cin >>b>>e;
        cout << fexp(b,e) << endl;
    }

}