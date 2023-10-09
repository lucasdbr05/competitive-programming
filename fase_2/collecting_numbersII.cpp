#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1e6+5;
const int MOD= 1e9+7;
int pos[MAX], v[MAX];

int32_t main(){
    sws;
    int n, m;cin >> n>> m;
    for (int i=1;i<=n; i++){
        cin >> v[i]; pos[v[i]]=i;
    }
    
    int ans = 1;
    for (int i=1; i<n; i++){
        if(pos[i]>pos[i+1]) ans ++;
    }
    
    int x, y;
    while(m--){
        cin >> x >> y;
        int l= v[x], r= v[y];
        swap(v[x], v[y]);
        if(pos[l]>=pos[l-1] and pos[l-1]> y) ans++;
        if(pos[l]<pos[l-1] and pos[l-1]<= y) ans--;
        if(pos[l]<=pos[l+1] and pos[l+1]< y) ans++;
        if(pos[l]>pos[l+1] and pos[l+1]>= y) ans--;
        pos[l]=y;
        if(pos[r]>=pos[r-1] and pos[r-1]> x) ans++;
        if(pos[r]<pos[r-1] and pos[r-1]<= x) ans--;
        if(pos[r]<=pos[r+1] and pos[r+1]< x) ans++;
        if(pos[r]>pos[r+1] and pos[r+1]>= x) ans--;
        pos[r]=x;
        
        cout << ans <<endl;
    }
}