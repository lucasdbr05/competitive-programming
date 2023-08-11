#include <bits/stdc++.h>

typedef long long int lli;
//typedef pair<lli,lli> ii;
#define endl "\n"
using namespace std;
 

void solve(){
    lli n, m;
    cin >> n >> m;
    multiset<lli> prices;
    for (lli i = 0; i < n; ++i){
        lli p;
        cin >> p;
        prices.insert(p);
    }

    for (lli i=0;i< m; ++i){
        lli target;
        cin>> target;

        auto it = prices.upper_bound(target);

        if (it == prices.begin()){
            cout<< -1 << endl;
            continue;
        }
        else{
            cout<< *(--it)<< endl;
            prices.erase(it);
        }
    }
}


 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
    
}
    