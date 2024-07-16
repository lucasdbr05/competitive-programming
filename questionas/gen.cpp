#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

vector<string> tests;

void gen_sample()
{
    string t1, t2, t3;
    t1 = "xxx\nxoo\nooa\n";
    t2 = "x#x\nxoo\nxo#\n";
    t3 = "x#x\naoo\nxo#\n";
    tests.push_back(t1);
    tests.push_back(t2);
    tests.push_back(t3);
}

bool win(vector<string> s) {
    for (int i = 0; i < 3; i++) {
        if (s[i][0] == s[i][1] && s[i][1] == s[i][2] && s[i][0] != '#') return true;
        if (s[0][i] == s[1][i] && s[1][i] == s[2][i] && s[0][i] != '#') return true;
    }

    if (s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[1][1] != '#') return true; 
    if (s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[1][1] != '#') return true;

    return false;
}

void gen_andriley() {
    vector<pair<int, int>> v = {
        {0, 0}, {0, 1}, {0, 2},
        {1, 0}, {1, 1}, {1, 2},
        {2, 0}, {2, 1}, {2, 2},
    };

    vector<string> s = {"###", "###", "###"};

    int sz = v.size();
    pair<int, int> to_ins_and = v[(int)rnd.next(0, 1000) % sz];

    char to_ins = 'x';

    while (v.size() > 0 && !win(s)) {
        sz = v.size();
        int curr = (int)rnd.next(0, 1000) % sz;

        pair<int, int> pos = v[curr];

        s[pos.first][pos.second] = to_ins;
        v.erase(v.begin() + curr);

        to_ins = to_ins == 'x' ? 'o' : 'x';
    }

    s[to_ins_and.first][to_ins_and.second] = 'a';

    ostringstream oss;

    for (int i = 0; i < 3; i++) {
        oss << s[i] << "\n";
    }

    tests.push_back(oss.str());
}

void gen_not_andriley() {
    vector<pair<int, int>> v = {
        {0, 0}, {0, 1}, {0, 2},
        {1, 0}, {1, 1}, {1, 2},
        {2, 0}, {2, 1}, {2, 2},
    };

    vector<string> s = {"###", "###", "###"};

    int sz = v.size();

    char to_ins = 'x';

    while (v.size() > 0 && !win(s)) {
        sz = v.size();
        int curr = (int)rnd.next(0, 1000) % sz;

        pair<int, int> pos = v[curr];

        s[pos.first][pos.second] = to_ins;
        v.erase(v.begin() + curr);

        to_ins = to_ins == 'x' ? 'o' : 'x';
    }

    ostringstream oss;

    for (int i = 0; i < 3; i++) {
        oss << s[i] << "\n";
    }

    tests.push_back(oss.str());
}

void gen_tests() {
    int ini = tests.size();
    int x = 45;
    for (int i = 0; i < x; i++) {
        gen_andriley();
        gen_not_andriley();
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int test = 0;
    gen_sample();
    gen_tests();

    for (const auto &t : tests)
    {
        startTest(++test);
        string filename =  to_string(test);
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << t;
            outFile.close();
        } 
    }
    return 0;
}
