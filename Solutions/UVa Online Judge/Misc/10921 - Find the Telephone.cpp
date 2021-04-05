#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

using namespace std;

#define all(X) X.begin(), X.end()

int get_num(char c) {
    switch(c) {
        case 'A': case 'B': case 'C':
            return 2;
        case 'D': case 'E': case 'F':
            return 3;
        case 'G': case 'H': case 'I':
            return 4;
        case 'J': case 'K': case 'L':
            return 5;
        case 'M': case 'N': case 'O':
            return 6;
        case 'P': case 'Q': case 'R': case 'S':
            return 7;
        case 'T': case 'U': case 'V':
            return 8;
        case 'W': case 'X': case 'Y': case 'Z':
            return 9;
        default:
            return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    while(cin >> s) {
        auto it = s.begin();
        while(it < s.end()) {
            if(isalpha(*it) && *it != '-') {
                cout << get_num(*it);
            }
            else if(*it == '-' || *it == '0' || *it == '1') {
                cout << *it;
            }
            ++it;
        }
        cout << '\n';
    }

    return 0;
}
