#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define float double
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define iii array<int, 3>
#define vpii vector<pair<int, int>>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
vpii dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pii> g[MAX];
vector<int> v;
vector<int> dist(MAX, INF);
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<bool> vis(MAX, false);


void dijkstra(int k){
    dist[k] = v[k];
    pq.push({dist[k], k});


    while(!pq.empty()){
        auto [w, u] = pq.top(); pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(auto [vv, ww]: g[u]){
            if(dist[vv]> dist[u] +  v[vv] + ww){
                dist[vv]= dist[u] +  v[vv]+ ww;
                pq.push({dist[vv], vv});
            }
        }
    }

}


void solve(){
    int n, m;
    cin >> n >> m;
    v.resize(n+1);

    for(int i=1; i<=n; i++) cin >> v[i];


    for(int i=0; i<m; i++){
        int u, v, k; cin >> u >> v >> k;

        g[u].pb({v, k});
        g[v].pb({u, k});
    }

    dijkstra(1);


    for(int i=2; i<=n; i++) cout << dist[i] << esp;
    cout << endl;

    
}

signed main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)solve(); 
    
}