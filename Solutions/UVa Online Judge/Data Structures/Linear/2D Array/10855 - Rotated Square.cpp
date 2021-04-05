#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

using namespace std;

#define all(X) X.begin(), X.end()

void swap_columns(vector<string> &v, int string_size) {
    int i = 0, j = string_size - 1;
    while(i < j) {
        for(int n = 0; n < (int) v.size(); ++n) {
            swap(v[n][i], v[n][j]);
        }
        i++; j--;
    }
}

void transpose(vector<string> &v, int string_size) {
    for(int i = 0; i < string_size; ++i) {
        for(int j = i; j < string_size; ++j) {
            swap(v[i][j], v[j][i]);
        }
    }
}

vector<vector<string>> get_rotations(vector<string> &vec, int string_size) {
    vector<vector<string>> rotations{vec};
    int NUM_OF_ROTATIONS = 3;
    while(NUM_OF_ROTATIONS--) {
        transpose(vec, string_size);
        swap_columns(vec, string_size);
        rotations.push_back(vec);
    }
    return rotations;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;

    while(cin >> n >> m, n || m) {
        vector<string> matrix;
        vector<string> mini;
        string input;

        cin.ignore();
        while(n--) {
            getline(cin, input);
            matrix.push_back(input);
        }
        while(m--) {
            getline(cin, input);
            mini.push_back(input);
        }
        int string_size = (int) input.size();
        auto rotated_matrixes = get_rotations(mini, string_size);

        vector<vector<string>> compare;
        for(int k = 0; k + string_size <= (int) matrix.size(); k++) {
            for(int p = 0; p + string_size <= (int) matrix.size(); p++) {
                vector<string> v;
                int i = k, times_i = string_size;
                while(times_i--) {
                    string s;
                    int j = p, times_j = string_size;
                    while(times_j--) {
                        s.push_back(matrix[i][j]);
                        j++;
                    }
                    v.push_back(s);
                    ++i;
                }
                compare.push_back(v);
            }
        }

        vector<int> sum(4, 0);
        for(int i = 0; i < (int) compare.size(); ++i) {
            vector<string> vec = compare[i];
            for(int k = 0; k < (int) rotated_matrixes.size(); ++k) {
                vector<string> matrix = rotated_matrixes[k];
                bool is_equal = true;
                for(int j = 0; j < (int) vec.size(); ++j) {
                    if(matrix[j] != vec[j]){
                        is_equal = false;
                    }
                }
                if(is_equal) {
                    sum[k]++;
                }
            }
        }

        for(int i = 0; i < (int) sum.size(); ++i) {
            cout << sum[i] << (i == (int) sum.size() - 1 ? "\n" : " ");
        }
    }

    return 0;
}
