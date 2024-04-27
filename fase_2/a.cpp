#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define o_maior_do_brasil_e_o void
#define int long long int
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define iii array<int, 3>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= (2e3)+7;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int vis[MAX][MAX];
vector<pii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char g[MAX][MAX];

int n, m, aux = 0; 
bool inbound(int u, int v){
    if(u>0 and u<=n and v>0 and v<=m) return true;
    return false;
}
bool can_go(int u, int v){
    for(auto [x, y]: dirs){
        if(g[u+x][v+y]=='#' and g[u-x][v-y]=='#') return false;
    }

    return true;
    
}
bool can_start(int u, int v){
    if(g[u][v]=='#') return false;
    for(auto [x, y]: dirs){
        if(g[u+x][v+y]=='#') return false;
    }


    return true;
    
}


void dfs(int i, int j, int id){
    if(g[i][j]=='#' or vis[i][j]==id) return;

    bool flag= false;

    for(auto [uu, vv]: dirs){
        uu+= i; vv+= j;
        if(inbound(uu, vv)){
            if(g[uu][vv]=='#')flag = true;
        }
    }

    aux++;
    vis[i][j]= id;

    if(flag) return;

    for(auto [uu, vv]: dirs){
        if(inbound(i+uu, j+vv)){
            dfs(uu+i, vv+j, id);
        }
    }
}

o_maior_do_brasil_e_o fluminense(){
   cin >> n >> m;
    // vector<vector<char>> g(n+1, vector<char>(m+1));
    // pii prevh = {0, 0};
    // pii prevw = {0, 0};

    int ans =0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> g[i][j];
            if(g[i][j]=='.')ans=1;
        }
    }



    int id = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(vis[i][j]==0 and g[i][j]!='#'){
                aux = 0;
                dfs(i, j, id);
                ans = max(ans, aux);
                id++;
            }
        }
    }

    cout << ans << endl;
}

signed main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)fluminense(); 
    
}