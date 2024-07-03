#include <bits/stdc++.h>

using namespace std;

// not very obvious from qn but we need to print the combination of offices that give the lowest minimum distance
// from sample, 2 2 1 means there's 1 person in square 12. so having 1 office at square 12 is good enough
// we can put other offices at the lowest indices i.e. 0, 1, 2, 3 since they won't be used anyway

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        vector<vector<int>> peepo(x, vector<int>(3));
        for (int i = 0; i < x; ++i) {
            cin >> peepo[i][0] >> peepo[i][1] >> peepo[i][2];
        }

        vector<int> bestOffice(5);
        int bestSum = INT_MAX;
        for (int i1 = 0; i1 < 25; i1++) {
            for (int i2 = i1 + 1; i2 < 25; i2++) {
                for (int i3 = i2 + 1; i3 < 25; i3++) {
                    for (int i4 = i3 + 1; i4 < 25; i4++) {
                        for (int i5 = i4 + 1; i5 < 25; i5++) {
                            int sum = 0;
                            // for each 5 office combo, for each peepo, find nearest office and add to sum
                            int o1r = i1 / 5, o1c = i1 % 5;
                            int o2r = i2 / 5, o2c = i2 % 5;
                            int o3r = i3 / 5, o3c = i3 % 5;
                            int o4r = i4 / 5, o4c = i4 % 5;
                            int o5r = i5 / 5, o5c = i5 % 5;
                            for (int i = 0; i < x; ++i) {
                                int r = peepo[i][0], c = peepo[i][1], p = peepo[i][2];
                                int d1 = abs(r - o1r) + abs(c - o1c);
                                int d2 = abs(r - o2r) + abs(c - o2c);
                                int d3 = abs(r - o3r) + abs(c - o3c);
                                int d4 = abs(r - o4r) + abs(c - o4c);
                                int d5 = abs(r - o5r) + abs(c - o5c);
                                int d = min(d1, min(d2, min(d3, min(d4, d5))));
                                sum += d * p;
                            }
                            if (sum < bestSum) {
                                bestSum = sum;
                                bestOffice = {i1, i2, i3, i4, i5};
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            cout << bestOffice[i] << " ";
        }
        cout << bestOffice[4] << "\n";
    }
    
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
