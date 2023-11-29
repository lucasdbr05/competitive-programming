#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 6e5+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
vector<int> v;
vector<int> deg(MAX), path(MAX);

void solve(){
    int n, aux;
    queue<int> q;
    aux=0;
    // vector<int> ones;
    for(int i=0; i<n; i++){
        cin >> deg[i]>> path[i];
        if(deg[i]==1){/*ones.push_back(i);*/q.push(i);}
        
    }
    vector<pii> ans;
    while(!q.empty()){
        int curr1, curr2; curr1 = q.front();q.pop();
        curr2 = path[curr1];
        deg[curr1]--;
        deg[curr2]--;if(deg[curr2]==1)q.push(curr2);
        path[curr2]^=curr1;
        ans.push_back({curr1, curr2});

    }

    cout << ans.size() << endl;
    for(auto [a,b]: ans) cout << a << " "<< b << endl;
}
 
 
 
int32_t main(){
    sws;
    int t=1;// cin >> t;
    while(t--)solve();
}