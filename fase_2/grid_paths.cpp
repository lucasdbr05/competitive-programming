#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MOD = 1e9+7;
int n, paths=0;
char grid[1005][1005];
int dp[1005][1005];
int vis[1005][1005];

// bool val(int i, int j){
//     if (i<=0 or i>n) return false;
//     if (j<=0 or j>n) return false;
//     if (vis[i][j]) return false;
//     return true;
// }

// void dfs(int i, int j){
//     if (!val(i,j)) return ;
//     vis[i][j]= true;
//     if (i==n and j==n){paths= (paths+1)%MOD;}
//     else{
        
//     }
//     vis[i][j]=false;
// }

int main(){
    cin >> n;
    for (int i=1;i<=n; i++){
        for (int j=1;j<=n; j++){
            cin >> grid[i][j];
            if (grid[i][j]=='*') vis[i][j]=true;
        }
    }

    // dfs(1,1);
    if (!vis[1][1]) dp[1][1]=1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (vis[i][j]) continue;
            if (i-1>0) dp[i][j]= (dp[i][j]+ dp[i-1][j])%MOD;
            if (j-1>0) dp[i][j]= (dp[i][j]+ dp[i][j-1])%MOD;
        
        }
    }

    paths = dp[n][n];
    cout << paths << endl;
}
