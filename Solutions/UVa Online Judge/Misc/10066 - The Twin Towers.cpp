#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

using namespace std;

#define all(X) X.begin(), X.end()

int lcs(vector<int> &first_tower, vector<int> &second_tower) {
    int size_first = (int) first_tower.size();
    int size_second = (int) second_tower.size();
    vector<vector<int>> dp(size_first + 1, vector<int>(size_second + 1));

    for(int i = 0; i <= size_first; ++i) {
        for(int j = 0; j <= size_second; ++j) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(first_tower[i - 1] == second_tower[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[size_first][size_second];
}

int main() {
    ios_base::sync_with_stdio(false);

    int m, n, c = 1;

    while(cin >> m >> n, m || n) {
        vector<int> first_tower(m), second_tower(n);
        int i = 0, j = 0;

        while(i < m) {
            cin >> first_tower[i++];
        }
        while(j < n) {
            cin >> second_tower[j++];
        }
        
        cout << "Twin Towers #" << c++ << "\nNumber of Tiles : " << lcs(first_tower, second_tower) << "\n\n";
    }

    return 0;
}
