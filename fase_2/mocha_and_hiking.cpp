#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
int n, k, x;
#define iii tuple<int, int, int>
const int INF=0x3f3f3f3f3f3f3f;
const int MAX=1e4+10;

void dfs(int s){

}

int32_t main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        int z=0,o;
        for (int i=0; i<n; i++){
            cin >> k; 
            vector<vector<int>> g(k+3);
            bool vis(n+1);
            if (k){
                g[n+1].push_back(k);
            }
            else{
                g[k].push_back(n+1);
                z++;
            } 

        }
        o= n+1-z;

        if (abs(o-z)>1) cout << -1 << endl;
        else{
            
        }

    }
}