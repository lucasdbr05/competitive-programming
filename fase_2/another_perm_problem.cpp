#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef pair<ll, ll> ii;

ll n;

vector<ll> calc(ll n, ll i_cur){
    vector<ll> sums;
    for (int i=0; i<n; i++){
        ll x;
        if (i_cur>i) x = (i+1)*(i+1);
        else x = (n-i+i_cur)*(i+1);
        sums.push_back(x);
    }   

    return sums;
}

ll addItems(vector<ll> &aux){
    ll s=0, m=0;
    for (int i=0; i<n; i++){
        s += aux[i];
        m = max(m, aux[i]);
    }
    return (s-m);
}

ll max_(vector<ll>ans){
    ll out=0;
    for (auto x: ans){
        out = max(out, x);
    }
    return out;
}

int main(){
    int t; cin >> t;
    while (t--){
        cin >>n;
        vector<ll> ans;
        for (int i=0; i<=n; i++){
            vector<ll> aux  = calc(n, i);
            ans.push_back(addItems(aux));
        }
        cout << max_(ans)<< endl;
    }
}