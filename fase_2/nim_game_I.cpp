#include <bits/stdc++.h>
using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
#define endl '\n'
#define int long long int
const int MAX=2e5+10;

int32_t main(){
    int t; cin >> t;
    while (t--){
        int n; cin >>n;
        int ans=0;
            for (int i=0; i<n; i++){
                int a;cin >> a;
                ans ^= a;
            }
        string resp =ans>0?"first":"second";
        cout << resp << endl;
    }
    
}