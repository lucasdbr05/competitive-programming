#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int find_fst(lli n, vector<lli> &v, int s){
    for (int i=0;i<s; i++){
        if(v[i]==n){ v[i]=0; return i;}
    }
    return -1;
};
int find_scn(lli n, vector<lli> &v, int s){
    for (int i=s-1;i>=0; i--){
        if(v[i]==n){ v[i]=0; return i;}
    }
    return -1;
};


int main()
{
    int n;
    lli x;
    cin >> n >> x;
    
    vector<lli> v(n);
   
    for (int i=0; i< n; i++){
        cin>> v[i];
    }
     vector<lli> copy = v;
    sort(v.begin(), v.end());
    
    int l=0, r=n-1;
    lli v1=0, v2=0;
    while(l<r){
        lli aux=v[l]+v[r];
        
        if (aux==x){
            v1=v[l];
            v2=v[r];
            break;
        }else if(aux<x){
            l++;
        } else if(aux > x){
            r--;
        }
    }
    


    if (v1!=0 && v2 !=0){
            int f = find_fst(v1, copy, n)+ 1;
            int s = find_scn(v2, copy, n)+ 1;
    
            cout<< min(f,s) << " "<< max(f,s) << endl;
        } else{
            cout << "IMPOSSIBLE"<< endl;
        }
    
    return 0;
}
