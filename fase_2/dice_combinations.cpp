#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;
const int MAX = 1e6+10;

vector<int>h;
int memo[MAX];
int n, k=6;
const int mod = 1e9+7;
void dp(){
    for (int i=1; i<=n;i++){
        for(int d=1;  d<=6; d++){
            if (d>i) continue;
            memo[i]= (memo[i] + memo[i-d])%mod;
        }
    }

}

int main(){
    _ios_;
    cin>> n;
    memset(memo, 0, sizeof memo);
    memo[0]=1;
    dp();
    cout<<memo[n]<< endl;

}