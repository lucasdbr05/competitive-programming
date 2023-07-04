#include <bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false); cin.tie(0);
#define endl "\n"


int main(){_ 
    string joia;
    set<string> tesouro;
    while(cin>>joia){
        tesouro.insert(joia);
    }

    cout << tesouro.size()<<endl;
}