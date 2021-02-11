#include <bits/stdc++.h>

using namespace std;

#define all(X) X.begin(), X.end()

int main() {
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    while(n--) {
        unordered_map<char, int> values;
        int i = 0, k = 0, m = 0; 
        char c;
        cin >> k;
        while(k--) {
            cin >> c >> i;
            values.insert({c, i});
        }

        string input, buffer = "";
        cin >> m;
        while(getline(cin, input) && m--) {
            buffer += input;
        }
        buffer += input;
        
        int payment = 0;
        auto begin = buffer.begin();
        auto end = buffer.end() - 1;
        while(begin <= end) {
            (values.find(*begin) != values.end()) ? payment += values.at(*begin) : payment = payment;
            if(begin != end){
                (values.find(*end) != values.end()) ? payment += values.at(*end) : payment = payment;
            }
            begin++; end--;
        }
        cout << fixed << setprecision(2) << (double) payment / 100 << "$" << '\n';
    }

    return 0;
}