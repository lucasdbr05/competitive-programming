#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MOD = 1e9+7;

int t,k;
int memo[1000005];
int f[1000005];





int32_t main(){
    cin>> t >> k;
    memo[0]=1;
    for (int i=1; i<=1e5+5;i++){
        memo[i]= (i-k)>=0? (memo[i-1]+memo[i-k])%MOD : memo[i-1]%MOD;
        f[i] = (f[i-1]+ memo[i-1])%MOD; 
    }
    
    while (t--){
        int a,b; cin >> a >> b;
        int ans = (f[b+1]-f[a]+MOD)%MOD;
        cout << ans << endl;
   }
}


// cin >> t >> k;
//     vi psum(maximo + 2);
//     vi dp(maximo + 2,0);
    
//     dp[0] = 1;
//     psum[0] = 0;
 
//     for(int i = 1; i <= maximo; i++)
//     {
//         if(i - k >= 0)
//         {
//             dp[i] = dp[i-1] + dp[i-k];
//             dp[i] %= MOD;
//         }
//         else
//         {
//             dp[i] = dp[i-1];
//         }
//         psum[i] = psum[i-1] + dp[i-1];
//         psum[i] %= MOD;
//     }
 
//     while(t--)
//     {
//         int a,b;
//         cin >> a >> b;
//         int ans = (psum[b+1] - psum[a] + MOD)%MOD;
//         cout << ans << endl;
//     }
//     return 0;
// }