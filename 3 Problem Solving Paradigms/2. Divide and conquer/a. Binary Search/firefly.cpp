#include <bits/stdc++.h>

using namespace std;

// sort top and bot, can lower bound to see how many hit

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H;
    cin >> N >> H;
    vector<int> top(N / 2), bot(N / 2);
    for (int i = 0; i < N / 2; ++i) {
        cin >> bot[i] >> top[i];
    }
    sort(top.begin(), top.end());
    sort(bot.begin(), bot.end());

    // lower bound is greater or equal to >=
    // upper bound is greater than >
    // top obstable if reach fly, >=, cnt++. bot obstable must be greater than fly height, >, cnt++. or can H-i+1 and lower_bound
    int mn = 1e9, cnt = 0;
    for (int i = 1; i <= H; ++i) {
        int tmp = (N / 2) - (lower_bound(top.begin(), top.end(), i) - top.begin());
        tmp += (N / 2) - (upper_bound(bot.begin(), bot.end(), H - i) - bot.begin());
        if (mn == tmp) {
            ++cnt;
        } else if (mn > tmp) {
            mn = tmp;
            cnt = 1;
        }
    }
    cout << mn << " " << cnt << "\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

