#include <bits/stdc++.h>

using namespace std;

struct ride {
    int a, b, t;
};

int N, Q;
int memo[105][25005]; // rides considered, time left
int memoB0[25005]; // time left
vector<ride> rides, ridesB0, ridesB1; // rides with b==0, b!=0
vector<vector<int>> funs;

inline int dpB0(int T) {
    int &ans = memoB0[T];
    if (ans != -1) return ans;

    ans = 0;
    for (ride r : ridesB0) {
        if (T - r.t >= 0) ans = max(ans, dpB0(T - r.t) + r.a);
    }

    return memoB0[T] = ans;
}

inline int dp(int i, int T) {
    if (i == ridesB1.size()) return dpB0(T);
    if (memo[i][T] != -1) return memo[i][T];

    int ans = dp(i + 1, T); // skip the ride
    ride r = ridesB1[i];
    int cnt = 1;
    while (T - r.t * cnt >= 0) {
        ans = max(ans, dp(i + 1, T - r.t * cnt) + funs[i][cnt - 1]);
        cnt++;
        if (cnt > funs[i].size()) break;
    }

    return memo[i][T] = ans;
}

void initFuns() {
    for (int i = 0; i < ridesB1.size(); i++) {
        int fun, cnt = 1;
        ride r = ridesB1[i];
        while (cnt * r.t <= 25000) {
            fun = r.a - (cnt - 1) * (cnt - 1) * r.b;
            if (fun < 0) break;
            funs[i].push_back(fun + (cnt > 1 ? funs[i].back() : 0));
            cnt++;
        }
    }
}

// important part of question. it's the number of times he take the ride, no need consecutive.
// so we just test all possible number of times he can take the ride.
// optimized the funs a little by doing cumsum
// follow clue to split the b==0 and b!=0 cases.
// because fun rapidly decreases for b!=0 cases, but when b==0, if time for ride is 1, it breaks algo when T==25000.
// at while (t - r.t * cnt >= 0) { ... }

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N;
    rides.resize(N);
    funs.resize(N);
    for (int i = 0; i < N; i++) cin >> rides[i].a >> rides[i].b >> rides[i].t;
    for (ride r : rides) {
        if (r.b == 0) ridesB0.push_back(r);
        else ridesB1.push_back(r);
    }
    memset(memo, -1, sizeof(memo));
    memset(memoB0, -1, sizeof(memoB0));
    initFuns();
    cin >> Q;
    while (Q--) {
        int T;
        cin >> T;
        cout << dp(0, T) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
