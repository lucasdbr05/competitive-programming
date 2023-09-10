#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
#define _ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
int n, m,p,ss, a, b, ans;
vector<int> graph[100];
int vis[100];


void dp(int v, int qtt){
    if (v>n){
        if (qtt>0) ans++;
        return;
    }

    dp(v+1, qtt);

    bool val = true;
    for (auto e: graph[v]){
        if (vis[e]) val=false;
    }
    if (val){
        vis[v]=1;
        dp(v+1, qtt+1);
        vis[v]=0;
    }
}


int main(){
    cin >> n >> m;

    for (int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dp(1, 0);

    cout << ans <<endl;
}
