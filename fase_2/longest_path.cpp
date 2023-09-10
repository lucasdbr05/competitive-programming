#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 100005;
const int INF= 0x3f3f3f3f;

int n, m, a,b, ans=0;
vector<int> g[MAX];
int dist[MAX];
bitset<MAX> vis;

int dfs_dp(int i){
    if (vis[i]) return dist[i];
    vis[i]=true;
    for (int no: g[i]){
        dist[i] = max(dist[i], dfs_dp(no)+1);
    }
    return dist[i];
}


int32_t main(){
    sws

    cin >> n >> m;
    while (m--){
        cin>>a>> b;
        g[a].push_back(b);
    }

    
    for (int i=1; i<=n; i++){
        ans =max(dfs_dp(i), ans);
    }

    cout << ans << endl;
}           