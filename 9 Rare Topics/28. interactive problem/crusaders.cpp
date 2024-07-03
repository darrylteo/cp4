#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// log2(1e6) = 20. given up to 106 ponies. not feasible to naive bsta
// we can try to keep track of all the known cities and bsta within a range
// be careful test case has negative values
// extremely tight bounds on question!!!
// could only get up to test 9/12 before reading ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_9_Rare_Topics/9.31_Interactive_Problem/kattis_crusaders.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int C, A, d = 1500;
    cin >> C >> A;
    vector<int> ponies(A); // pony wages. we will process them in any order
    vector<int> p(A, -1); // assignment of ponies to cities. everypony should be assigned a city
    for (int i = 0; i < A; i++) cin >> ponies[i];
    set<pair<int, int>> cities; // cost, idx
    unordered_map<int, int> px; // city idx, cost

    // cost of first and last city
    cities.insert({-1, 1});
    px[1] = -1;
    cout << "Q " << C << endl << flush;
    int res;
    cin >> res;
    cities.insert({res, C});

    for (int i = 0; i < A; ++i) { // assume each city can take infinite ponies
        int l, r;
        if (cities.lower_bound({ponies[i], 0})->first > ponies[i]) {
            r = cities.lower_bound({ponies[i], 0})->second - 1;
        } else {
            r = cities.lower_bound({ponies[i], 0})->second;
        }
        l = (--cities.upper_bound({ponies[i], 0}))->second;

        while (l < r) {
            int m = (l + r + 1) / 2;

            int cost;
            if (px.find(m) == px.end()) {
                d--;
                assert(d >= 0);
                cout << "Q " << m << endl << flush;
                cin >> cost;
                px[m] = cost;
                cities.insert({cost, m});
            } else {
                cost = px[m];
            }

            if (cost == ponies[i]) {
                l = r = m;
                break;
            }

            if (cost < ponies[i]) l = m;
            else r = m - 1;
        }
        p[i] = l;
    }
    string ans = "A";
    for (int i = 0; i < A; ++i) ans += " " + to_string(p[i]);
    cout << ans << endl << flush;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
