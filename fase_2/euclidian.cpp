#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int, int>
#define ff first
#define ss second
#define sws ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int norm(pii a, pii b) {
    return (b.ff - a.ff) * (b.ff - a.ff) + (b.ss - a.ss) * (b.ss - a.ss);
}

signed main(){
    sws;
    
    
    int n; cin>>n;
    vector<pii> v(n);
    int d = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    sort(v.begin(), v.end());
    set<pii> s = {{v[0].ss, v[0].ff}};
    int j = 0;
    for (int i = 1; i < n; i++) {
        int D = ceil(sqrt(d));
        while (j < i && v[j].ff < v[i].ff - D) {
            s.erase({v[j].ss, v[j].ff});
            j++;
        }

        auto l = s.lower_bound({v[i].ss - D, 0});
        auto r = s.upper_bound({v[i].ss + D, 0});
        for (auto it = l; it != r; it++) {
            d = min(d, norm({it->ss, it->ff}, v[i]));
        } 
        s.insert({v[i].ss, v[i].ff});
    }
    cout << d<< endl;
}