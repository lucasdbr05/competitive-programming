#include <bits/stdc++.h>
using namespace std;

const int MAX=100010;
const int INF = 1000000010;

using ii= pair<int, int>;
int dist[MAX];
vector<ii> adj[MAX];
bitset<MAX> processed;


void djikstra(int source, int N){
    for (int i=1; i<=N; ++i) dist[i]=INF;

    dist[source] = 0;
    processed.reset();

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0,source));

    while (not pq.empty()){
        auto d = pq.top().first, u = pq.top().second;
        //d = dist, u = vertex to be processed
        pq.pop();

        if (processed[u]) continue;

        processed[u]= true;

        for (const auto &e:adj[u]){
            auto v = e.first ;
            auto w = e.second;

            if (dist[v]>d+w){
                dist[v]=d+w;
                pq.push(ii(dist[v],v));
            }

        }
    }
}

int solve(int N){
    djikstra(1, N);
    return dist[N];
}

int main(){
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;

    while (M--){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(ii(b,c));
        adj[b].push_back(ii(a,c));
    }

    auto ans = solve(N);

    cout << ans<< "\n";
}