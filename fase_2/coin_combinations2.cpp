#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 1e6+10;
const int MOD = 1e9+7;
int n, s, aux ,ans;
vector<int> coins;
int dp[101][MAX];
int pd[MAX];


bool cmp(int a, int b){return a>b;}

int total(int num, int idx){
    // cout << num << " "<< coins[idx]<< endl;
    if (idx<0) return 0;
    if (num<0) return 0;
    if (num ==0) return 1;
    if (dp[idx][num]!=-1) return dp[idx][num];
    dp[idx][num]=0;
    for(int i =idx; i>=0; i--){
        if (coins[i]<=coins[idx]) dp[idx][num]= (dp[idx][num] + total(num-coins[i],i))%MOD;
        
    }
    return dp[idx][num];
}


int main(){
    cin >> n >> s;
    coins.resize(n); memset(dp, -1, sizeof(dp)); memset(pd, 0, sizeof(pd));
    for (int i=0; i<n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    for (int i=0; i<n; i++) dp[i][0]=0;
    // int ans = total(s, n-1);
    // for (int i =0; i< n; i++){
    //     for (int j=0; j<=s; j++){
    //         cout << dp[i][j]<< " ";
    //     }
    //     cout << endl;
    // }
    pd[0]=1;

    for (int x: coins){
        for(int i =x; i<=s; i++){
            pd[i]= (pd[i]+pd[i-x])%MOD;
        }
    }

    ans = pd[s];
    
    cout<<ans << endl;
}