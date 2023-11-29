#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair <int, int> pii;
// typedef long long int ll;
const int MAX= 2e3+5;
const int INF= 0x3f3f3f3f;
int n, M;
char grid[MAX][MAX];
int vlin[MAX], vcol[MAX];

void solve(){
    int n; cin >> n;
    vector<int> v(n), vaux;

    int k=n-1, r=0, l=0;
    int msb=0;
    for(int i=0; i<30; i++){
        if((1<<i)&k)msb=i;
    }
    r = (1<<msb)-1;
    l = ((1<<msb)^k)+1;
    k = l+1;
    int i=0;
    while(l<r){
        v[i]=++l;
        i++;
    }
    while(k<n){
        if(i%4==0){
            v= k^(1<<msb);
            i++;
            v[i] = k;
            i++;
            k++;
        }else{
            v[i] = k;
            i++;
            v[i]= k^(1<<msb);
            
            i++;
            k++;
        }
    }

    
    
    for(int i=0; i<n; i++){
        cout << v[i]<< " ";
    }

    cout << endl;
}


int32_t main(){
    sws;
    int t; cin >> t;
    while(t--){
        solve();
    }


    
}