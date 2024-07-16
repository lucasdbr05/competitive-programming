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

void solve(){
    bool flag = false;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            char c; cin >> c;
            if(c=='a')flag = true;
        }
    }

    if(flag) cout << "SIM" << endl;
    else cout << "NAO" << endl;
    
}

signed main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)solve(); 
}