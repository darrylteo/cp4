#include <bits/stdc++.h>

using namespace std;

struct sale {
    int price;
    int qty;
};

vector<vector<sale>> sales;
int dp[53][301], S, W; // dp[week][seatsRemaining] = minPrice (for this week)

int solve(int week, int seatsRemaining) {
    if (week == W || seatsRemaining == 0) return 0;
    int &ans = dp[week][seatsRemaining];
    if (ans != -1) return ans;
    ans = 0; // find best price for this week
    for (int i = 0; i < sales[week].size(); i++) {
        int price = sales[week][i].price;
        int qty = sales[week][i].qty;
        if (qty >= seatsRemaining) {
            ans = max(ans, price * seatsRemaining); // sell all seats at this price
        } else {
            ans = max(ans, price * qty +
                           solve(week + 1, seatsRemaining - qty)); // sell some here, continue checking next weeks
        }
    }
    return dp[week][seatsRemaining] = ans;
}

// every week u must choose a price from 1 of given price. i thought first week could just don't sell... but that's incorrect

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> S >> W;
    W++;
    sales.resize(W);
    for (int i = 0; i < W; i++) {
        int n;
        cin >> n;
        sales[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> sales[i][j].price;
        }
        for (int j = 0; j < n; j++) {
            cin >> sales[i][j].qty;
        }
    }
    memset(dp, -1, sizeof(dp));
    int best = solve(0, S);

    // quick method
    int bestPrice = 0;
    for (auto & i : sales[0]) {
        int price = i.price;
        int qty = i.qty;
        if (solve(1, S - qty) + price * qty == best) {
            bestPrice = price;
            break;
        }
    }
    cout << best << '\n' << bestPrice << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


