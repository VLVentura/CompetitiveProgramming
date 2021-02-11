#include <bits/stdc++.h>

using namespace std;

#define all(X) X.begin(), X.end()

int main() {
    ios_base::sync_with_stdio(false);
    
    unordered_map<char, char> char_to_int {
        {'A', '2'}, {'B', '2'}, {'C', '2'}, {'D', '3'}, {'E', '3'}, {'F', '3'},
        {'G', '4'}, {'H', '4'}, {'I', '4'}, {'J', '5'}, {'K', '5'}, {'L', '5'},
        {'M', '6'}, {'N', '6'}, {'O', '6'}, {'P', '7'}, {'R', '7'}, {'S', '7'},
        {'T', '8'}, {'U', '8'}, {'V', '8'}, {'W', '9'}, {'X', '9'}, {'Y', '9'},
    };
    int n, size;

    cin >> n;
    while(n--) {
        cin >> size;
        string input;
        unordered_map<string, int> phones;
        unordered_set<string> phone_exists;
        priority_queue<string, vector<string>, greater<string>> repeated;
        while(size--) {
            cin >> input;
            auto it = input.begin();
            string final;
            while(it < input.end()) {
                if(isalpha(*it) && *it != 'Q' && *it != 'Z') {
                    final.push_back(char_to_int.at(*it));
                }
                else if(isdigit(*it)) {
                    final.push_back(*it);
                }
                if(final.length() == 3) {
                    final.push_back('-');
                }
                it++;
            }
            if(phone_exists.find(final) == phone_exists.end()) {
                phones.insert({final, 1});
                phone_exists.insert(final);
            }
            else {
                phones.at(final) += 1;
                if(phones.at(final) == 2) {
                    repeated.push(final); 
                }
            }
        }
        if(repeated.size() == 0) {
            cout << "No duplicates.\n";
        }
        else {
            while(!repeated.empty()) {
                string ans = repeated.top();
                cout << ans << " " << phones.at(ans) << '\n';
                repeated.pop();
            }
        }
        cout << (n == 0 ? "" : "\n");
    }
    
    return 0;
}