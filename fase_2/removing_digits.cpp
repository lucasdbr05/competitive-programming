#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const ll INF= 0x3f3f3f3f;
int v, n, m, x, y;
ll ans =INF;
ll price[1005];
ll pages[1005];
ii books[1005];
ll memo[1000005];
bool vis[1005];
bool val=false;


// ll dp(ll n, ll qtt){
//     cout << n << endl;
//     if (n<0) return 0;
//     if (memo[n]!=INF) return memo[n];
//     if (n==0) {ans = min(qtt, ans);}
//     for (ll i=log10(n)+1;i>=0; i--){
//         ll exp = pow(10, i);
//         ll x = (n/exp)%10;
//         memo[n] = min(dp(n-x, qtt+1), memo[n]);
//     }
//     return memo[n];
// }



int main(){
    _ios_

    cin>> n;
    memset(memo, INF, sizeof memo);
    // dp(n,0);
    memo[0]=0;
    for (int i=1; i<=n; i++){
        int num = i;
        while (num>0){
            int d = num%10; num = num/10;
            memo[i]= min(memo[i], memo[i-d]+1);
        }
    }
    cout <<memo[n] << endl;
}