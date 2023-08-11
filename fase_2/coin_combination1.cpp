#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 1e6+10;
const int MOD = 1e9+7;
int n, s, aux;
vector<int> coins;
int dp[MAX];
map<int, vector<int>> m;


bool cmp(int a, int b){return a>b;}

int total(int num){
    if (num<0) return 0;
    if (num ==0) return 1;
    if (dp[num]!=-1) return dp[num];
    dp[num]=0;
    for(auto x: coins){
        dp[num]= (dp[num] + total(num-x))%MOD;
    }
    return dp[num];
}


int main(){
    cin >> n >> s;
    coins.resize(n); memset(dp, -1, sizeof(dp));
    for (int i=0; i<n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end(), cmp);

    dp[0]=0;
    int ans = total(s);
    
    cout<<ans << endl;
}