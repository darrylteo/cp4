#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string buf, s;
    getline(cin, buf);
    int n;
    cin >> n;
    vector<vector<string>> answers(n);
    for (int i = 0; i < n; ++i) {
        getline(cin >> ws, buf);
        stringstream ss(buf);
        while (getline(ss, s, ',')) {
            if (s[0] == ' ') {
                s.erase(0, 1);
            }
            answers[i].push_back(s);
        }
    }
    vector<int> changes(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int maxChange = 0;
            for (int k = 0; k < answers[i].size(); ++k) {
                if (answers[i][k] != answers[j][k]) {
                    maxChange++;
                }
            }
            changes[i] = max(changes[i], maxChange);
        }
    }


    for (int i = 0; i < n; ++i) {
        if (changes[i] == *min_element(changes.begin(), changes.end())) {
            for (int j = 0; j < answers[i].size() - 1; ++j) {
                cout << answers[i][j] << ", ";
            }
            cout << answers[i][answers[i].size() - 1] << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
