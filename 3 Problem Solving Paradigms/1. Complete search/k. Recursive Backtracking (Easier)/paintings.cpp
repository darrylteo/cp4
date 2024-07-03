#include <bits/stdc++.h>

using namespace std;

int N, M, ans, found;
map<string, vector<string>> hideous;
vector<string> colors, newColors, bestColors;

void dfs(int idx) {
    // if previously added color is hideous, discard this set (early pruning)
    if (idx > 1) {
        if (find(hideous[newColors[idx - 1]].begin(), hideous[newColors[idx - 1]].end(), newColors[idx - 2]) != hideous[newColors[idx - 1]].end()) {
            return;
        }
    }
    if (idx == N) {
        ans++; // can use
        if (!found) {
            found = 1;
            bestColors = newColors;
        }
        return;
    }
    for (int i = 0; i < colors.size(); ++i) {
        newColors.push_back(colors[i]);
        colors.erase(colors.begin() + i);
        dfs(idx + 1);
        colors.insert(colors.begin() + i, newColors.back());
        newColors.pop_back();
    }
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        colors.clear();
        hideous.clear();
        cin >> N;
        for (int i = 0; i < N; ++i) {
            string color;
            cin >> color;
            colors.push_back(color);
        }
        cin >> M;
        for (int i = 0; i < M; ++i) {
            string color1, color2;
            cin >> color1 >> color2;
            hideous[color1].push_back(color2);
            hideous[color2].push_back(color1);
        }
        ans = 0, found = 0;
        dfs(0);
        cout << ans << '\n';
        for (string &s: bestColors) {
            cout << s << " ";
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

