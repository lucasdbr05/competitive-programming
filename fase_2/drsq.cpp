#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair <int, int> ii;
// typedef long long int ll;
const int MAX= 2*1e5+5;
const int INF= 0x3f3f3f3f;
int n, M;
int arr[MAX];
int seg[4*MAX];

int build(int p, int l, int r){
    if (l==r) return seg[p]=arr[l];
    int m=(l+r)/2;
    return seg[p]= build(2*p,l,m)+build(2*p+1,m+1,r);
}


int query(int a, int b, int p, int l, int r){
    if (b<l or r<a) return 0;
    if (a<=l and r<=b) return seg[p];
    int m=(l+r)/2;
    return  (query(a,b,2*p,l,m)+query(a,b,2*p+1,m+1,r));
}
int update(int a, int b, int p, int l, int r){
    if (a<l or r<a) return seg[p];
    if (l==r) return seg[p]=b;
    int m=(l+r)/2;
    return seg[p]= (update(a,b,2*p,l,m)+update(a,b,2*p+1,m+1,r));
}




int32_t main(){
    sws
    cin >> n >> M;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    build(1,1,n);
    while (M--){
        int aux, a, b; cin >> aux>> a >> b;
        if (aux==1){
            update(a,b,1,1,n);
        } else{
            cout << query(a,b,1,1,n) << endl;
        }
    }
}