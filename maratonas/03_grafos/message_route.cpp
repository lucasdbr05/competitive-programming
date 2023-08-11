#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
typedef pair<int, int> ii;
const int MAX = 1e5+10;

int n,m,curr;
vector<vector<int>> adj(MAX);
vector<bool> vis(MAX, false);
vector<int> parents(MAX, -1), dis(MAX, -1);

queue<int> q;





int main(){_
    cin >> n >> m;

    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    q.push(1); dis[1]=0;vis[1]=true;

    while(!q.empty()){
        curr = q.front(); q.pop();

        for (auto x: adj[curr]){
            if (!vis[x]){
                q.push(x);
                dis[x]=dis[curr]+1;
                parents[x]=curr;
                vis[x]=true;
            }
        }
    }

    if (parents[n]==-1) cout<< "IMPOSSIBLE"<< endl;
    else{
        cout<< dis[n]+1<< endl;

        vector<int> ans;ans.push_back(n);
        int aux = parents[n];
        while(aux!=1){
            ans.push_back(aux);
            aux = parents[aux];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        for (auto i: ans) cout<< i << " ";
        cout << endl;
    }


}
