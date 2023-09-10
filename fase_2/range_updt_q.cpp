#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 2*1e5+5;
const int INF= 0x3f3f3f3f;
int n, m;
int arr[MAX];
int seg[4*MAX];

int build(int p, int l, int r){
    if (l==r) return seg[p]=arr[l];
    int m=(l+r)/2;
    return seg[p]= build(2*p, l, m)+ build(2*p+1, m+1, r);
}

int update(int a, int b, int x, int p, int l, int r){
    if (a<l or r<b) return 0;
    if (l<=a and b<=r) return seg[p]+=x;
    int m=(l+r)/2;
    return seg[p]= update(a, b,x,2*p, l, m)+update(a, b,x,2*p+1, m+1,r);
}

int query(int i, int p,int l , int r){
    if (l==i and r==i) return seg[p];
    int m= (l+r)/2;
    if (r<i) return query(i,2*p, l, m);
    if (l>i) return query(i,2*p+1, m+1, r);
}


int32_t main(){
    cin >> n >> m;
    for (int i=1; i<=n;i++) cin >> arr[i];
    build(1,1,n);
    while (m--){
        int x;cin >> x;
        if (x==1){
            int a, b, c; cin >> a >> b >> c;
            update(a,b,c,1,1,n);
        }else{
            int a; cin >> a;
            cout << query(a, 1,1,n)<< endl;
        }   
    }
}