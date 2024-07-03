#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int bestContestant, contestant = 1, maxScore = 0;
    int n;
    while (cin >> n) {
        int score = n;
        for (int i = 0; i < 3; ++i) {
            cin >> n;
            score += n;
        }
        if (score > maxScore) {
            maxScore = score;
            bestContestant = contestant;
        }
        ++contestant;
    }
    cout << bestContestant << " " << maxScore << endl;



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
