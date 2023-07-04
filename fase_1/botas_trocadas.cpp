#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false);cin.tie(0);
#define endl '\n'
#define f first
#define s second 

int main(){ _ 
    int t;
    cin>> t;
    vector<pair<int, int>> botas(61,{0,0});
    while(t--){
        int tam;
        char l;

        cin >> tam >> l;
       
        if (l=='D'){
            botas[tam].s ++;
        }else{
            botas[tam].f ++;
        }

    }
    int ans = 0;

    for (auto i :botas){
            ans += min(i.f, i.s);
        }
    cout<< ans << endl;

    return 0;
}
