#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 1e4;
const int MOD = 1e9+7;
int n;
vector<int> coins;

double h,t,ans=0;
double dp[MAX][MAX];
double prob[MAX];





int main(){
    cin >> n;

    

    for (int i=1;i<=n; i++) cin >> prob[i];

    dp[0][0]=1;

    for(int i=1; i<=n; i++){
        h = prob[i]; t= 1-prob[i];

        dp[0][i] = t*dp[0][i-1];

        for (int j=1; j<=i; j++){
            dp[j][i]= h*dp[j-1][i-1]+ t*dp[j][i-1];

        }
    }

    for (int i=n/2+1; i<=n; i++) ans+= dp[i][n];

    cout << fixed;
    cout<< setprecision(10);
    cout << ans << endl;


}