#include <bits/stdc++.h>

using namespace std;

list<int> get_list(int n) {
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        v[i] = i + 1;
    list<int> l(v.begin(), v.end());
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    while((cin >> n), n) {
        bool run = true;
        int m = 1;
        while(run) {
            list<int> l = get_list(n);
            auto it = l.begin();
            bool stop = false;

            while(!stop) {
                if(*it == 13) {
                    stop = true;
                }
                else {
                    if(*it == l.back()){
                        auto aux = it;
                        it = l.begin();
                        l.erase(aux);
                    }
                    else {
                        it = l.erase(it);
                    }
                    for(int i = 0; i < m - 1; i++) {
                        auto aux = it;
                        aux++;
                        if(aux == l.end()) {
                            it = l.begin();
                        }
                        else {
                            it++;
                        }
                    }
                }
            }
            if(l.size() == 1) {
                cout << m << endl;
                run = false;
            }
            m++;
        }
    }

    return 0;

}
