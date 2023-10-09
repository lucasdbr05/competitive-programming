#include <bits/stdc++.h>
using namespace std;
const int MAX= 2e5+10;
int n,m;
#define int long long int
#define endl '\n'
#define sws ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int arr[MAX]; 
int seg[4*MAX], lazy[4*MAX];
bool has[4*MAX];
 
int build(int id, int l, int r){
    if (l==r) return seg[id]=arr[l];
    int m =(l+r)/2;
 
    return seg[id]= build(2*id, l, m) + build(2*id+1,m+1, r);
}
 
 
void update(int l, int r, int xl, int xr, int u, int m){
    seg[u]+= lazy[u]*(r-l+1);
    if (l!= r){
        lazy[2*u]+= lazy[u];
        lazy[2*u+1]+= lazy[u];
    }
    
    lazy[u]=0;
    if(xr<l or xl>r) return;
    
    if (xl<=l&& xr>=r){
        seg[u]+= m*(l-r+1);
        if (l!= r){
            lazy[2*u]+= m;
            lazy[2*u+1]+= m;
        }
    }else{
        int mid = (l+r)/2;
        update(l,mid,xl,xr,2*u,m);
        update(mid+1,r,xl,xr,2*u+1,m);
        seg[u]=seg[2*u]+seg[2*u+1];
    }
}
 
 
int query(int u, int k,int l, int r){
    seg[u]+= lazy[u]*(r-l+1);
    if (l!= r){
        lazy[2*u]+= lazy[u];
        lazy[2*u+1]+= lazy[u];
    }
    
    lazy[u]=0;
    if(l==r) return seg[u];
    
    int mid = (l+r)/2;
    
    if(k<=mid) return query(2*u,k,l,mid);
    else return query(2*u+1,k, mid+1, r);
}
 
 
int32_t main() {
    sws
	cin >> n >> m;
	for (int i=1; i<=n; i++){ 
	    cin >> arr[i];
	}
	
	build(1,1,n);
	while (m--){
	    int x;cin >> x;
	    if (x==1){
	        int a,b,u; cin >> a >> b >> u;
	        update(1,n,a,b,1,u);
	    }else{
	        int k;cin >> k;
	        cout << query(1, k,1,n)<< endl;
	    }
	}
	
 
	return 0;
}