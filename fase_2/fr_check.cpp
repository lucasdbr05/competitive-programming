#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define vii vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

vi graph[MAX], t_graph[MAX];
bool vis[MAX];

void dfs(int x){
    vis[x]= true;
    for(auto &no: graph[x]){
        if(!vis[no])dfs(no);
    }
}

void dfs_inv(int x){
    vis[x]= true;
    for(auto &no: t_graph[x]){
        if(!vis[no])dfs_inv(no);
    }
}


void fluminense(){
    int n, m; cin >> n>> m;


    while (m--){
        int a, b; cin >> a >> b;
        graph[a].pb(b);
        t_graph[b].pb(a); 
    }

    dfs(1);

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cout << NO<< endl<< 1 << " "<< i << endl;
            return;
        }
    }

    memset(vis, false, sizeof(vis));
    dfs_inv(1);

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cout << NO<< endl<< i <<  " "<< 1<< endl;
            return;
        }
    }

    cout << YES<< endl;

}

int32_t main(){
    sws;    
    int T=1;
    //cin >> T;
    while(T--)fluminense(); 
    
}