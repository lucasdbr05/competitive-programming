#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
const int MAX = 2e5+10;
const int MOD= 1e9+7;
int n, m;
int deg[MAX];
int path[MAX];
bool vis[MAX];
vector<int> g[MAX];

void topo(){
    queue<int> q;
    for (int i=2; i<=n; i++){
        if (deg[i]==0)q.push(i);
    }

    while(!q.empty()){
        auto u=q.front(); q.pop();
        for (auto x: g[u]){
            deg[x]--;
            if (deg[x]==0){
                q.push(x);
            }
        }
    }

    q.push(1);
    path[1]=1;

    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto x: g[u]){
            deg[x]--;
            path[x]= (path[x]+path[u])%MOD;
            if (deg[x]==0) q.push(x);
        }
    }


}


int32_t main(){
    memset(path, 0, sizeof path);
    cin >> n >>m;

    for (int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        deg[v]++;
        g[u].push_back(v);
    }


    topo();
    cout << path[n]<< endl;    
    
}