#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll val, totalCoins = 0;
    cin >> val;
    vector<ll> coins(4), vals = {1, 5, 10, 25};
    for (int i = 0; i < 4; ++i) cin >> coins[i];
    for (int i = 0; i < 4; ++i) totalCoins += coins[i];
    val = -val; // swap the problem to finding the store owner returns least number of coins
    for (int i = 0; i < 4; ++i) val += vals[i] * coins[i];
    // get min coin change using greedy (similar to page 155 in textbook mentioned about coins 1,5,10,15)
    ll best = (ll) 1e17;
    vector<ll> coinsUsed(4, 0);
    ll tmpVal = val;
    // this best value for value 25 coins but sometimes...
    // e.g. want make value 30, u have 0 0 3 1. if took 25 u end up impossible.
    // the rest are okay cuz the smaller denomination are factors of 10.
    // sanity check. if have any value of 10-24, taking the 10 cannot make it worse.
    // just check for a few values of not taking 25 is sufficient. 3 is arbitrary.
    ll good = min(val / vals[3], coins[3]);
    for (ll j = good; j >= max(0LL, good - 3); --j) {
        tmpVal = val;
        coinsUsed[3] = j;
        tmpVal -= vals[3] * coinsUsed[3];
        for (int i = 2; i >= 0; --i) {
            coinsUsed[i] = min(tmpVal / vals[i], coins[i]);
            tmpVal -= vals[i] * coinsUsed[i];
        }
        if (tmpVal == 0) best = min(best, coinsUsed[0] + coinsUsed[1] + coinsUsed[2] + coinsUsed[3]);
    }
    if (best == (ll) 1e17) cout << "Impossible" << endl;
    else cout << totalCoins - best << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}