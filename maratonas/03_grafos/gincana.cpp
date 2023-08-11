#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
#define endl '\n'

const int MAX = 1e5+10;
vector<vector<int>> adj(MAX);
vector<bool> vis(MAX, false);


void dfs(int num){
    vis[num]= true;
    for (auto x: adj[num]){
        if (!vis[x]){
            dfs(x);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int a, n;
    cin>> a>> n;
   
    for (int i=0; i<n; i++){
        int x,y;
        cin >> x>> y;x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int times= 0;
    for (int i =0; i<a;i++){
        if (!vis[i]){
            dfs(i);
            times++;
        }
    }


    cout << times << endl;

}
