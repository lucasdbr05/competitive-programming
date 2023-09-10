#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;
const int MAX = 1e5+10;
#define int long long int
typedef pair<int, int> ii;
ii items[MAX];
int memo[MAX];
int n, k, ans=0;


void dp(){
    memo[0]=0;
    for (int j=1; j<=n; j++){
        for (int i=k; i>0; i--){
            if (i>=items[j].first){
                memo[i]= max(memo[i], memo[i-items[j].first]+items[j].second);
            } else{
                break;
            }
        }
    }

}

int32_t main(){
    
    cin >> n >> k;

    for (int i=1; i<=n; i++) cin >> items[i].first >> items[i].second;
    

    
    dp();
    ans = memo[k];

    //for (int i=0; i<=k; i++) cout << memo[i]<< endl;
    cout << ans << endl;
    
}