#include <bits/stdc++.h>

using namespace std;

struct game {
    int win, loss, diff;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, G;
    while (cin >> N >> G) {
        vector<game> games(N);
        for (int i = 0; i < N; ++i) {
            cin >> games[i].win >> games[i].loss;
            games[i].diff = games[i].win - games[i].loss;
        }
        sort(games.begin(), games.end(), [](const game &a, const game &b) {
            return a.diff > b.diff;
        });
        int points = 0;
        for (game g: games) {
            if (g.diff > 0) {
                points += 3;
            } else if (g.diff == 0) {
                if (G > 0) {
                    points += 3;
                    --G;
                } else {
                    ++points;
                }
            } else {
                if (G >= -g.diff + 1) {
                    points += 3;
                    G -= -g.diff + 1;
                } else if (G == -g.diff) {
                    points += 1;
                    G -= -g.diff;
                }
            }
        }
        cout << points << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

