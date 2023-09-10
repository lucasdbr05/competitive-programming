#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
int n, ans=0;
vector<int> v;
bool vis[5005];

void dp(int l, int r, bool j, int qtt){
    cout <<l<< " "<< r<< " " <<"-->"<<qtt << endl;
    if (l == r){
         ans = max(ans, qtt);
         return;
    }

    if (j){
        dp(l+1,r, false, qtt+v[l]); dp(l, r-1, false, qtt+v[r]);
    }else{
        dp(l+1,r, true, qtt); dp(l, r-1, true, qtt);
    }
}

int main(){
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    dp(0, n-1, true, 0);

    cout << ans << endl;
    
}