#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

bool dequal(double a, double b) {
    return abs(a - b) < 1e-9;
}

struct drink {
    string name;
    double u, cost;
};
vector<drink> drinks;
double m, u;
int d;

int dp(int idx, double drunk, double money) {
    if (idx == d) {
        if (dequal(drunk, u) && dequal(money, m)) return 1; // drunk u spent m
        return 0;
    }
    if (drunk > u || money > m) return 0;
    return max(dp(idx + 1, drunk, money), dp(idx, drunk + drinks[idx].u, money + drinks[idx].cost));
}

vi path;
void solve(int idx, double drunk, double money) {
    if (idx == d) return;
    if (dp(idx + 1, drunk, money)) { // solve when we don't take the drink
        solve(idx + 1, drunk, money);
    } else if (dp(idx, drunk + drinks[idx].u, money + drinks[idx].cost)) { // solve when we take the drink
        path.push_back(idx);
        solve(idx, drunk + drinks[idx].u, money + drinks[idx].cost);
    }
}

// feels like coin change complete search version since double cannot be used in dp so likely slow but its 0s only small test cases

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> m >> u >> d;
    drinks.resize(d);
    for (int i = 0; i < d; ++i) {
        string s;
        double strength;
        cin >> drinks[i].name >> strength >> s >> drinks[i].cost;
        drinks[i].u = strength / (s[2] - '0');
    }
    solve(0, 0, 0);
    if (path.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        vi idxCnt(d);
        for (int i : path) idxCnt[i]++;
        for (int i = 0; i < d; ++i) {
            if (idxCnt[i]) {
                cout << drinks[i].name << " " << idxCnt[i] << "\n";
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

