#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int r, c;
    while(cin >> r >> c, r) {
        vector<vector<char>> v(c, vector<char>(r));
        for (int i = 0; i < r; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < c; j++) {
                v[j][i] = s[j];
            }
        }
        sort(v.begin(), v.end(), [](vector<char> &a, vector<char> &b) {
            for (int i = 0; i < a.size(); i++) {
                if (tolower(a[i]) != tolower(b[i])) {
                    return tolower(a[i]) < tolower(b[i]);
                }
            }
            return false;
        });
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << v[j][i];
            cout << endl;
        }
        cout << endl;
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
