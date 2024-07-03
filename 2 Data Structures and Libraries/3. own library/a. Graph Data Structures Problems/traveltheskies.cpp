#include <bits/stdc++.h>

using namespace std;

struct flight {
    int from;
    int to;
    int capacity;
};

// 170 test cases poggies

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, m;
    vector<vector<flight>> flights(10); // flights[i] is day i (max 8 passengers)
    cin >> k >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, d, z;
        cin >> u >> v >> d >> z;
        flights[d].push_back({u, v, z});
    }
    // passengers[i][j] is the number of extra ppl arriving on day i at airport j
    int a, b, c;
    vector<vector<int>> passengers(10, vector<int>(15, 0));
    for (int i = 0; i < k * n; ++i) {
        cin >> a >> b >> c;
        passengers[b][a] += c;
    }
    vector<int> passengersCurrent(15, 0); // passengersCurrent[i] is the number of ppl at airport i
    bool flag = true;
    for (int day = 1; day <= n; ++day) { // for each day
        // add the new arriving passengers
        for (int i = 0; i < 15; ++i) {
            passengersCurrent[i] += passengers[day][i];
        }
        for (auto f : flights[day]) { // for each flight
            if (passengersCurrent[f.from] >= f.capacity) {
                passengersCurrent[f.from] -= f.capacity;
                passengers[day + 1][f.to] += f.capacity; // they can ride again the next day
            } else {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        cout << "optimal" << endl;
    } else {
        cout << "suboptimal" << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
