#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
 
int nxt(string& s, vector<int> &nbor,int lider,char c){
    while (lider!=-1){
        //cout << s[lider+1]<<" "<<c<<endl;
        if (lider<s.size()-1 and s[lider+1]==c){
            lider++;
            break;
        }else{
            lider = nbor[lider];
        }
    }
    if (lider ==-1 and c==s[0]){
        lider++;
    }
    return lider;
}
 
 
vector<int> kmp(string s){
    int n= s.size();
    vector<int> nbor(n, -1);
 
    nbor[0]=-1;
 
 
    for (int i=1; i<n; i++){
        nbor[i]= nbor[i-1];
        nbor[i]=nxt(s, nbor, nbor[i-1], s[i]);
    }
 
    return nbor;
}
 
 
 
int main(){
    string s,p; cin >> p>> s;
 
    vector<int> nbor = kmp(s);
 
    int lider =-1, match=0;
 
    for (int i=0; i< p.size(); i++){
        lider = nxt(s,nbor,lider, p[i]);
        //cout << lider << endl;
        if (lider==s.size()-1) match++;
    }
 
    cout << match<< endl;
}