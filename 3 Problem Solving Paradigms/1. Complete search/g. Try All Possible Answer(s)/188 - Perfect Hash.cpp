#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string buf;
    while (getline(cin, buf)) {
        cout << buf << endl;
        vector<int> W;
        stringstream ss(buf);
        string s;

        // convert word to int
        while (ss >> s) {
            int w = 0;
            for (int i = 0; i < s.size(); ++i) {
                w = w * 32 + s[i] - 'a' + 1;
            }
            W.push_back(w);
        }

        // just follow the problem statement. they say good chose largest but no need
        int n = W.size(), C = *min_element(W.begin(), W.end()), flag = 1;
        next:
        while (flag) {
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (C / W[i] % n == C / W[j] % n) {
                        C = min((C / W[i] + 1) * W[i], (C / W[j] + 1) * W[j]);
                        goto next;
                    }
                }
            }
            flag = 0;
        }

        cout << C << endl << endl;
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}