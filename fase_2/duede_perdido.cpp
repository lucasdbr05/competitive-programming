#include <bits/stdc++.h>
 
using namespace std;
#define endl '\n'
typedef pair<int, int> ii;
const int INF=0x3f3f3f3f;
int n,m, aux;
int  ans=INF;
int path[1010][1010];
int vis[1010][1010];
int dist[1010][1010];
queue<ii> q;
int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};
vector<ii> out; 
 
ii init, p;
 
 
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;
    for (int i =1;i<=n;++i){
        for (int j =1;j<=m;++j){
            cin >> path[i][j];
            vis[i][j]=0;
            if (path[i][j]==3){
                init={i,j};
            } if (path[i][j]==0){
                out.push_back({i,j});
            }
        }
    }
 
        
        
    vis[init.first][init.second]=1;
    dist[init.first][init.second]=0;
    q.push(init);
    
    while (!q.empty()){
        ii p;
        p = q.front(); q.pop();
        
        for (int f=0; f<4;f++){
            int i=0,j=0;
            i= p.first+neighborY[f];
            j= p.second+neighborX[f];
            
            if ((0>=j || j>m)||(0>=i || i>n)) continue;
            if (path[i][j]==2) continue;
            if (vis[i][j]) continue;
            
            vis[i][j]=1;
            q.push({i,j});
            dist[i][j]= dist[p.first][p.second]+1;
 
            if (path[i][j]==0) ans = min(ans, dist[i][j]);
        }
    }
 
 
    cout <<ans<< endl;
}