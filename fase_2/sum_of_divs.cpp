#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
int n;

int fexp(int b, int e){
    if (e==0) return 1;

    int ans = fexp(b, e/2);
    if(e%2) return (((ans*ans)%MOD)*b)%MOD;
    else return (ans*ans)%MOD;
}

int32_t main(){
    cin >> n;int q, j;
    int inv2= fexp(2, MOD-2);
    int ans = 0;
    int curr = 1;
    while(curr<=n){
        q = n/curr;
        j = n/q+1;
        int rj = (((j%MOD)*(j-1)%MOD)%MOD)*inv2%MOD;
        int ri = (((curr%MOD)*(curr-1)%MOD)%MOD)*inv2%MOD;
        int aux = (rj-ri+MOD)%MOD;
        ans = (ans+(q%MOD)*aux)%MOD;
        curr= j;
    }
    cout << ans << endl;

}