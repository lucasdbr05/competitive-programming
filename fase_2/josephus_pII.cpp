#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
int n, k, x;
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace __gnu_pbds;

int32_t main(){
    sws;
    cin >> n >> k;
    
    ordered_set oset;
    
    for (int i=1; i<=n; i++)
        oset.insert(i);
        
    x = k%n;
    
    while(!oset.empty()){
        int aux = *oset.find_by_order(x);
        cout << aux <<" ";
        oset.erase(aux);
    
        
        if(!oset.empty()) x = (x+k)%--n;
    }
}