#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define float double
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define iii array<int, 3>
#define vpii vector<pair<int, int>>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
vpii dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n; cin >> n;
    vector<int> v;

    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            v.pb(i);
            v.pb(n/i);
        }
    }

    sort(v.begin(), v.end());

    bool flag = false;

    if(v.size()) {
        for(auto x: v){
            if(x>2 && n%(x-1)){ cout << x-1 << endl; flag = true;}
        }
    }
    if(!flag)cout << "*";

    cout << endl;
    
    
}

signed main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)solve(); 
    
}0 0 0 2 2 2
0 0 2 2 2 4
