#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli sum(vector<int> v){
    lli n=0;
    for (auto x:v) n += x;
    return n;
}

int main(){
    lli n, x;
    cin >> n >> x;
    vector<int> v(n);
    vector<int> subiu(n,1);
    
    for (lli i=0; i< n; i++) cin >> v[i];
    lli l=0,r=n-1;
    sort(v.begin(),v.end());
    lli ans=0;

    while (l<r){
        if (v[l]+v[r]>x){
            r--;
        } else {
            ans++;
            subiu[l]=subiu[r]=0;
            l++;r--;
        }
    }
    ans += sum(subiu);
    
    cout << ans << endl;
}