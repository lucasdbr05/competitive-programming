#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n,t;
 
 
int main(){
    cin >> n >> t;
   
    vector<lli> v(n);
    for (lli i=0; i<n; i++) {cin>> v[i];}
 
    sort(v.begin(), v.end());
    
    lli l=0, r=1e18;
 
    while (l<r){
        lli chute = (l+r)/2;
        lli p=0;
 
        for (lli i=0; i<n; i++){
            p += chute/v[i];
            if (p>t) break;
        }
 
        if (p>=t) r = chute;
        else l=chute+1;
    }
    lli ans =l;
 
    cout << ans << endl;
}