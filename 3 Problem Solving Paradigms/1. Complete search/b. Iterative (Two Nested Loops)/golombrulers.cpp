#include <bits/stdc++.h>

using namespace std;

// O(n^2) get all n^2 differences and mark them as true

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    string buf;
    next:
    while (getline(cin, buf)) {
        stringstream ss(buf);
        bool dist[2005] = {}; // mark true when we can measure this distance
        vector<int> v;
        int n;
        while (ss >> n) {
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                if (dist[v[j] - v[i]]) {
                    cout << "not a ruler" << endl;
                    goto next;
                }
                dist[v[j] - v[i]] = true;
            }
        }
        vector<int> missing;
        for (int i = 1; i <= v.back(); ++i) {
            if (!dist[i]) {
                missing.push_back(i);
            }
        }
        if (missing.empty()) {
            cout << "perfect\n";
        } else {
            cout << "missing ";
            for (int i = 0; i < missing.size(); ++i) {
                cout << missing[i] << (i == missing.size() - 1 ? "\n" : " ");
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
