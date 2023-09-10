#include <bits/stdc++.h>
using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long int
const int MAX =2*1e5+5;
int n, x;
stack<int> st;
vector<int> adj[MAX];
int par[MAX];
int ans[MAX];

void dfs_pai(int p){
    for (auto node: adj[p]){
        if (par[node]==0){
            par[node]=p;
            dfs_pai(node);
        }
    }
}


int32_t main(){
    sws;

    cin >> n >> x;

    for (int i=0; i<n-1; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    par[x]=-1;

    dfs_pai(x);
   
   int index =1;
   ans[x]= index;

   

   for (int i=1; i<=n; i++){
    int id =i;
    int aux = ans[id];
    while (aux==0){
        st.push(id);
        id = par[id];
        aux = ans[id];
    }
    while(!st.empty()){
        int num = st.top(); st.pop();
        index++;
        ans[num]= index;
     }
   }

   for (int i=1; i<=n; i++) cout << ans[i]<< " ";
   cout << endl;


}