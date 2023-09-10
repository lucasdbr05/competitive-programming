#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(0);
const int MAX = 1e6+10;
const int MOD = 1e9+7;
int nums[MAX], psum[MAX];
int aux=0, ans =0;
map<int, int> mp;



int32_t main(){
    sws
    int n,x; cin >> n>> x;

    for (int i=1; i<=n;i++){
        cin>> nums[i];
       
    }
    for (int i=0; i<=n; i++){
        aux += nums[i];
        ans += mp[aux-x];
        mp[aux]++;
    }

    

    
    cout << ans << endl;
    
    
}