#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        vector<bool> v(26);
        string s;
        getline(cin >> ws, s);
        for (char c : s) {
            if (isalpha(c)) {
                v[tolower(c) - 'a'] = true;
            }
        }
        bool pangram = true;
        for (bool b : v) {
            if (!b) {
                pangram = false;
                break;
            }
        }
        if (pangram) {
            cout << "pangram\n";
        } else {
            cout << "missing ";
            for (int i = 0; i < 26; ++i) {
                if (!v[i]) {
                    cout << (char) (i + 'a');
                }
            }
            cout << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
