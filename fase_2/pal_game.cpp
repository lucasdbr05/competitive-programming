#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
int n, k, x;
#define iii tuple<int, int, int>
const int INF=0x3f3f3f3f3f3f3f;

const int MAX=2e5+10;
string s;
vector<iii> aux;

int32_t main(){
    sws;
    int t; cin >> t;

    while (t--){

        cin >>x;
        cin >> s;
        int z=0, o=0;
        for (int i=0; i<x;  i++) z += (s[i]=='0');
        o=x-z;
        if (z%2==0 or z==1) cout <<"BOB"<< endl; 
        else cout <<"ALICE"<< endl; 
    }

}