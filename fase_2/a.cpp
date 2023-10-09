#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1e3+10;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, k;


void fluminense(){

    vector<vector<int>> dp(MAX, vector<int>(MAX, 0));
    string a, b; cin>> a >> b;
    a =  " "+ a; b = " "+ b;
    int s_a = a.size(), s_b = b.size();
    
    for(int i=0; i<=s_b; i++) dp[0][i]=i;
    for(int i=1; i<=s_a; i++) dp[i][0]=dp[i-1][0]+1;
    
    
    for (int i=1; i<=s_a; i++){
        for (int j=1; j<=s_b; j++){
            if (a[i]==b[j]){
                dp[i][j]= dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
            }
        }
    }
    
    cout << dp[s_a][s_b]<< endl;
}

int32_t main(){
    
    sws;
    
    int t; cin >> t; while(t--) fluminense();
}