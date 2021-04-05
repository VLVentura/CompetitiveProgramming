#include <bits/stdc++.h>

using namespace std;

#define all(X) X.begin(), X.end()

int main() {
    ios_base::sync_with_stdio(false);
    
    string input;
    vector<string> index, values;
    int n;
    bool is_index = true;

    cin >> n;
    while(getline(cin, input)) {
        if(input.empty()) continue;
        
        if(is_index) {
            index.push_back(input);
        }
        else {
            values.push_back(input);
        }
        is_index = !is_index;
    }
    
    stringstream buffer;
    queue<string> order;
    int i = 0;

    while(i < n) {
        int j = 2;
        unordered_map<string, string> map;
        priority_queue<int> pq;
        while(j--) {
            if(j == 1) {
                input = index.at(i);
            }
            else {
                input = values.at(i);
            }
            buffer << input;
            while(getline(buffer, input, ' ')) {
                if(j == 1) {
                    order.push(input);
                    map.insert({input, ""});
                    pq.push(-stoi(input));
                }
                else {
                    map.at(order.front()) = input;
                    order.pop();
                }
            }
            buffer.clear();
        }
        while(!pq.empty()) {
            string ans = to_string(-pq.top());
            cout << map.at(ans) << '\n';
            pq.pop();
        }
        map.clear();
        cout << (i == n - 1 ? "" : "\n");
        i++;
    }

    return 0;
}
