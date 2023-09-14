#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
int n, k, x;
#define iii tuple<int, int, int>
const int INF=0x3f3f3f3f3f3f3f;

const int MAX=2e5+10;
set<int> s;
vector<iii> aux;

int32_t main(){
    int t; cin >> t;
    while (t--){
        cin>> n;
        vector<int> v(n);
        map<int, int> mp;
        int ans = 0;
        for(int i=0; i<n; i++){
            cin >> k;
            k-=i;
            ans += mp[k];
            mp[k]++;
        }
        cout << ans << endl;
    }

}