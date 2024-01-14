#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
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

void fluminense(){
    int n, k; cin >> n >> k;
    vector<string> v(n);
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        for(int j=0; j<k; j++){
            if(v[i][j]=='1'){
                a[i]|=(1<<(k-j-1));
            }
        }
    }

    int ans = 31;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ans = min(ans, (int)__builtin_popcountll((int)(a[i]^a[j])));
        }
    }

    cout << ans << endl;


    
}

int32_t main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)fluminense(); 
    
}