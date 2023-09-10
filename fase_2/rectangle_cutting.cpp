#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(0);
const int MAX = 1e6+10;
const int INF = 0x3f3f3f3f;
const int X  =510;
int n,m, aux;
int dp[X][X];


int32_t main(){
    cin >> n >> m;
    
    memset(dp, INF, sizeof dp);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (i==j) dp[i][j]=0;
            else {
                for (int k=1; k<=i; k++) dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);   
                for (int k=1; k<=i; k++) dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);   
            }
        }
    }

    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=m; j++){
    //         cout << dp[i][j]<< " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m]<< endl;
}