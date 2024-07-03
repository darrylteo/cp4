#include <bits/stdc++.h>

using namespace std;

// same as 11900 - Boiled Eggs

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N, Q;
        cin >> N >> Q;
        vector<int> weights(N);
        for (int &x: weights) cin >> x;
        sort(weights.begin(), weights.end());
        int totalWeight = 0, num = 0;
        for (int weight: weights) {
            if (totalWeight + weight <= Q) {
                totalWeight += weight;
                ++num;
            } else break;
        }
        cout << num << '\n';
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

