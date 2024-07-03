#include <bits/stdc++.h>

using namespace std;

int dirr8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dirc8[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<string> grid(4);
string word;

inline int dfs(int pos, int r, int c) {
    if (pos == word.size()) return 1;
    if (r < 0 || r >= 4 || c < 0 || c >= 4) return 0;
    if (grid[r][c] != word[pos]) return 0;
    char ch = grid[r][c];
    grid[r][c] = '*';
    for (int i = 0; i < 8; i++) {
        if (dfs(pos + 1, r + dirr8[i], c + dirc8[i])) {
            grid[r][c] = ch;
            return 1;
        }
    }
    grid[r][c] = ch;
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) cin >> dict[i];

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 4; i++) {
            cin >> grid[i];
        }
        int Q, score = 0, wordCnt = 0, longestWordLen = 0;
        vector<string> longestWords;
        for (const string& d: dict) {
            word = d;
            bool found = false;
            for (int i = 0; i < 4 && !found; i++) {
                for (int j = 0; j < 4 && !found; j++) {
                    if (grid[i][j] == word[0]) {
                        if (dfs(0, i, j)) {
                            found = true;
                        }
                    }
                }
            }
            if (found) {
                if (word.size() == 3 || word.size() == 4) score += 1;
                else if (word.size() == 5) score += 2;
                else if (word.size() == 6) score += 3;
                else if (word.size() == 7) score += 5;
                else if (word.size() >= 8) score += 11;
                wordCnt++;
                if (word.size() > longestWordLen) {
                    longestWordLen = word.size();
                    longestWords.clear();
                    longestWords.push_back(word);
                } else if (word.size() == longestWordLen) {
                    longestWords.push_back(word);
                }
            }
        }
        sort(longestWords.begin(), longestWords.end());
        cout << score << " " << longestWords[0] << " " << wordCnt << '\n';

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


