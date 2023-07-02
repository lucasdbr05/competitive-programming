#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0), res(n,0); 

    for (int i = 0; i<n;i++) cin>>v[i];
    
    stack<pair<int, int>> st;
    for (int i = 0; i<n;i++){
        while(st.size() && (st.top()).first>= v[i]){
            st.pop();
        }

        
        if (st.size()>0){
            res[i]= (st.top()).second;
        }
        st.push({v[i],i+1});
    }

    for (auto i: res) cout << i<< " ";
}