#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 10000;
const int INF= 0x3f3f3f3f;
int n, m;
int psum[MAX][MAX];
int f[MAX][MAX];
char c;


int32_t main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> c;
            f[i][j] = (c=='*')?1:0;
        }
    } 



    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            psum[i][j]+= f[i][j]+ psum[i][j-1]+ psum[i-1][j]- psum[i-1][j-1];
        }
    }  
    int ans;

    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=n; j++){
    //         cout << psum[i][j]<< " ";
    //     }
    //     cout << endl;
    // }

    
    while (m--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        
        ans  = psum[c][d]- psum[a-1][d] - psum[c][b-1]+ psum[a-1][b-1];
        cout << ans << endl;
    }
}           