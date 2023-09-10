#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX = 1e6+1;
int n, tot, ans=0;
vector<int> v;
bool dp[110][MAX];

int32_t main(){
    cin>> n;
    v.push_back(0);
    for (int i=1; i<=n; i++){cin >> tot; v.push_back(tot);}

    for (int i=0;i<= 102; i++) dp[i][0]= true;
    tot =0;
    for (int j=1; j<=n; j++){
        tot += v[j];
        // cout << v[j]<< endl;
        for (int i=tot; i>=0;i--){
            dp[j][i]= (dp[j-1][i]||dp[j-1][tot-i]||dp[j][tot-i]);
        }
    }
//     for (int j=0; j<=n; j++){
//         for(int i=0; i<=tot; i++){
//             cout << dp[j][i]  <<" ";
//         }
//     cout << endl;
// }
// }
    for(int i=1; i<=tot; i++){

        if (dp[n][i]) ans++;
    }
    cout << ans<< endl;
    for(int i=1; i<=tot; i++){

        if (dp[n][i]) cout << i <<" ";
    }
    cout << endl;

}