#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(0);

bool cmp(ii a, ii b){
    return a.second < b.second;
    
}


int main(){_
    int t; cin >> t;

    vector<ii> v;

    for (int i=0; i< t; i++){
        int a,b; 
        cin>> a >>b; 
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), cmp);

    int ans=0;
    int fim = -1;
    for (int i =0; i<t; i++){
        if (v[i].first > fim) {fim = v[i].second; ans ++;}
    }

    cout << ans << endl;

}