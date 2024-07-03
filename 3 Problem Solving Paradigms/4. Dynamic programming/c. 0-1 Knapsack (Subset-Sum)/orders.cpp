#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll N, V, coinValue[105], memo[105][30005];
vector<int> coins;

ll ways(int type, ll value) {
    if (value == 0) return 1;                      // one way, use nothing
    if ((value < 0) || (type == N)) return 0;      // invalid or done
    ll &ans = memo[type][value];
    if (ans != -1) return ans;                     // was computed before
    return ans = ways(type+1, value) +             // ignore this type
                 ways(type, value-coinValue[type]);// one more of this type
}

void getCoins(int type, ll value) {
    if (value == 0) return;
    if (ways(type+1, value) > 0) { // u made it without using this coin
        getCoins(type+1, value);
    } else {
        coins.push_back(type + 1);
        getCoins(type, value-coinValue[type]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> coinValue[i];
    }
    int m;
    cin >> m;
    memset(memo, -1, sizeof memo); // important not to clear everytime since coin values are fixed
    while (m--) {
        cin >> V;
        ll w = ways(0, V);
        if (w == 0) cout << "Impossible\n";
        else if (w > 1) cout << "Ambiguous\n";
        else {
            coins.clear();
            getCoins(0, V);
            for (int i=0;i<(int)coins.size();i++){
                cout << coins[i] << ((i != (int) (coins.size() - 1)) ? ' ' : '\n');
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}