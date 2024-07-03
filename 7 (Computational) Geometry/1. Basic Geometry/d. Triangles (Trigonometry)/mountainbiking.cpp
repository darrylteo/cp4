#include <bits/stdc++.h>

using namespace std;

// v^2 = u^2 + 2as

struct seg{
    int s, theta;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<seg> segs;
    int N;
    double g;
    cin >> N >> g;
    for (int i = 0; i < N; ++i) {
        seg s{};
        cin >> s.s >> s.theta;
        segs.push_back(s);
    }
    for (int i = 0; i < N; ++i) {
        double spd = 0;
        for (int j = i; j < N; ++j) {
            spd = sqrt(spd * spd + 2 * g * cos(segs[j].theta / 180.0 * M_PI) * segs[j].s);
        }
        cout << fixed << setprecision(9) << spd << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}