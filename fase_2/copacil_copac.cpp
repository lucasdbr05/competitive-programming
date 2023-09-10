#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
#define int long long int
typedef pair<ll, ll> ii;

vector<ii> adj[200005];
int tms[200005];


void dfs(int node, int par){
    for (auto [u, id]: adj[node]){
        if (par==id) continue;
        tms[u]= tms[node]+(id<par);
        dfs(u, id);
    } 
}


int32_t main(){
    int t; cin >> t;
    while(t--){
        ll n;cin>> n;
        for (int i=1; i<=n; i++)adj[i].clear();
        for (int i=0; i<n-1; i++){
            int x,y; cin >> x >> y;
            adj[x].push_back({y, i});
            adj[y].push_back({x, i});
        }
        tms[1]=1;
        dfs(1,-1);

        cout << *max_element(tms+1, tms+1+n)<< endl;

    }
}