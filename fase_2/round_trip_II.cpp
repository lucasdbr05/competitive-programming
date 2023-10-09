#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
const int MAX = 1e5+10;
int n, k;
bool got = false;
vector<int> g[MAX];
bool vis[MAX], aux[MAX];
stack<int> st;

bool dfs(int i){
    vis[i]=true;
    aux[i]=true;
    st.push(i);
    for (auto x:g[i]){
        if(!vis[x]){
            if(dfs(x))return true;
        }
        if(aux[x]){
            st.push(x);
            return true;
        }
    }
    st.pop();
    aux[i] = false;
    return false;

}

int32_t main(){
    int n, k; cin >> n >> k;
    while(k--){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i=1; i<=n;i++){
        if(!vis[i] && dfs(i)) break;
    }

    if(st.empty())cout <<"IMPOSSIBLE"<< endl;
    else{
        vector<int> ans;
        int fst = st.top();
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
            if (ans.back()==fst and ans.size()>1) break;
        }
        
        cout << ans.size()<< endl;
        reverse(ans.begin(), ans.end());
        for (auto x: ans) cout << x << " ";
        cout << endl;
        
    }
}