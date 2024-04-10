#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define iii array<int, 3>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f
3f3f3f;
int arr[MAX];
int seg[4*MAX];
 
int build(int p, int l, int r){
    if (l==r) return seg[p]=INF;
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
 


void fluminense(){
    
    int n; cin >> n;
    vector<int> v(i);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    map<int, int> mp;

    for(int i = n-1; i>=0; i--){
        
    }
}

int32_t main(){
    sws;    
    int T=1;
    cin >> T;
    while(T--)fluminense(); 
    
}