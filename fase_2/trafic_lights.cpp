#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 10000;
const int INF= 0x3f3f3f3f;

int n, m, x, aux, ans=0;
set<int> s;
multiset<int> inter;

int32_t main(){
    sws
    cin >> n >> m;
     
    inter.insert(n);
    s.insert(0); s.insert(n);

    while(m--){
        cin >> x;
        
        auto it = s.upper_bound(x);
        auto r = *it;
        auto l=*--it;
        s.insert(x);
        //cout << l<< " " << r;
        inter.erase(inter.find(abs(r - l)));
        inter.insert(abs(x-l));
        inter.insert(abs(r-x));

        auto ans = *--inter.end();
        ;
        cout << ans<< " ";
    }
    cout << endl;
}           