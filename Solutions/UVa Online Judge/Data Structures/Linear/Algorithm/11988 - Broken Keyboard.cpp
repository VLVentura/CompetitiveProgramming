#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#endif

using namespace std;

#define ll long long;
#define nl '\n'

#define all(X) X.begin(), X.end()

int main() {
    ios_base::sync_with_stdio(false);

    string input;
    while(cin >> input) {
        list<char> l;
        auto it = l.begin();
        for_each(all(input), [&] (char &c) {
            if(c == '[') it = l.begin();
            else if(c == ']') it = l.end();

            if(c != '[' && c != ']') {
                l.insert(it, c);
            }
        });
        for_each(all(l), [] (char &c) {cout << c;});
        cout << nl;
    }

    return 0;
}
