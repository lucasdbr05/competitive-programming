#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
int n, u, f, m;
double memo[1000][1000];
double poss[1000][1000];
bool vis[1000][1000];


const int MOD = 1e9+7;
const int MAX = 1e6+5;

double dp(int coins, int past){
    if(coins==m) return 1;
    if (vis[coins][past]) return memo[coins][past];

    for(int i=0;i<n;i++){
        if(i!=f){
            memo[coins][past] += dp(coins+1, i)*poss[past][i];
        }
    }
    vis[coins][past]=true;
    return  memo[coins][past];
}

int32_t main(){
    sws;

    cin>> n >> u >> f >> m;
    for (int i=0; i<n;i++){
        for (int j=0; j<n; j++){
            cin >> poss[i][j];
        }
    }

    cout << dp(0, u)<< endl;
    return 0;
}