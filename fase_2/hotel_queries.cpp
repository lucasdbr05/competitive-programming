#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 2e5+5;
const int MOD= 1e9+7;
const int INF = 1e18+1;
int n, m, ans;
int arr[MAX], seg[4*MAX], r[MAX];


int query(int i, int l, int r, int val){
    if(r<l) return 0;
    if(l==r) return l;
    int mid = (l+r)/2;
    auto x = seg[2*i]>=val ? query(2*i, l, mid, val):query(2*i+1, mid+1, r, val);
    return x;
}

void update(int i, int l, int r, int val, int k){
    if(l==r){seg[i]=val;return;}
    int mid = (l+r)/2;
    if(k<=mid) update(2*i, l, mid, val, k);
    else update(2*i+1, mid+1, r, val, k);
    seg[i] = max(seg[2*i], seg[2*i+1]);
}



int build(int i, int l, int r){
    if(l==r) return seg[i]= arr[l];
    int mid = (l+r)/2;
    return seg[i] = max(build(2*i, l, mid), build(2*i+1, mid+1, r));
}

int32_t main(){
    sws;

    cin >> n >> m;

    for(int i=1;i<=n; i++) cin >> arr[i];
    for(int i=1;i<=n; i++) cin >> r[i];

    build(1, 1, n);
    // for (int i=0; i<=4*n; i++) cout << seg[i]<< " ";

    for(int i=1; i<=m; i++){
        int aux = r[i];
        if(seg[1]< aux) cout << 0 << " ";
        else{
            ans = query(1, 1, n, aux);
            cout << ans << " ";
            arr[ans]-=aux;
            update(1, 1, n, arr[ans], ans);
        }
    }



    

}