#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> ii;
typedef long long int ll;
const ll INF=0x3f3f3f3f3f3f3f3f;


int main(){
    int t;
    cin >> t;
    while (t--){
        ll n, x, m=-INF;
        vector<ll> a, b, c, ans;
        cin>> n;
        for (int i=0; i<n; i++) {cin >>x; a.push_back(x);}
        for (int i=0; i<n; i++) {cin >>x; b.push_back(x);}
        for (int i=0; i<n; i++) {c.push_back(a[i]-b[i]);m= max(m,c[i] );}

        for (int i=0; i<n; i++){
            if (c[i]==m) ans.push_back(i+1);
        
        }

        cout << ans.size()<<endl;
        for (auto num: ans){
            cout << num << " ";
        }
        cout << endl;
    }


    
}