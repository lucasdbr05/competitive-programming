#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 1e6+10;

vector<set<int>> g(MAX);
int vis[MAX];
int  teams[MAX];
int n,m , a,b;
bool val =true;

bool dfs(int x, int t, int p){
    vis[x]=1;
    teams[x]=t;
    
    for(auto num:g[x]){
        if (num==p) continue;
        if (!teams[num]){
            if (!dfs(num,teams[x]^3, x))
            return false;
        }
        if (teams[num]==teams[x]) return false;
    }
    return true;
}




int main(){
    cin >> n >> m; 
    memset(vis,0, sizeof (vis));
    memset(teams,0, sizeof (teams));
    for (int i=0; i<m ; i++){
        cin >> a >> b; 
        g[a].insert(b);
        g[b].insert(a);
    }

    val= dfs(1,1,-1);


    for (int i=1; i<=n; i++){
        if (!vis[i]){
            if (!dfs(i,1,-1)){
                val= false;
            }
        }
    }

    if (val){
    for (int i=1; i<=n; i++){
        cout<< teams[i]<< " ";
    }
    cout << endl;
    }
    else cout << "IMPOSSIBLE"<< endl;
}