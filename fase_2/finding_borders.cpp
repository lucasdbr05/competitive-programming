#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


int nxt(vector<int>& nbor, string& s,int lider, char c){

    while(lider!=-1){
        if (lider<s.size()-1 and s[lider+1]==c){
            lider ++;
            break;
        }else{
            lider = nbor[lider];
        }
    }

    if (lider==-1 and s[0]==c){lider++;}

    return lider;
}

vector<int> kmp(string& s){
    int n = s.size();
    vector<int> nbor(n,-1);

    nbor[0]=-1;
    for (int i=1; i< n; i++){
        nbor[i]=nbor[i-1];
        nbor[i]= nxt(nbor,s,nbor[i-1],s[i]);
    }

    return nbor;

}


vector<int> P(string s){
    int k;
    vector<int> p((int)s.size()+1, -1);
    for (int i=1; i<=(int)s.size(); i++){
        k = p[i-1];
        while(k>=0 and s[i-1]!=s[k]) k = p[k];
        p[i]= k+1;
    }

    vector<int> ans;
    k = p[s.size()];

    // for(int i=0; i<= s.size(); i++) cout << p[i]<< " ";
    while(k>0){
        ans.push_back(k);
        k = p[k];
    }

    reverse(ans.begin(), ans.end());
    return ans;


}


int32_t main(){
    sws
    string s; cin >> s;

    vector<int> ans = P(s);
    
    for (auto x: ans) cout << x << " ";
    cout << endl;
    
}