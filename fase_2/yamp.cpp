#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll a, int b){
    ll ans = 1;
    while (b){
        ans *= a;
        b--;
    }
    return ans;
}



ll solve(ll a, ll b, string sb){
    ll size_str_b = sb.size();
    if ((b+1) == power(10,size_str_b)){
        return a*(size_str_b);
    } else{
        return a*(size_str_b -1);
    }
}


int main(){
    ll t;
    cin >> t;
    while (t--){
        ll a;
        ll b;
        cin >> a>>b;
        string sb = to_string(b);
    cout<< solve(a,b,sb)<<"\n";

    }
}