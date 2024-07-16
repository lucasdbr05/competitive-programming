#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    for (int i = 0; i < 3; ++i) {
        string line = inf.readLine();
        ensuref(line.size() == 3, "Each line must be exactly 3 chars");

        for (char c : line) {
            ensuref(c == 'x' || c == 'o' || c == '#' || c=='a', "Invalid character in line. Only 'x', 'o', 'a' or '#' are allowed");
        }
    }
    
    inf.readEof();
}