#include <bits/stdc++.h>

using namespace std;

// finally a straightforward qns... so sad after the previous 2.
// just add a ball one by one, if cannot do on peg 1, check peg 2 etc until last peg
// if all cannot then ans is ball - 1

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v;
    for (int pegs = 1; pegs <= 50; ++pegs) {
        int ans = 0, ball = 1;
        vector<vector<int>> dp(pegs);
        while (true) {
            int i;
            for (i = 0; i < pegs; ++i) {
                if (!dp[i].empty()) {
                    double mySum = sqrt(dp[i].back() + ball);
                    if (floor(mySum) == mySum) {
                        dp[i].push_back(ball);
                        ball++;
                        break;
                    }
                } else {
                    dp[i].push_back(ball);
                    ball++;
                    break;
                }
            }
            if (i == pegs) {
                ans = ball - 1;
                break;
            }

        }
        v.push_back(ans);
    }


    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << v[x - 1] << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
