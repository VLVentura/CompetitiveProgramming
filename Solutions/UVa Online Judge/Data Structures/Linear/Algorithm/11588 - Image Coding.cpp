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

    int t, cases = 1;
    cin >> t;

    while(t--) {
        int r, c, m, n, maxValue = 1;
        char in;
        map<char, int> pixelValues;
        cin >> r >> c >> m >> n;

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                cin >> in;
                if(pixelValues.find(in) == pixelValues.end()) pixelValues.insert(make_pair(in, 1));
                else {
                    pixelValues[in] += 1;
                    maxValue = max(maxValue, pixelValues[in]);
                }
            }
        }

        int sum = 0;
        for_each(all(pixelValues), [&](pair<char, int> p) { 
            if(p.second == maxValue) sum += p.second * m;
            else sum += p.second * n;
        });

        cout << "Case " << cases++ << ": " << sum << nl;
    }
    
    

    return 0;
}
