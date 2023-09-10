#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(0);
const int MAX =2e5+10;
int total=0, ans =0, n;

int nums[MAX];
map<int, int> mp;


int32_t main(){
    cin >> n;

    for(int i=1; i<=n; i++) cin >> nums[i];
    ++mp[0];
    for (int i=1; i<=n; i++){
        total += nums[i]%n;
        total = (total+n)%n;
        ans +=  mp[total];
        mp[total]++;
        cout << total << endl;
    }

    cout << ans<< endl;

}