#include <bits/stdc++.h>
using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
#define endl '\n'
#define int long long int
const int MAX=3e5+10;
// #define ii pair<int, int>

set<pair<int, int>> graph[MAX];
int n, m;
int dist[MAX], parent[MAX];

void djikstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1]=0;
    parent[1]=-1;
    pq.push({0,1});

    while(!pq.empty()){
        pair<int, int> v = pq.top(); pq.pop();
        if(dist[v.second]>=v.first) {
            for(pair<int, int> e:graph[v.second]){
                if(dist[e.first]>dist[v.second]+e.second){
                    dist[e.first]= dist[v.second]+e.second;
                    pq.push({dist[e.first],e.first});
                    parent[e.first]=v.second;
                }
            }   

        }


    }
}

int32_t main(){
    sws;
    cin >> n >> m;
    // graph.resize(n+1);
    // dist.resize(n+1);
    // parent.resize(n+1);
    // for(int i = 1; i <= n; ++i)parent[i] = -1;
    memset(parent, -1, sizeof parent);
    while (m--){
        int a, b;cin >> a >> b;
        graph[a].insert({b, -1});
    }
    djikstra();
    if (dist[n]==0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> resp;
        cout << (-1*dist[n])+1 << endl;
        int x=n;
        while (x !=-1){
            resp.push_back(x);
            x= parent[x];
        }
        reverse(resp.begin(), resp.end());
        for(auto i: resp) cout << i<< " ";
        cout << endl;

    }
}