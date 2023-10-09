#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
int n, ans=0;
vector<int> v, psum;

int memo[5005][5005];
bool vis[5005][5005];

int dp(int l, int r){
    if(vis[l][r])return memo[l][r];
    if (l == r){
        return v[l];
    }
    vis[l][r]= true;
    return memo[l][r] = max(v[l]+(psum[r]-psum[l])- dp(l+1, r), v[r]+(psum[r-1]-psum[l-1])- dp(l, r-1));
}

int32_t main(){
    cin >> n;
    v.resize(n+2);psum.resize(n+2);
    for (int i = 1; i <= n; i++){
        cin >> v[i]; psum[i]= psum[i-1]+v[i];
    }
    cout << dp(1, n)<< endl;

    
}