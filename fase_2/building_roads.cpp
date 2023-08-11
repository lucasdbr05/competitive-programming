#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MAX = 1e5+10;
#define endl '\n'

vector<vector<int>> adj(MAX);
vector<bool> vis(MAX,false);

void dfs(int num){
    if (vis[num]) return;
    vis[num]=true;

    for (auto x : adj[num]){
        dfs(x);
    }

}



int main(){
    int n,m; cin >> n>>m;

    for (int i=0; i<m;i++){
        int x, y; cin>> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> v;

    for (int i=0; i<n; i++){
        if (!vis[i]){
            v.push_back(i);
            dfs(i);
        }
    }

    int len = v.size()-1;
    cout << len << endl;

    for (int i=1; i<=len; i++){
        cout << v[i-1]+1<< " "<< v[i]+1 << endl;
    }
}