#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


bool isPal(string s){
    for (int i=0; i< s.size(); i++){
        if (s[i]!=s[s.size()-i-1]) return false;
    }
    return true;
}

void solved(string &s)
{
    lli n = s.size();
    map<char, int> ls;
    for (auto x : s)
        ls[x]++;

    string m = "";

    for (auto x : ls)
    {
        if (x.second % 2 == 1)
        {
            m += x.first*x.second;
            ls[x.first]=0;
        }
    }

    string begin = "";
    for (auto x : ls)
    {
        for (int k = 0; k < x.second / 2; k++)
        {
            begin = x.first + begin;
            ls[x.first]--;
        }
    }

    string end = "";

    for (auto x : ls)
    {
        for (int k = 0; k < x.second; k++)
        {
            end += x.first;
            ls[x.first]--;
        }
    }

    string res = begin + m + end;

    if (isPal(res)) cout << res<< endl;
    else cout<< "NO SOLUTION"<< endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    lli t, r, c, n;
    string s;
    cin >> s;
    solved(s);
    return 0;
}