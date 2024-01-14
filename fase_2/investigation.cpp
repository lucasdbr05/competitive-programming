#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
vector<pii> graph[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int routes[MAX], min_f[MAX], max_f[MAX], dist[MAX];


void dijkstra(){
    pq.push({0, 1});
    
    dist[1] = 0;
    routes[1]=1;

    while(!pq.empty()){
        auto [d, u] =  pq.top(); pq.pop();

        if(dist[u]< d) continue;
        for(auto [v, c]: graph[u]){
             if(dist[v]> c+d){
                dist[v] = c+d;
                routes[v]= routes[u];
                min_f[v]= min_f[u]+1;
                max_f[v]= max_f[u]+1;
                pq.push({dist[v],v});
            } else if(dist[v]==c+d){
                routes[v]= (routes[u]+routes[v])%MOD;
                min_f[v] = min(min_f[v], min_f[u]+1);
                max_f[v] = max(max_f[v], max_f[u]+1);
            }
        }
    }
}

void fluminense(){
    int n, m; cin >> n >> m;
    memset(dist, 0x3f, sizeof dist);
    while(m--){
        int a, b, c; cin >> a>> b >> c;
        graph[a].push_back({b, c});
    }


    dijkstra();

    cout << dist[n]<< " "<< routes[n]<< " "<< min_f[n]<< " "<< max_f[n]<< endl;

}

int32_t main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)fluminense(); 
    
}