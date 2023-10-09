#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX = 2e5+10;
const int MOD = 1e9+7;
vector<int> tree[MAX];
bool vis[MAX];
int path[MAX];
int deg[MAX];
int n, m;
queue<int> q;

void dfs(int s){
    if (vis[s]) return;
    vis[s]=true;
    for(auto x: tree[s]){
        path[x] = (path[x]+path[s])%MOD;
        dfs(x);
    }
}

void topo(){
    for (int i=2; i<=n;i++){
        if (deg[i]==0) q.push(i);
    }
    
    while (!q.empty()){
        auto u = q.front();q.pop();

        for(auto x: tree[u]){
            deg[x]--;
            if (deg[x]==0){
                q.push(x);
            }
        } 
    }

    path[1]=1;
    q.push(1);

    while (!q.empty()){
        // cout << q.front()<< endl;
        auto u = q.front(); q.pop();

        for (auto x: tree[u]){
            path[x]=(path[x]+path[u])%MOD;
            deg[x]--;
            if(deg[x]<=0) q.push(x);
        }
    }
}

int32_t main(){
    memset(path, 0, sizeof path);
    sws;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        deg[b]++;
    }

    path[1]=1;
    topo();

    cout << path[n]<< endl;

}