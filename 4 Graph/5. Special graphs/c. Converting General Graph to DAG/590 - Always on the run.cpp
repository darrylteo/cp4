#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int memo[15][1005]; // city, days used (aka flight cnt). record best cost to get here
vi schedule[15][1005]; // city from, city to
int n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1;
    while (cin >> n >> k >> ws, n) {
        memset(memo, 0x3f, sizeof memo);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                schedule[i][j].clear();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                string buf;
                getline(cin, buf);
                stringstream ss(buf);
                int x;
                while (ss >> x) {
                    schedule[i][j].push_back(x);
                }
            }
        }
        // begin bottom up dp
        memo[0][0] = 0;
        for (int day = 1; day <= k; day++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    int costIdx = (day - 1) % schedule[i][j][0] + 1;
                    int cost = schedule[i][j][costIdx];
                    if (cost == 0) continue;
                    memo[j][day] = min(memo[j][day], memo[i][day - 1] + cost);
                }
            }
        }

        cout << "Scenario #" << cases++ << '\n';
        if (memo[n-1][k] == 0x3f3f3f3f) {
            cout << "No flight possible.\n\n";
        } else {
            cout << "The best flight costs " << memo[n-1][k] << ".\n\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}