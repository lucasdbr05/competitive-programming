#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

typedef pair<int, int> ii;
const int INF = 1e6+10;
int n,m,q,a,b,w,x, ans=-INF;
ii p;
vector<vector<ii>> f(2000*2000);
int dist[2000];
int aux;
vector<int> hosp;
bitset<2000> vis;



void dijkstra(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int h: hosp){
        pq.push({0,h});
        dist[h]=0;
    }
    
    while(!pq.empty()){
        p = pq.top();pq.pop();

        if (vis[p.second]) continue;
        vis[p.second]=true;
        for(auto& node:f[p.second]){
            if (dist[node.second]>node.first+dist[p.second]){
                dist[node.second]=node.first+dist[p.second];
                pq.push({dist[node.second], node.second});
            }
        }
    }

}




int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(cin >> n >> m >> q){
        f.clear(); hosp.clear();
        ans = -INF;
        memset(dist, INF, sizeof(dist));
        vis.reset();
        for (int i=0;i<m; i++){
            cin >> a >> b >> w;
            f[a].push_back({w,b});
            f[b].push_back({w,a});
        }
        while (q--){
            cin>> x;
            hosp.push_back(x);
        }

        dijkstra();

        for (int i=1;i<=n;i++){
            ans = max(ans, dist[i]);
        }
        cout << ans << endl;
        
    }
}