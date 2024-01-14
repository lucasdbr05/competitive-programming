#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3;

vector<int> k_label(MAX, -1), graph[MAX], graph_tr[MAX], aux;
bool vis[MAX];

void dfs(int x){
    vis[x] =  true;

    for(auto &e: graph[x]){
        if(!vis[e])dfs(e);
    }

    aux.pb(x);
}



void dfs_kosaraju(int x, int k){
    vis[x] = true;
    for(auto &e:graph_tr[x]){
        if(!vis[e]){
            dfs_kosaraju(e, k);
        }
    }

    k_label[x]= k;


}

void fluminense(){
    int n, m; cin >> n>> m;
    int k =1;
    while(m--){
        int a, b; cin >>a >> b;
        graph[a].pb(b);
        graph_tr[b].pb(a);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i])dfs(i);
    }
    reverse(aux.begin(), aux.end());
    int kingdom =0;
    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++){
        if(!vis[aux[i]]){
            ++kingdom;
            dfs_kosaraju(aux[i], kingdom);
        }
    }

    cout<< kingdom<< endl;
    for(int i=1; i<=n; i++)cout << k_label[i]<< " "; cout << endl;

}

int32_t main(){
    sws;    
    int T=1;
    //cin >> T;
    while(T--)fluminense(); 
    
}