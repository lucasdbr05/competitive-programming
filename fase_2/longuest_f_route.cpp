#include <bits/stdc++.h>
using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
#define endl '\n'
#define int long long int
const int MAX=1e6+10;
// #define ii pair<int, int>
 
 
vector<int> graph[MAX];
// set<pair<int, int>> graph[MAX];
int n, m;
int dist[MAX], parent[MAX], deg[MAX];
queue<int> q;
 
void topo(){
 
    while(!q.empty()){
        auto u = q.front(); q.pop();
        // cout << u << endl;
        for(auto x: graph[u]){
            deg[x]--;
            if(deg[x]==0) {
                parent[x]=u;
        
                if(x!=1) q.push(x);

            }
        }
    }
}

 
int32_t main(){
    sws;
    cin >> n >> m;
    memset(parent, -1, sizeof parent);
    memset(deg, 0, sizeof deg);
    while (m--){
        int a, b;cin >> a >> b;
        // graph[a].insert({b, -1});
        graph[a].push_back(b);
        
        deg[b]++;
    }
    for(int i=2; i<=n; i++){
        if(deg[i]==0) q.push(i);
    }
    topo();
    q.push(1);
    parent[n]=-1; parent[1]=-1;
    topo();
    if (parent[n]==-1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> resp;
        int x=n;
        while (x !=-1){
            resp.push_back(x);
            x= parent[x];
        }
        reverse(resp.begin(), resp.end());
        cout << resp.size() << endl;
        for(auto i: resp) cout << i<< " ";
        cout << endl;
 
    }
}