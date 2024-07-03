#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // add each edge to the adjacency list
    int n, x;
    while (cin >> n, n != -1) {
        vector<set<int>> v(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> x;
                if (x == 1) {
                    v[i].insert(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            bool found = false;
            for (int j : v[i]) { // for neighbour j of i, check if it has neighbour k of j that is also neighbour of i
                for (int k : v[j]) {
                    if (v[i].find(k) != v[i].end()) {
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                cout << i << " "; // kattis doesn't care about extra spaces
            }
        }
        cout << endl;
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
