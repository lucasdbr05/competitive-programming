#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int, int> ii;
#define int long long int
 
const int INF= 1e9+10;
const int MAX= 1e6+10;
const int TAM= 1e3;
int n,m,a,b,c;
vector<vector<ii>> graph(MAX);
int dist[MAX];
int disc[MAX];
int vis[MAX];
int d, u, f, v, w;
pair<int,ii> t;
 
void dijkstra(){
    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
 
    dist[1]=0;
    disc[1]=0;
 
    pq.push({0,{1,0}});
 
    while(!pq.empty()){
        t = pq.top();pq.pop();
        d = t.first;
        u = t.second.first;
        f = t.second.second;
        if (f==1){if (disc[u]<d) continue;}
        if (f==0){if (dist[u]<d) continue;}
 
        for (auto e:graph[u]){
            v = e.first; w = e.second;
 
            if (f==0){
                if (dist[v]>d+w){
                    dist[v]= w+d;
                    pq.push({dist[v],{v,0}});
                }
                if (disc[v]>d+w/2){
                    disc[v] = d+ w/2;
                    pq.push({disc[v],{v,1}});
                }
            }
 
            if (f==1){
                if (disc[v]>d+w){
                    disc[v]=d+w;
                    pq.push({disc[v], {v,1}});
                }
            }
        }
    }
}
 
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dist, INF, sizeof(dist));
    memset(disc, INF, sizeof(disc));
    cin >> n >> m;
 
    while (m--){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    dijkstra();
    cout<< disc[n]<< endl;
}