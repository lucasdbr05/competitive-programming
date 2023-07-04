#include <bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(0);
#define endl "\n"



int main(){ sync
    
    map<int, int> mp;

    int n; cin >> n;
    vector<int> v(n), ordv(n);
    for (int i = 0; i<n; i++) {
        int x; cin>>x;
        v[i]= x;
        ordv[i]=x;
    }
    sort(ordv.begin(), ordv.end());

    for (int i = 0; i<n;i++) mp[ordv[i]]=i;
    for (int i = 0; i<n;i++) v[i]= mp[ordv[i]];

    for (int i: v) cout << i<< " ";

    cout<< endl;

}