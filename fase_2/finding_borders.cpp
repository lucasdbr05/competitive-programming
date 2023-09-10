#include <bits/stdc++.h>
 
using namespace std;
#define endl '\n'
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

int main(){
    sws
    string s; cin >> s;

    vector<int> nbor = kmp(s);

    int lider = 0;


    for (int i=0; i<s.size(); i++){
        lider = nxt(nbor, s, lider, s[i]);

        
    }
    for (auto x: nbor) cout << x << " ";
    cout << endl;
    vector<int> ans;
    int aux =0;
    int i = nbor.size()-1;
    while(nbor[i]!=-1){
        aux = nbor[i]+1;
        i-= (aux);
        ans.push_back(aux);
    }

    reverse(ans.begin(), ans.end());
    for (auto x: ans) cout << x << " ";
    cout << endl;
    
}