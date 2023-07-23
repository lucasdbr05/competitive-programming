#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(false); cin.tie(0);

using namespace std;



int main(){_
    int n,m,k;
    cin >> n>>m>>k;
    vector<int> aps(n);
    vector<int> c(m);
    for (int i=0; i<n; i++){ cin>> aps[i];}
    for (int i=0; i<m; i++){ cin>> c[i];}
   
    sort(aps.begin(),aps.end());
    sort(c.begin(), c.end());
    

    int x=0,y=0, ans=0;
    while(x<n && y< m){
        if (c[y]-k<=aps[x] && c[y]+k>= aps[x]){
            ans++;
            x++;
            y++;
            
        } else if (c[y]+k<aps[x]){
            y++;
            
            
        } else if (c[y]-k>aps[x]){
            x++;
           
        }
    }
    cout<< ans << endl;
    
    return 0;
}