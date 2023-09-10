#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
const int MAXV=1010;
int n, m;
int graph[1010][1010], aux[1010][1010];
int level[MAXV], vis[MAXV], adj[MAXV], parent[MAXV];
queue<int> q;


bool bfs(int source, int sink){
    memset(vis, false, sizeof vis);
    q.push(source);
    vis[source]=true;
    parent[source]=-1;
    while (!q.empty()){
        int u = q.front(); q.pop();

        for(int i=0; i<=MAXV;i++){
            if (vis[i]==false and aux[u][i]>0){
                q.push(i);
                parent[i]=u;
                vis[i]=true;
            }
        }
    }

    return vis[sink];
    
}


int ford_fulkerson(int s, int t){
    for (int u=1; u<=MAXV; u++){
        for (int v=1; v<=MAXV; v++){
            aux[u][v]= graph[u][v];
        }
    }

    int max_flow = 0;

    while(bfs(s,t)){
        int path_flow = 0x3f3f3f3f;
        for (int v=t; v!=s; v=parent[v]){
            int u= parent[v];
            path_flow = min(path_flow, aux[u][v]);
        }
            for (int v=t; v!=s; v= parent[v]){
                int u = parent[v];
                aux[u][v]-= path_flow;
                aux[v][u]+= path_flow;
            }

            max_flow += path_flow;
        }

        return max_flow;
        
}
    

int32_t main(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b, s; cin >> a >> b >> s;
        graph[a][b]=s;
    }

    int ans = ford_fulkerson(1, n);

    cout << ans << endl;



}