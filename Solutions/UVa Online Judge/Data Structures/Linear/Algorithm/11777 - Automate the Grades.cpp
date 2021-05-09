#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

using namespace std;

using ll = long long;

#define all(X) X.begin(), X.end()

char getGrade(int n) {
    if(n >= 90) return 'A';
    else if(n >= 80) return 'B';
    else if(n >= 70) return 'C';
    else if(n >= 60) return 'D';
    else return 'F';
}

int main() {
    ios_base::sync_with_stdio(false);

    int t, c = 1, term1 = 0, term2 = 0, _final = 0, attendece = 0, ct1 = 0, ct2 = 0, ct3 = 0;
    cin >> t;

    while(t--) {
        priority_queue<int> pq;
        int sumct = 0;
        cin >> term1 >> term2 >> _final >> attendece >> ct1 >> ct2 >> ct3;
        pq.push(ct1); pq.push(ct2); pq.push(ct3);
        for(int i = 0; i < 2; ++i) {
            sumct += pq.top();
            pq.pop();
        }
        sumct /= 2;
        cout << "Case " << c++ << ": " << getGrade(term1 + term2 + _final + attendece + sumct) << '\n';
    }

    return 0;
}
