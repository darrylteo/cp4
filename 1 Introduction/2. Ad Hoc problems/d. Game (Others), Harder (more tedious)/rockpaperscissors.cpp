#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, k;
    cin >> n >> k;
    while (n) {
        int p1, p2, games;
        double wins[101] = {0}, losses[101] = {0};
        string move1, move2;
        games = n * k * (n - 1) / 2;
        for (int i = 0; i < games; ++i) {
            cin >> p1 >> move1 >> p2 >> move2;
            if (move1 == move2) continue;
            if (move1 == "rock") {
                if (move2 == "scissors") {
                    wins[p1]++;
                    losses[p2]++;
                } else if (move2 == "paper") {
                    wins[p2]++;
                    losses[p1]++;
                }
            } else if (move1 == "paper") {
                if (move2 == "rock") {
                    wins[p1]++;
                    losses[p2]++;
                } else if (move2 == "scissors") {
                    wins[p2]++;
                    losses[p1]++;
                }
            } else if (move1 == "scissors") {
                if (move2 == "paper") {
                    wins[p1]++;
                    losses[p2]++;
                } else if (move2 == "rock") {
                    wins[p2]++;
                    losses[p1]++;
                } else {}
            }
        }
        for (int j = 1; j <= n; ++j) {
            if (wins[j] + losses[j] != 0) {
                printf("%.3f\n", wins[j] / (wins[j] + losses[j]));
            } else {
                printf("-\n");
            }
        }
        cin >> n >> k;
        if (n) cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

