#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
typedef pair<int, int> ii;
const int MAX = 1e5+10;

int neighborX[4]= {1,0,-1,0};
int neighborY[4]= {0,1,0,-1};
char neighborD[4]= {'R','D','L','U'};

const int INF= 0x3f3f3f; 

int t, n,m, y, x, ans=-1, u, v;
bool pos;

char matrix[2000][2000];
int steps[2000][2000];
int vis[2000][2000];
int dist[2000][2000];
ii p,f,curr, a, init, aux;
bool valid;
queue<ii> qP;
queue<ii> q;


bool isValM(int y, int x){
    if (0>=y) return false;
    if (n<y) return false;
    if (0>=x) return false;
    if (m<x) return false;
    if (vis[y][x]) return false;
    if (matrix[y][x]=='#') return false;
    return true;
}
bool isValA(int y, int x){
    if (0>=y) return false;
    if (y>n) return false;
    if (0>=x) return false;
    if (x>m) return false;
    if (vis[y][x]) return false;
    if (matrix[y][x]!='.') return false;
    return true;
}


int main(){_
    cin >> n >> m;

    memset(dist, INF, sizeof (dist));
    memset(vis, 0, sizeof (vis));

    for(int i= 1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> matrix[i][j];
            if (matrix[i][j]=='M'){q.push({i,j}); vis[i][j]=1; dist[i][j]=0;}
            if (matrix[i][j]=='A'){init = {i,j};}
        }
    }

    while(!q.empty()){
        p = q.front(); q.pop();
        u=p.first; v=p.second;

        for(int i=0; i<4; i++){
            y = u+neighborY[i];
            x = v+neighborX[i];

            if (isValM(y,x) && dist[y][x]>dist[u][v]+1){
                q.push({y,x}); vis[y][x]=1;
                dist[y][x]= dist[u][v]+1;
        
            }
        }
    }

    q.push(init);
    dist[init.first][init.second]=0;
    vis[init.first][init.second]=1;
    
    memset(vis, 0, sizeof(vis));
    memset(steps, -1, sizeof steps);
    u=init.first;v=init.second;
    if(((u==1||u==n)||(v==1||v==m))){
            if (ans<0 && dist[u][v]<INF) ans = (dist[u][v]);
            else ans = min(ans, (dist[u][v]));
            curr= {u,v};
            valid=true;
        }

    while(!q.empty()){
        a = q.front(); q.pop();
        u=a.first; v=a.second;
        for (int i=0; i< 4; i++){
            y = u+neighborY[i];
            x = v+neighborX[i];
            if (!isValA(y,x)) continue;
            if (dist[u][v]+1>= dist[y][x]) continue;
            if(((x==1||x==m)||(y==1||y==n)) && isValA(y,x)){
                if (ans<0 && dist[y][x]<INF) ans = (dist[y][x]);
                else ans = min(ans, (dist[y][x]));
                valid = true;
                curr= {y,x};
            }

            if (isValA(y,x) && dist[u][v]+1< dist[y][x]){
                q.push({y,x}); vis[y][x]=1;
                dist[y][x]= dist[u][v]+1;
                steps[y][x]= i;
            }
        }   
    }


    if (valid){
        cout << "YES"<< endl;

        vector<char> path;

        aux = curr;
        
        while(steps[aux.first][aux.second]!=-1){
            int c = steps[aux.first][aux.second];
            path.push_back(neighborD[c]);
            aux = {aux.first-neighborY[c], aux.second-neighborX[c]};
        }
        reverse(path.begin(), path.end());

        cout << path.size()<< endl;
        for(auto e: path){
            cout << e << "";
        }
        cout << endl;
    }else{
        cout << "NO"<< endl;
    }
}