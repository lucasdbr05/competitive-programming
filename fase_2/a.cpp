#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define vii vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, tot; 



void fluminense(){
    cin >> n;
    vi v(n);
    tot = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        tot += v[i];
    }

    sort(v.begin(), v.end());
    int m, d, a; cin >> m;
    while (m--){
        int ans = INF ;
        cin >> d >> a;
        auto it = lower_bound(v.begin(), v.end(), d);
        if(it!= v.begin()) {
            it--;
            ans = min(ans, max(0LL, d - (int)*(it))+  max(0LL, a - (tot-(int)*(it))));
            it++;
        }
        if (it != v.end())ans = min(ans, max(0LL, a - (tot-(int)*(it))));    
        cout << ans << endl;
    }



}

int32_t main(){
    sws;    
    int T=1;
    //cin >> T;
    while(T--)fluminense(); 
    
}