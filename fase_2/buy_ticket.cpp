#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, int> ii;
#define endl '\n'

const int MAX =1e6+10;
const int INF =1e8+10;
int vis[MAX];
ll dist[MAX];
ii p;
ll n, m, a, b, c, d, node, w, u;
vector<vector<ii>> adj(MAX);


void dijkstra(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    dist[0]=0;
    pq.push({0,0});

    while (!pq.empty()){
        p = pq.top(); pq.pop();
        d=p.first; node=p.second;
        // cout << d << " " << node << endl;
        if (vis[node]) continue;
        vis[node]=1;

        for(auto e: adj[node]){
            w= e.first; u= e.second;
            if (dist[u]>w+d){
                dist[u]=w+d;
                pq.push({dist[u], u});
            }
        }

    }
}

int main(){
    cin>> n >> m;
    memset(dist, INF, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    while (m--){
       cin >> a >> b >> c;
       adj[a].push_back({2*c, b}); 
       adj[b].push_back({2*c, a}); 
    }

    for (int i= 1; i<=n; i++){
        cin >> c; 
        adj[0].push_back({c,i});
        adj[i].push_back({c,0});
    }
    dijkstra();

    for (int i=1; i<=n; ++i){
        cout << dist[i] << " ";
    }
    cout << endl;


}
