#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
typedef tuple<int,int,int> iii;
const int INF = 0x3f3f3f3f3f3f3f;
int n,m;
int dist[5000];
vector<iii> path;


void belmann_ford(){
    dist[1]=0;
    

    //relaxations
    for(int k=1; k<=n; k++){
        for (auto [v,u,c]: path){
            if (dist[v]== INF)continue;
            dist[u]= min(dist[v]+c, dist[u]);
            dist[u]= max(-INF, dist[u]);
        }
    }
    
    for(int k=1; k<=n; k++){
        for (auto [v,u,c]: path){
            if (dist[v]== INF)continue;
            dist[u]= max(dist[u], -INF);
            if(dist[v]+c<dist[u]) dist[u]= -INF;
        }
    }
}

int32_t main(){
    cin>> n >> m;
    for (int i=0; i<m; i++){
        int a,b,w;cin >> a >> b >> w;
        path.push_back({a,b,-w});
    }

    for (int i=2; i<=n; i++) dist[i]= INF;


    belmann_ford();
    // for (int i=1; i<=n; i++) cout << dist[i]<< " ";
    if (dist[n]==-INF) cout << -1 << endl;
    else cout <<-1*dist[n]<< endl;
}    

