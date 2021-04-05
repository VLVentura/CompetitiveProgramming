#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

using namespace std;

#define all(X) X.begin(), X.end()

int max_rectangle(vector<int> &line) {
    stack<int> s;
    int max_area = -1, area = 0, i = 0;

    while(i < (int) line.size()) {
        if(s.empty() || line[s.top()] <= line[i]) {
            s.push(i);
            i++;
        }
        else {
            int top = s.top();
            s.pop();
            
            area = (s.empty()) ? line[top] * i : line[top] * (i - s.top() - 1);
            max_area = max(max_area, area);
        }
    }
    while(!s.empty()) {
        int top = s.top();
        s.pop();

        area = (s.empty()) ? line[top] * i : line[top] * (i - s.top() - 1);
        max_area = max(max_area, area);
    }

    return max_area;
}

int get_max_area(vector<vector<int>> &matrix) {
    vector<int> temp(matrix[0].size());
    int max_area = -1, area = 0;

    for(int i = 0; i < (int) matrix.size(); ++i) {
        for(int j = 0; j < (int) temp.size(); ++j) {
            temp[j] = (matrix[i][j] == 0) ? 0 : temp[j] + matrix[i][j];
        }
        area = max_rectangle(temp);
        max_area = max(max_area, area);
    }

    return max_area;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m, p;

    while(cin >> m >> n, n || m) {
        vector<vector<int>> matrix(m, vector<int>(n));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> p;
                matrix[i][j] = (p == 0) ? 1 : 0;
            }
        }
        cout << get_max_area(matrix) << '\n';
    }

    return 0;
}