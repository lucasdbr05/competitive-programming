#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 3e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
vector<bool> check(MAX,false);
// int n, k;
// int dp[MAX][MAX];




void solve(){
    int n;cin >> n;

    string ans = (n>=1111)||check[n]? "YES":"NO";
    cout << ans << endl;
    
}

int32_t main(){
    
    sws;

    for (int i=1; i<MAX; i++){
        if(i%11==0 or i%111==0 or i%1111==0){check[i]=true;}
        else if(i>11 and check[i-11]){check[i]=true;}
        else if(i>111 and check[i-111]){check[i]= true;}
        
    }
    
    int t; cin >> t; while(t--) solve();
}