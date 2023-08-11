#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> ii;
typedef long long int ll;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
ll n, m, x, a, b;


int main(){
    _ios_ 
    cin >> n >> m;
    vector<vector<ll>> grid(n+1, vector<ll>(m+1, 0));
    vector<vector<bool>> vis(n+1, vector<bool>(m+1, false));
    
    cin>> x;
    while (x--){
        cin>> a >> b;
        vis[a][b]=true;
    }
    if (!vis[1][1]) grid[1][1]=1;
    for (int i=1;i<=n; i++){
        for (int j=1; j<=m; j++){
            if (vis[i][j]) continue;
            if (i-1>0) grid[i][j]= (grid[i][j]+ grid[i-1][j])%MOD;
            if (j-1>0) grid[i][j]= (grid[i][j]+ grid[i][j-1])%MOD;
        }
    }
    
    cout << grid[n][m] << endl;
}

