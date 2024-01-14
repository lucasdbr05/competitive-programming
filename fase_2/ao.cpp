#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair <int, int> pii;
// typedef long long int ll;
const int MAX= 1e2;
const int INF= 0x3f3f3f3f;

vector<pii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, k;

int somatorio(int x, int i){
    if (i==0) return 0;
    int aux =min(x, i);
    return aux*(2*x-(aux-1))/2;
}


bool check(int x){
    int l = max(n-k+1, 0LL);
    int r = max(k-1,0LL);
    int aux = somatorio(x, l) + somatorio(x-1, r);
    
    return aux<=m;
    
}





void solve(){
    cin >> n >> m >> k;
    int ans=0, aux = 0;
        int l=1, r=m;
        
        while(l<=r){
            int mid = (l+r)/2;
            if(check(mid)){
                ans = mid;
                l=mid+1;
            }else{
                r = mid-1;
            }
        }
        cout << ans << endl;

    
    
}


int32_t main(){
    sws;
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }


    
}


