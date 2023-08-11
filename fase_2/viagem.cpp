#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int INF= 0x3f3f3f3f;
int v, n, m, x, y;
ll out =INF;
vector<iii> path[100005];
ll memo[100005][205];
bool vis[100005];
bool val=false;


// void dfs(int i, int p, int time){
//     if (vis[i]) return;
//     if (p>v) return;
//     vis[i]=1;
//     if (i==y){
//         val = true;
//         out = min(out, time);  
//     } 
//     else{
//         for (auto [node, t, price]: path[i]){
//             dfs(node, p+price, time+t);
//         }
//     }
//     vis[i]=0;
// }


int main(){
    _ios_   
    cin >> v >> n >> m;
   
    for (int i=0; i<m; i++){
        int a, b, t, p;
        cin >> a >> b >> t >> p;
        path[a].push_back(iii(b,t,p));
        path[b].push_back(iii(a,t,p));
    }

    cin >> x >> y;


    for (int cost=0; cost<=v; cost++){
        for (int i=1; i<=n; i++){
            memo[i][cost]=INF;
        }
        memo[x][cost]=0;

        for(int i=1; i<=n;i++){
            for(auto [node, time, p]: path[i]){
                if (cost<p or p==0) continue;

                memo[i][cost] = min(memo[i][cost], memo[node][cost-p]+time);
            }
        }

        set<ii> s;

        for (int i=1; i<=n; i++){
            s.insert({memo[i][cost], i});
        }

        while(!s.empty()){
            int no = s.begin()->second ; s.erase(s.begin());
            
            for(auto [node, time, p]:path[no]){
                if (p!=0) continue;

                if (memo[node][cost]> memo[no][cost]+time){
                    s.erase({memo[node][cost], node});
                    memo[node][cost]= memo[no][cost]+time;
                    s.insert({memo[node][cost], node});
                    
                }
            }
        }
    }
    if (memo[y][v]==INF) out =-1;
    else out =memo[y][v];

    cout  << out << endl; 
}