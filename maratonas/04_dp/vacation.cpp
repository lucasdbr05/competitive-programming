#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;
const int MAX = 1e5+10;
typedef pair<int, int> ii;
int vac[MAX][5];
int memo[MAX][5];
int n, k, ans=0;


void dp(){
    ii cols[3] = {{2,3}, {1,3}, {1,2}};
    for (int i=1; i<=n; i++){
        for (int j=1; j<=3; j++){
            memo[i][j] = vac[i][j]+max(memo[i-1][cols[j-1].first], memo[i-1][cols[j-1].second]);
        }
    }

    for (int i = 1; i<=3; i++){
        ans = max(memo[n][i], ans);
    }

}

int main(){
    cin >> n ;
    for(int i=1; i<=n; i++){
        for (int j=1; j<=3; j++) cin>>vac[i][j];
    }

    
    dp();
    cout << ans << endl;
    
}