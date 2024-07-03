#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// 1 if can reach, 0 if cannot reach

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    int grid[26][26];
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            grid[i][j] = 0;
        }
        grid[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        grid[a - 'a'][b - 'a'] = 1;
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                grid[i][j] |= grid[i][k] & grid[k][j];
            }
        }
    }
    for (int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;
        if (a.size() != b.size()) {
            cout << "no" << endl;
            continue;
        }
        bool can = true;
        for (int j = 0; j < a.size(); j++) {
            if (!grid[a[j] - 'a'][b[j] - 'a']) {
                can = false;
                break;
            }
        }
        if (can) cout << "yes\n";
        else cout << "no\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




