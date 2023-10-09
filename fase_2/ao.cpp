#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;


void solve(){
    int n, k; cin >> n >> k;

    vector<int> v(n+1);
    for(int i=0; i<n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    int ans =0;
    for(int i=n-1; i>=n-k; i--){
        ans += v[i-k]/ v[i];
    }

    for (int i=k; i<n-k; i++) ans += v[i];


    cout << ans << endl;


}



int32_t main(){
    sws;
    
    int t=1; cin >> t;
    while(t--) solve();

}