#include <bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin >>t;
    while (t--){
        int n;
        cin >>n;
        vector<int> v(n);
        int c = 0;
        for (int i=0; i<n;i++){
            cin >> v[i];
        }
        vector<int> ans;
        for (int i = 1; i <n; i++){
            int aux = v[i-1]-v[i];
            c += aux;
            if (aux!=0){
                if (ans.size()>0){
                int x = ans.back();
                if (x >0 && aux >0){
                    ans.push_back(aux);
                } else if (x<0 && aux>0){
                    ans.push_back(aux);
                }
            } else{
                ans.push_back(aux);
            }
        }
    }
            cout<< ( 1+ans.size())<< endl;

        }
}