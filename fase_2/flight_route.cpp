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
const int MAX= 1e5+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f;

int n, m, k;
vector<vector<pii>> routes;
vector<vector<int>> dist;
priority_queue<pii, vector<pii>, greater<pii>> pq;


void dijkstra(){
    pq.push({0, 1});


    while(!pq.empty()){
        auto [d, u]= pq.top(); pq.pop();    
        // cout << d << " "<< u<< endl;
        if(dist[u][k] < d) continue;
        
        for(auto [v, c]: routes[u]){    
            if(dist[v][k]>c+d){
                dist[v][k] = c+d;
                pq.push({dist[v][k], v});
                sort(dist[v].begin(), dist[v].end()); 
            }
        }
    }
}

void fluminense(){
    cin >> n >> m >> k;
    dist.resize(n+1);
    for(int i=0; i<=n; i++){
        dist[i].resize(k+1);
        for(int j=1; j<=k; j++){
            dist[i][j]= INF;
        }
    }
    routes.resize(n+1);
    while(m--){
        int a, b, p; cin >> a >> b >> p;
        routes[a].push_back({b,p});
    }

    // dist = vector(n+2,vector<int>(k+2, INF));
    for(int i=0; i<=n; i++) dist[i][0] = 0;
    dist[1][1]=0;
    dijkstra();
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<=k; j++){
    //         cout << dist[i][j]<< " ";
    //     }
    //     cout << endl;
    // }
    sort(dist[n].begin(), dist[n].end());
    for(int i=1; i<=k; i++){
        cout << dist[n][i]<< " ";
    }
 
}

int32_t main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)fluminense(); 
    
}