#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'

int main (){
    int n;
    cin>>n;
    vector<int> v(n,0);

    for (int i=0; i<n; ++i){
        cin>> v[i];
    }
    sort(v.begin(), v.end());
    int m = n/2;
    int median = v[m];

    lli ans = 0;
    for (int i=0; i< n; ++i){
        ans += abs(v[i]-median);
    }
    cout << ans << endl;
    return 0;
}

