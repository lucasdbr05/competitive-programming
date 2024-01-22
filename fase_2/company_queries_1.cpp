#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define vii vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define iii array<int, 3>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int log2(int n){
    int LOG = 0;
    while((1<<LOG)<=n)LOG++;
    return LOG;
}

int kth_ancestor(int node, int k, int LOG ,vector<vector<int>>& up, vector<int>&parent, vector<int>& depth){
    if(k>depth[node])return -1;

    for(int i=LOG-1; i>=0; i--){
        if((1<<i)<=k){
            node = up[node][i];
            k-=(1<<i);
        }
    }
    return node;
}


void fluminense(){
    int n, q; cin >> n >> q;
    vector<int> parent(n+1), depth(n+1);
    int LOG = log2(n);
    vector<vector<int>> up(n+1, vector<int>(LOG));    
    for(int i=2; i<=n; ++i)cin >> parent[i];
    depth[1]=0;
    parent[1]=0;
    for(int i=1; i<=n; i++){
        up[i][0]= parent[i];
        if(i!=1){
            depth[i]= depth[parent[i]]+1;
        }
        for(int j=1; j<LOG; j++){
            up[i][j]= up[up[i][j-1]][j-1];
        }
    }

    while(q--){
        int node, k; cin >> node >> k;
        cout << kth_ancestor(node, k, LOG,up, parent, depth)<< endl;
    }
    
}

int32_t main(){
    sws;    
    int T=1;
    //cin >> T;
    while(T--)fluminense(); 
    
}