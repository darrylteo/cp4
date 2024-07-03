#include <bits/stdc++.h>

using namespace std;

// simplified version of 00592 - Island of Logic
// just check whether current case is possible or not
// if 0 indexed should take half the time

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int i, a;
    while (cin >> i >> a, i || a) {
        vector<pair<int, int>> answers;
        int x, y;
        for (int j = 0; j < a; ++j) {
            cin >> x >> y;
            answers.emplace_back(x, y);
        }

        // check all combinations
        // 1 indexed
        int max_informants = 0;
        for (int j = 0; j < (1 << (i + 1)); ++j) {
            bitset<21> current(j); // 1 for reliable, 0 for unreliable. 1 indexed
            bool possible = true;
            for (auto &answer: answers) {
                if (current[answer.first]) { // left guy is reliable. if left guy unreliable nothing check
                    if (answer.second > 0 &&
                        !current[answer.second]) { // left guy says right guy is reliable but he is unreliable
                        possible = false;
                        break;
                    } else if (answer.second < 0 &&
                               current[-answer.second]) { // left guy says right guy is unreliable but he is reliable
                        possible = false;
                        break;
                    }
                }
            }

            if (possible) {
                int count = current.count();
                if (count > max_informants) {
                    max_informants = count;
                }
            }
        }
        cout << max_informants - 1 << endl; // for index 0
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}