#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n;
int dp[MAX];

int fexp(int b, int e){
    if(e==0) return 1;

    int aux = fexp(b, e/2);
    if(e%2) return (((aux*aux)%MOD)*b)%MOD;
    return ((aux*aux)%MOD);
}

int32_t main(){
    sws;

    cin >> n;
    int aux = n*(n+1)/2;
    memset(dp, 0, sizeof (dp));
    if(aux%2!=0){cout << 0 << endl;return 0;}
    dp[0]=1;
    for (int i=1; i<=n; i++){
        for(int j= aux/2; j>=i; j--){
            dp[j]=(dp[j]+ dp[j-i])%MOD ;
        }
    }

    // for (int i=1; i<=aux/2; i++)cout << dp[i]<< " ";

    cout << (dp[aux/2]*fexp(2, MOD-2))%MOD<< endl;

}