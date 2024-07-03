#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int memo[605][305]; // pos, night
vi camps;
int n, k;

// similar to prev qn uva 590 but max instead of add

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> n >> k) {
        memset(memo, 0x3f, sizeof memo);
        camps.assign(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            cin >> camps[i];
            if (i == 0) continue;
            camps[i] += camps[i - 1];
        }
        for (int i = 0; i <= n; ++i) {
            memo[i][0] = camps[i];
        }
        for (int j = 1; j <= k; ++j) { // night
            for (int i = 0; i < n; ++i) { // start of curr trek for the day
                for (int l = i + 1; l <= n; ++l) { // end
                    memo[l][j] = min(memo[l][j], max(memo[i][j - 1], camps[l] - camps[i]));
                }
            }
        }
        cout << memo[n][k] << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}