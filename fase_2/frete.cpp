#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

typedef pair<int, int> ii;
const int INF = 1e5+10;
const int MAX = 1e6+10;

int n,m,q,a,b,w,x, ans=INF;
ii p;
vector<vector<ii>> path(MAX);
vector<int> dis_ua, dis_as;


vector<int> f;
bitset<MAX> vis_ua;

vector<int> dijkstra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<int> dist(n+10,INF);
    bitset<MAX> vis;
   
    
    dist[s] = 0;
    pq.push({0,s});

    while (!pq.empty()){
        p = pq.top(); pq.pop();
        if (vis[p.second]) continue;
        vis_ua[p.second]=true;
        
        for(auto& num: path[p.second]){
            if (dist[num.second]>num.first+p.first){
                dist[num.second]=num.first+p.first;
                pq.push({dist[num.second], num.second});
            }
        }
    }
    
    return dist;
}



int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m >> x;

    for (int i =0;i<m;i++){
        cin>> a >> b >> w;
        path[a].push_back({w,b});
        path[b].push_back({w,a});
    }

    dis_ua = dijkstra(1);
    dis_as = dijkstra(n);

    while(x--){
        cin >> q;
        ans = min(ans, (dis_ua[q]+ dis_as[q]));
        
    }

    cout << ans << endl;
}