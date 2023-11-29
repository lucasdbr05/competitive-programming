#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define iii array<int, 3>
#define ff first 
#define ss second 
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

bool cmp(iii a, iii b){
    if(a[0]==b[0]) return a[1] < b[1];
    return a[0] > b[0];
 }



void solve(){
    int n; cin >> n;
    vector<iii> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1];
        v[i][2]=i+1;
    }

    sort(v.begin(), v.end(), cmp);
    int l=0, r=1, ans =0, p1=0, p2=0;
    while(l<n and r<n){
        if(l==r)r++;
        cout << l << " "<< r << " ";
        int aux1 = v[r][0]-v[l][1];
        int aux2 = v[l][0]- v[r][1];
        if(aux1>0 and aux2>0){
            if(v[l][0]+v[r][0]> ans){
                ans = v[l][0]+v[r][0];
                p1 = l; p2= r;
            }
            l++; r++;
        }
        else if(aux1>0){
            if(v[l][0]>=ans){
                ans = v[l][0];
                p1 = l, p2= r;
            }
            r++;
        }
        else if(aux2>0){
            if(v[r][0]>=ans){
                ans = v[r][0];
                p1 = l, p2= r;
            }
            l++;
        }
        else if(aux1<=0 and aux2<=0){r++;}
        cout << ans << endl;
    }
    cout << ans << endl;
    cout << v[p1][2]<< " "<< v[p1][2]<< endl;
}


int32_t main(){
    sws;
    int t=1;
    //cin >> t;
    while(t--)solve();

}