#include <bits/stdc++.h>

using namespace std;

// observe from sample output that only last round matters

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, tmp;
    while (cin >> n >> m, n) {
        vector<int> tickets(n); // tickets[i] = tickets bought by i-th person in last round
        int ticketsTotal = 0; // ticketsTotal = total tickets bought in last round
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j != m - 1) cin >> tmp;
                else {
                    cin >> tickets[i];
                    ticketsTotal += tickets[i];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int gcd = __gcd(tickets[i], ticketsTotal);
            cout << tickets[i] / gcd << " / " << ticketsTotal / gcd << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
