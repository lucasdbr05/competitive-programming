#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ii pair<int, int>
int n, k, x;
const int INF=0x3f3f3f3f3f3f3f;
const int MAX=2e5+10;
vector<int> tree[MAX];
queue<int> q;

ii bfs(int s){
    vector<int>dist(MAX, INF); 
    dist[s]=0;
    int node = s;
    q.push(node);
    while (!q.empty()){
        node = q.front();q.pop();
        // cout << node<<" "<< dist[node] << endl;
        for(auto v:tree[node]){
            if(dist[v]>=INF){
                dist[v]= dist[node]+1;
                q.push(v);
            }
        }
    }
    
    return {node, dist[node]};

}


int32_t main(){
    sws;
    cin >> n;
    for(int i=1;i<n; i++){
        int a,b;cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    auto [v, ig]= bfs(1);
    auto [ign, ans]= bfs(v);

    cout << ans << endl;
}