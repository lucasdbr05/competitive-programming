#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sws ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
vector<int> ans;
 
 
int main(){
    int n; cin>> n;
    vector<int> v;
    for (int i=0; i<n; i++){
        v.push_back(i+1);
    }
 
    while(v.size()>1){
        vector<int> aux;
        for (int i=0; i<v.size(); i++){
            if(i%2) {
                ans.push_back(v[i]);
            }else{
                aux.push_back(v[i]);
            }
        }
        if (v.size()%2){
            v.clear();
            v.push_back(aux.back()); aux.pop_back();
            for (auto i: aux) v.push_back(i);
 
        }else{
            v = aux;
        }
    }

    if(v.size()==1) {ans.push_back(v[0]); v.pop_back();}
    
    for(auto num: ans) cout << num << " ";
    cout << endl;
}