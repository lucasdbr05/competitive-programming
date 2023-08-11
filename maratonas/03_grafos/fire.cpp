#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
typedef pair<int, int> ii;
const int MAX = 1e5+10;

int neighborX[4]= {1,0,-1,0};
int neighborY[4]= {0,1,0,-1};
const int INF= 0x3f3f3f; 

int t, n,m, y, x,aux_qF, ans=-1;
bool pos;

char matrix[2000][2000];
int vis[2000][2000];
int dist[2000][2000];
ii p,f,curr, pp;
queue<ii> qP;
queue<ii> q;

bool isVal(int y, int x){
    if (0>=y) return false;
    if (n<y) return false;
    if (0>=x) return false;
    if (m<x) return false;
    if (vis[y][x]) return false;
    if (matrix[y][x]=='#') return false;
    return true;
}


int main(){_
    cin >>t;
    while(t--){
        ans=-1;
        cin>> m >> n;
        memset(vis, 0, sizeof vis);
        memset(dist, INF, sizeof dist);
        
        for(int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                cin>> matrix[i][j];
                if (matrix[i][j]=='@') {p = {i,j};}
                if (matrix[i][j]=='*') {q.push({i,j}); vis[i][j]=1;dist[i][j]=0;}
            }
        }
        

        while(!q.empty()){
            f = q.front(); q.pop();

            for (int z=0; z<4; z++){
                y= f.first+ neighborY[z];
                x= f.second+ neighborX[z];

                if (isVal(y, x)){
                    q.push({y,x}); vis[y][x]=1;
                    dist[y][x]= dist[f.first][f.second]+1;
                }
            }
        }

        qP.push(p);
        dist[p.first][p.second]= 0;
        vis[p.first][p.second]= 1;
        

        memset(vis, 0, sizeof vis);

        while(!qP.empty()){
            pp = qP.front(); qP.pop();

            for(int z=0;z<4; z++){
                y= pp.first+ neighborY[z];
                x= pp.second+ neighborX[z];

                if ((x==1|| x==m )||(y==1||y==n)){
                    if (ans<0 && dist[y][x]<INF) ans = (dist[y][x]);
                    else ans = min(ans, dist[y][x]);
                    
                }

                if (isVal(y, x) && dist[pp.first][pp.second]+1<dist[y][x]){
                    qP.push({y,x}); vis[y][x]=1;
                    dist[y][x]= dist[pp.first][pp.second]+1;
                }
            }
        }
        //  for(int i=1;i<=n;++i){
        //     for (int j=1;j<=m;++j){
        //         cout<< dist[i][j]<< " ";
        //     }
        // cout << endl;
        // }
        if (ans>=0) cout << ans << endl;
        else cout << "IMPOSSIBLE"<< endl;
    }

}