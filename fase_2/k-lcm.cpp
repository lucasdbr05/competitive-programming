#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
int n, k, x;
#define iii tuple<int, int, int>
const int INF=0x3f3f3f3f3f3f3f;
const int MAX=1e4+10;


int32_t main(){
    int t;cin >> t;
    while(t--){
        cin >> n >> k;
        

        if (n%2!=0) cout << 1 <<" "<< n/2<<" "<< n/2;
        if (n%4!=0) cout << 2 <<" "<< n/2-1<<" "<< n/2-1;
        else cout << 1<<" "<< 1<<" "<< 1;
    }
}