#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair <int, int> ii;
// typedef long long int ll;
const int MAX= 2*1e5+5;
const int INF= 0x3f3f3f3f;
int n, ans=0;



int32_t main(){
    sws
    cin >> n;
    vector<int> v(n), lis;
    for (int i=0;i<n;i++){
        cin >> v[i];
    }

    for (int i=0; i<n; i++){
        auto low = lower_bound(lis.begin(), lis.end(), v[i]);
        if (low == lis.end()) lis.push_back(v[i]);
        else lis[low-lis.begin()]= v[i];
    }
    ans = lis.size();
    cout << ans << endl;




}