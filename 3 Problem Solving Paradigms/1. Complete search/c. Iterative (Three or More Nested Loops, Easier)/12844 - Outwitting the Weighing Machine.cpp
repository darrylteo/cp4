#include <bits/stdc++.h>

using namespace std;

// algebra question

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << "Case " << i << ": ";
        vector<int> sums(10);
        for (int j = 0; j < 10; ++j) {
            cin >> sums[j];
        }
        vector<int> girls(5);

        // diff between 1st 2 numbers is c - b
        // diff between last 2 numbers is d - c
        // we also know that 1st number is a+b, last number is d+e

        vector<tuple<int, int, int>> abc;
        vector<pair<int, int>> de;
        int diffcb = sums[1] - sums[0], diffdc = sums[9] - sums[8];
        for (int j = 0; j < (sums[0] - 50) / 2; ++j) { // limit is cuz a <= b but search 50 to 200 also ok
            girls[0] = 50 + j;
            girls[1] = sums[0] - girls[0]; // (a+b) - a
            girls[2] = girls[1] + diffcb; // b + (c-b)
            girls[3] = girls[2] + diffdc; // c + (d-c)
            girls[4] = sums[9] - girls[3]; // (d+e) - d
            vector<int> newSums;
            newSums.push_back(girls[0] + girls[1]);
            newSums.push_back(girls[0] + girls[2]);
            newSums.push_back(girls[0] + girls[3]);
            newSums.push_back(girls[0] + girls[4]);
            newSums.push_back(girls[1] + girls[2]);
            newSums.push_back(girls[1] + girls[3]);
            newSums.push_back(girls[1] + girls[4]);
            newSums.push_back(girls[2] + girls[3]);
            newSums.push_back(girls[2] + girls[4]);
            newSums.push_back(girls[3] + girls[4]);
            sort(newSums.begin(), newSums.end());
            if (newSums == sums) {
                cout << girls[0] << " " << girls[1] << " " << girls[2] << " " << girls[3] << " " << girls[4] << "\n";
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
