#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// check if we throw away (aka put aside and pair) all weight x and below, are the rest paired?

bool isValid(vector<ll> &rack, ll x) {
    // given x, if we find a weight that is larger than x, continue to find the matching weight
    // if we encounter a larger than x weight (and not paired), or reach end of vector, it is invalid
    for (int i = 0; i < rack.size(); i++) {
        if (rack[i] <= x) continue;
        bool found = false;
        for (int j = i + 1; j < rack.size(); j++) {
            if (rack[i] == rack[j]) { // paired
                found = true;
                i = j;
                break;
            }
            if (rack[j] > x) return false; // blocking
        }
        if (!found) return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> top(n), bot(n);
    for (ll &i: top) cin >> i;
    for (ll &i: bot) cin >> i;
    ll l = 0, r = INT_MAX, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (isValid(top, mid) && isValid(bot, mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
