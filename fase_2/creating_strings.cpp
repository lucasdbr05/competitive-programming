#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define endl "\n"

int main(){
    string  x;
    vector<string> v;
    cin >>x;

    sort(all(x));

    do {
        v.push_back(x);
    } while(next_permutation(all(x)));

    cout<<v.size()<< endl;

    for (string y:v) cout<<y<<endl;
}