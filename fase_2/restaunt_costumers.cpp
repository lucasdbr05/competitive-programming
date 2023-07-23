#include <bits/stdc++.h>
 
using namespace std;
typedef long long int lli;
 
typedef pair<lli, lli> ii;
using namespace std;
 

 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    lli n;
    cin >> n;
    vector<ii> v;
    for (lli i=0; i< n; i++){
        lli a,b;
        cin >> a >> b;
        
        v.push_back({a,1});
        v.push_back({b+1,-1});
    }
    

    sort(v.begin(), v.end());

    lli aux = 0, ans = 0;

    for(auto e: v){
        aux += e.second;
        ans = max(ans,aux);
    }


    cout << ans << endl;


}
    