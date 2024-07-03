#include <bits/stdc++.h>

using namespace std;

//P(buy, don't buy)
//P(AB, C) = 0.1*0.2*0.7 = 0.014
//P(BC, A) = 0.9*0.2*0.3 = 0.054
//P(AC, B) = 0.1*0.8*0.3 = 0.024
//
//P(A) = 0.038/0.092 = 0.413043
//P(B) = 0.068/0.092 = 0.739130
//P(C) = 0.078/0.092 = 0.847826

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, r, cases = 1;
    while (cin >> N >> r, N) {
        cout << "Case " << cases++ << ":\n";
        vector<double> probs(N), cumProbs(N);
        for (int i = 0; i < N; i++) cin >> probs[i];

        // to permutate and see which we buy
        vector<int> buy(N);
        for (int i = 0; i < r; i++) buy[i] = 1;
        sort(buy.begin(), buy.end());

        double sumProbs = 0;
        while (true) {
            double p = 1;
            for (int i = 0; i < N; i++) {
                if (buy[i]) p *= probs[i];
                else p *= (1 - probs[i]);
            }
            sumProbs += p;
            for (int i = 0; i < N; i++) {
                if (buy[i]) cumProbs[i] += p;
            }
            if (!next_permutation(buy.begin(), buy.end())) break;
        }

        for (int i = 0; i < N; i++) {
            cout << fixed << setprecision(6) << cumProbs[i] / sumProbs << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


