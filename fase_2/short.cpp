#include <bits/stdc++.h>
using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long int
#define ii pair<int, int>
const int MOD = 1e9+7;
const int MAX= 1e6+10;

void solve(){
    string aux = "abc";
    string s ; cin >>s;
    int c=0;
    // for (auto i=0; i<3; i++)c+= aux[i]==s[i]?1:0;

    if(aux[0]!=s[0] and aux[1]!=s[1] and aux[2]!=s[2]) cout <<"NO"<< endl;
    else cout << "YES"<< endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--)solve();
}