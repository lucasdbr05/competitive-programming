#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
const int MAXV=2000;
const int INF=0x3f3f3f3f3f3f3f3f;
int n, m;
int graph[MAXV][MAXV], aux[MAXV][MAXV],vis[MAXV], parent[MAXV];
queue<int> q;


bool bfs(int source, int d){
    memset(vis, false, sizeof vis);
    q.push(source);
    vis[source]=true;
    parent[source]=-1;
    while (!q.empty()){
        int u = q.front(); q.pop();

        for(int i=1; i<=n;i++){
            if (vis[i]==false and aux[u][i]>0){
                q.push(i);
                parent[i]=u;
                vis[i]=true;
            }
        }
    }

    return vis[d]==true;
    
}


int ford_fulkerson(int s, int t){
    int u;
    memset(aux, 0, sizeof aux);
    for (int u=1; u<=n; u++){
        for (int v=1; v<=n; v++){
            aux[u][v]= graph[u][v];
        }
    }
    memset(parent, 0, sizeof parent);
    int max_flow = 0;

    while(bfs(s,t)){
        int path_flow = INF;
        for (int v=t; v!=s; v=parent[v]){
            u= parent[v];
            path_flow = min(path_flow, aux[u][v]);
        }
            for (int v=t; v!=s; v= parent[v]){
                u = parent[v];
                aux[u][v]-= path_flow;
                aux[v][u]+= path_flow;
            }

            max_flow += path_flow;
        }

        return max_flow;
        
}
    

int32_t main(){
    cin >> n >> m;
    memset(graph, 0, sizeof graph);
    for(int i=1; i<=m; i++){
        int a, b, s; cin >> a >> b >> s;
        graph[a][b]+=s;
    }

    int ans = ford_fulkerson(1, n);

    cout << ans << endl;



}