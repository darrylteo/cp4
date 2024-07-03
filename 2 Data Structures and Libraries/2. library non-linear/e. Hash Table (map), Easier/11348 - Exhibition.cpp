#include <bits/stdc++.h>

using namespace std;

// more efficient method would be to record for each stamp, how many friends own it
// if only 1 friend own it, add to that friend unique count

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    for (int i = 1; i <= K; ++i) {
        cout << "Case " << i << ":";
        int N;
        cin >> N;
        vector<int> uniques(N);
        vector<unordered_set<int>> pool(N), all(N);
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            while (x--) {
                int y;
                cin >> y;
                all[j].insert(y);
                // throw this letter in stamp pool for other people to compare against later
                for (int k = 0; k < N; ++k) {
                    if (j != k) {
                        pool[k].insert(y);
                    }
                }
            }
        }
        for (int j = 0; j < N; ++j) {
            for (auto &x : all[j]) {
                if (pool[j].find(x) == pool[j].end()) { // count if cannot find compared to all other friends
                    uniques[j]++;
                }
            }
        }
        double sum = accumulate(uniques.begin(), uniques.end(), 0);
        if (sum == 0) {
            cout << " \n";
            continue;
        }
        for (int j = 0; j < N; ++j) {
            cout << " " << fixed << setprecision(6) << uniques[j]/sum*100 << "%";
        }
        cout << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
