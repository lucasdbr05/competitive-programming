#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
#define _ ios::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
const int INF= 0x3f3f3f3f;


int main(){_
    int t; cin>> t;
    while(t--){
        ll n, n2, aux, x;cin>> n; n2=(n*(n-1)/2);
        vector<ll> nums, ans;
        for (int i=0; i<n2; i++){
            cin>>x; nums.push_back(x);
        }
        sort(nums.begin(), nums.end());
        aux = n-1;
        ll i=0;
        while(aux>0){
            ans.push_back(nums[i]);
            i+= aux; aux-=1;
        }
        ans.push_back(1e9);

        for(ll j=0; j<n; j++){
            cout << ans[j] << " ";
        }
        cout << endl;
    }

}