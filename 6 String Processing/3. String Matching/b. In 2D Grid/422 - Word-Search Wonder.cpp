#include <bits/stdc++.h>

using namespace std;

int dirr8[] = {0, 0, 1,  1, -1, 1, -1};
int dirc8[] = {1, -1, 0, 1, -1, -1, 1};

// kinda weird that words can't go upwards

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
        transform(grid[i].begin(), grid[i].end(), grid[i].begin(), ::toupper); // convert to uppercase
    }

    string s;
    done:
    while (cin >> s, s != "0") {
        transform(s.begin(), s.end(), s.begin(), ::toupper); // convert to uppercase
        int n = s.size();
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == s[0]) {
                    for (int i = 0; i < 7; i++) {
                        int r1 = r, c1 = c;
                        bool found = true;
                        for (int j = 1; j < n; j++) {
                            r1 += dirr8[i];
                            c1 += dirc8[i];
                            if (r1 < 0 || r1 >= N || c1 < 0 || c1 >= N || grid[r1][c1] != s[j]) {
                                found = false;
                                break;
                            }
                        }
                        if (found) {
                            cout << r + 1 << "," << c + 1 << " " << r1 + 1 << "," << c1 + 1 << '\n';
                            goto done;
                        }
                    }
                }
            }
        }
        cout << "Not found\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


