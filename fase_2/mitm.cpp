#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<int> v;
vector<int> generate(int l, int r){
    int sz = r-l+1;
    vector<int> out;

    for(int i=0; i<(1<<sz); i++){
        int aux = 0;
        for(int j=0; j<sz; j++){
            if(i&(1<<j))aux += v[l+j];
        }
        out.push_back(aux);
    }

    return out;
}


int32_t main(){
    sws;
    int n, m, ans=0; cin >> n >> m;

    v.resize(n);

    for(int i=0; i<n; i++) cin >> v[i];

    vector<int> l = generate(0, (n>>1)-1);
    sort(l.begin(), l.end());
    vector<int> r = generate((n>>1), n-1);
    sort(r.begin(), r.end());

    for(auto num: l){
        auto aux = upper_bound(r.begin(), r.end(), m-num)-lower_bound(r.begin(), r.end(), m-num);
        ans += aux;
    }

    cout << ans << endl;




}