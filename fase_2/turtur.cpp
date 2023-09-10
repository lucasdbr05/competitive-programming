#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef long long int ll;
const int LINF =0x3f3f3f3f3f3f3f;
typedef vector<tuple<int, int>> vt;
typedef vector<tuple<int, int, int>> vtiii;
#define _ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
int n, m, k, a, b, c,d;
map<int, vt> dict[200001];
map<int, ll> mp[200001];
int card[200001];

priority_queue<tuple<int,int, int> , vtiii, greater<tuple<int, int, int>>> pq;

void dijkstra(int i, int cartao){
    pq.push({0, i, cartao});

    while (!pq.empty()){
        auto [dist, node, ct] = pq.top(); pq.pop();

        if (mp[node].count(ct)) continue;
        mp[node][ct] = dist;

        if (card[node]!=ct){
            pq.push({dist, node, card[node]});
        }

        for (auto [no, aux_d]: dict[node][ct]){
            pq.push({dist+aux_d, no, ct});
        }
    }
    
}

int main(){
    _
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) cin >> card[i];

    for (int i=0; i<m; i++){
        cin >> a >> b >> c >> d;
        dict[a][d].push_back({b, c});
        dict[b][d].push_back({a, c});
    }

    dijkstra(1, card[1]);

    ll ans = LINF;

    for (auto [ignore, dist]: mp[n]){
        ans = min(ans, dist);
    }

    if ((ans)>=LINF) ans=-1;

    cout << ans << endl;

}
