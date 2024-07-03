#include <bits/stdc++.h>

using namespace std;

vector<string> v = {"", "qaz", "wsx", "edc", "rfvtgb", " ", " ", "yhnujm", "ik,", "ol.", "p;/"};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int F, N;
    while (cin >> F >> N) {
        int cant[11] = {};
        for (int i = 0; i < F; i++) {
            int x;
            cin >> x;
            cant[x] = 1;
        }
        int can[128] = {};
        for (int i = 1; i <= 10; i++) {
            if (!cant[i]) {
                for (char c : v[i]) {
                    can[c] = 1;
                }
            }
        }
        set<string> words;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            bool ok = true;
            for (char c : s) {
                if (!can[c]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                if (words.empty() || s.size() == words.begin()->size()) {
                    words.insert(s);
                } else if (s.size() > words.begin()->size()) {
                    words.clear();
                    words.insert(s);
                }
            }
        }
        cout << words.size() << '\n';
        for (const string& word : words) {
            cout << word << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

