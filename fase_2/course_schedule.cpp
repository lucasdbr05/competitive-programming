#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(0);
const int MAX =2e5+10;
int n, m, a, b;
int degree[MAX];
vector<int> g[MAX];
stack<int> st;
vector<int> ans;


int32_t main(){
    cin >> n >> m;
    // memset(degree, false, sizeof degree);
    while (m--){
        cin >> a >> b;
        ++degree[b];
        g[a].push_back(b);

    }

    for (int i=1;i<=n; i++){
        if (!degree[i])st.push(i);
    }

    // memset(degree, false, sizeof degree);


    while (!st.empty()){
        int x = st.top(); st.pop();
        // if(degree[x]) continue;
        ans.push_back(x);
        for (auto num:g[x]){
            --degree[num];
            if (!degree[num]){
                st.push(num);
            }
        }
        
    }
    if (ans.size()!=n) cout << "IMPOSSIBLE"<< endl;
    else
        for (auto x: ans)
            cout << x << " ";

        cout << endl;
    




}