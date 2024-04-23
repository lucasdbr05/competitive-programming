#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
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
const int MAX= 2e5+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
bool vis[MAX];
vector<int> g[MAX];
int idx[MAX];
map<int, int> mp, paths;
int cnt = 0, adj = 0;

void dfs(int v, int id){
    if(vis[v]) return;

    vis[v]=true;
    idx[v]= id;
    mp[id]++;
    cnt++;
    adj+= g[v].size();
    int aux = 0;
    for(auto u:g[v]){
        dfs(u, id);
    }
}



void fluminense(){
    int n, m; cin >> n >> m;

    while(m--){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans =0;
    for(int i=1;i<=n; i++){
        if(!vis[i]){
            cnt = 0;
            adj = 0;
            dfs(i, i);
            cout << cnt << " " << adj << endl;
            ans+= (cnt*(cnt-1))/2 - adj/2;
        }
    }

    cout << ans << endl;




    

    


}

int32_t main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)fluminense(); 
    
}