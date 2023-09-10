#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long int


int32_t main(){
    int n;cin >>n;
    vector<int> t[2];
    vector<int> dp[2];
    for (int i=0; i<n; i++){
        int x; cin >> x;
        t[0].push_back(x);
    }
    for (int i=0; i<n; i++){
        int x; cin >> x;
        t[1].push_back(x);
    }

    dp[0].push_back(0);dp[1].push_back(0);
    int aux;
    for (int i=1; i<=n; i++){
        aux = max(dp[0][i-1], dp[1][i-1]+t[0][i-1]);
        dp[0].push_back(aux);
        aux = max(dp[1][i-1], dp[0][i-1]+t[1][i-1]);
        dp[1].push_back(aux);
    }

    int ans = max(dp[0][n], dp[1][n]);
    cout << ans << endl;
}