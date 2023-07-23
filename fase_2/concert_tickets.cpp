#include <bits/stdc++.h>
 
using namespace std;
typedef long long int lli;
 
typedef pair<lli, lli> ii;
using namespace std;
 

 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    lli a,b;
    cin>>a>>b;
    lli l=0, r=a-1;
    vector<lli> t(a,0), p(b,0);
    vector<bool>can(a,true);

    for (lli i =0; i<a;i++) {cin>> t[i];}
    for (lli i =0; i<b;i++){cin>> p[i];}

    sort(t.begin(),t.end());

        
    for (lli e: p){
        cout << e<< " ";
        lli m;
        while(l<r){
            m = (l+r)/2;
            //cout << m << " ";
            if (t[m]>=e){
                r=m-1;
            }else if (t[m]<e){
                l=m+1;
            }
        }

        cout << t[m] << endl;
    }

    return 0;

}
    