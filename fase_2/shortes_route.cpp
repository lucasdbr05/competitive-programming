#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define sws ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
vector<vector<int>> dist;
const int INF=1e18;
const int LEN  =1000;
// int dist[LEN][LEN];
int a,b,c, x,y,w;

int32_t main(){
    sws
    cin >> a >> b >>c;
    dist.resize(a+1);
    for (int i=0; i<=a; i++)dist[i].resize(a+1);
    // memset(dist, INF, sizeof dist);
    vector<vector<int>> dist(a+4, vector<int> (a+4, INF));
    for (int i=0; i<=a; i++) for (int j=0; j<=a; j++) dist[i][j]=INF;
    for (int i=1; i<=b; i++){
        cin >> x>> y >> w;
        dist[x][y]=min(w, dist[x][y]);
        dist[y][x]=min(w, dist[y][x]);
    }

    for (int k=1; k<=a; k++){
        for (int i=1; i<=a; i++){
            for (int j=1;j<=a; j++){
                dist[i][j]= min(dist[i][j], dist[i][k]+ dist[k][j]);
            }
        }
    }

    for (int i=1; i<=c; i++){
        cin >> x>> y;
        if (x==y) dist[x][y]=0;
        if (dist[x][y] ==INF)dist[x][y]=-1;
        cout << dist[x][y]<< endl;
        
    }


}