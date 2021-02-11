#include <bits/stdc++.h>

using namespace std;

#define all(X) X.begin(), X.end()

int pos_before(int pos, vector<string> &books, unordered_map<string, bool> &is_available) {
    if(pos < 0) {
        return pos;
    }
    else if(is_available.at(books.at(pos))) {
        return pos;
    }
    return pos_before(pos - 1, books, is_available);
}

int pos_book_before(const string &book, vector<string> &books, unordered_map<string, bool> &is_available) {
    int pos = (int) (find(all(books), book) - books.begin()) - 1;
    if(pos < 0) {
        return pos;
    }
    return pos_before(pos, books, is_available);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
    
    string input;
    vector<string> books;
    unordered_map<string, string> authors;
    unordered_map<string, bool> is_available;
    
    while(getline(cin, input) && input != "END") {
        string book = input.substr(0, input.find("by") - 1);
        string author = input.substr(input.find("by") + 3);
        authors.insert({book, author});
        is_available.insert({book, true});
        books.push_back(book);
    }
    
    sort(all(books), [&] (string &b1, string &b2) {
        if(authors.at(b1) != authors.at(b2)) {
            return authors.at(b1) < authors.at(b2);
        }
        return b1 < b2;
    });
    
    vector<pair<string, string>> to_return;
    while(getline(cin, input) && input != "END") {
        string command = input.substr(0, 6);
        string book = input.substr(input.find(" ") + 1);
        if(command == "BORROW") {
            is_available.at(book) = false;
        }
        else if(command == "RETURN") {
            is_available.at(book) = true;
            to_return.push_back(make_pair(authors.at(book), book));
        }
        else {
            if(to_return.size() > 0) {
                sort(all(to_return), [&] (pair<string, string> &p1, pair<string, string> &p2) {
                    if(p1.first != p2.first) {
                        return p1.first < p2.first;
                    }
                    return p1.second < p2.second;
                });
                for(int i = 0; i < (int) to_return.size(); ++i) {
                    int pos = pos_book_before(to_return.at(i).second, books, is_available);
                    if(pos < 0) {
                        cout << "Put " << to_return.at(i).second << " first\n" ;
                    }
                    else {
                        cout << "Put " << to_return.at(i).second << " after " << books.at(pos) << "\n";
                    }
                }
                to_return.clear();
            }
            cout << "END\n";
        }
    }
    return 0;
}