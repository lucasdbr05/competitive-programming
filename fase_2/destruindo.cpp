#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
 
lli max_num(lli a, lli b){
    if (a>b) return a;
    else return b;
}
 
int main(){
    lli n, a,b,c,x;
    cin>>n>>a>>b;
    c = round((n*b-a)/(2*(b)));
    x = 0;
 
    for (int i=-5; i<5; i++){
        if ((c+i)<=n and (c+i)>=0) x = max_num(b*(n-(c+i))*(c+i) + a*(n-(c+i)),x);
    }
    
    
    
    cout<<x<< endl;
}