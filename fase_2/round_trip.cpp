#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const ll INF= 0x3f3f3f3f;
int v, n, m, a, b;
ll out =INF;
vector<int> ans, aux;
vector<int> adj[100005];
bool vis[100005];
int parent[100005];
bool val=false;
 
// void dfs(int i, int start){
//     if (val) return;
//     if (vis[i]) return;
//     if (adj[i].empty()) return;
//     vis[i]=true;
//     for (auto elem: adj[i]){
//         if (elem!=start){
//             aux.push_back(elem);
//             dfs(elem, start);
//             aux.pop_back();
//         } else if (elem==start){
//             if (aux.size()>=ans.size()){
//                 aux.push_back(start);
//                 ans = aux;
//                 aux.pop_back();
//                 if (ans.size()>=4){
//                     val=true;
//                     return;
//                 }
//             }
//         }
//     }
// }



bool dfs(int i, int p){
    vis[i]=true;
    parent[i]=p;

    for (auto elem: adj[i]){
        if (elem==p) continue;
        if (vis[elem]){
            a= i; b=elem;
            return true;
        }
        if (!vis[elem]){
            if(dfs(elem, i)) return true;
        }
    }
    return false;
}
 
 
int main(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            if (dfs(i, -1)){
                val=true;
                break;
            }
        } 
    }
 
    // if (ans.size()>3) val= true;
 
    if (val) {
        int x = a;
        ans.push_back(a);
        while(x!=b){
            ans.push_back(parent[x]);
            x = parent[x];
        }
        ans.push_back(a);
        cout << ans.size() << endl;
        for (auto num: ans){
            cout << num << " ";
        }
        cout << endl;
    } else{
        cout << "IMPOSSIBLE"<< endl;
    }
}