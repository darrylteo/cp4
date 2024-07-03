#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

const int MAX_n = 12; // up to 10 unique places excl home and work
int lastId;
double dist[MAX_n][MAX_n], memo[MAX_n][1 << (MAX_n - 1)];

double dp(int u, int mask) {                        // mask = free coordinates
    if (mask == 0) {
        if (u == lastId) return 0;                // reach home
        else return 2000000000;                   // didn't end at home
    }
    double &ans = memo[u][mask];
    if (ans != -1) return ans;                     // computed before
    ans = 2000000000;
    int m = mask;
    while (m) {                                    // up to O(n)
        int two_pow_v = LSOne(m);                    // but this is fast
        int v = __builtin_ctz(two_pow_v) + 1;          // offset v by +1. // ctz = count trailing zeros
        ans = min(ans, dist[u][v] + dp(v, mask ^ two_pow_v)); // keep the min
        m -= two_pow_v;
    }
    return ans;
}

vector<int> path;

void getPath(int u, int mask) {                    // backtracking routine
    if (mask == 0) return;                         // close the loop
    double opt = dp(u, mask);
    int m = mask;
    while (m) {                                    // up to O(n)
        int two_pow_v = LSOne(m);                    // but this is fast
        int v = __builtin_ctz(two_pow_v) + 1;          // offset v by +1. // ctz = count trailing zeros
        if (fabs(opt - (dist[u][v] + dp(v, mask ^ two_pow_v))) < 1e-9) { // if same, same state
            path.push_back(v);
            getPath(v, mask ^ two_pow_v); // recurse on this state
            return;
        }
        m -= two_pow_v;
    }
}


// similar to 12841 - In Puzzleland (III)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<string, pair<double, double>> locations;
    for (int i = 0; i < n; ++i) {
        string name;
        double x, y;
        cin >> name >> x >> y;
        locations[name] = {x, y};
    }
    string buf;
    cin.ignore();
    while (getline(cin, buf)) {
        if (buf.empty()) break;
        stringstream ss(buf);
        string tmp;
        vector<pair<double, double>> currSet;
        vector<string> currNames;
        currSet.emplace_back(locations["work"]);
        currNames.emplace_back("work");
        while (ss >> tmp) {
            currSet.emplace_back(locations[tmp]);
            currNames.emplace_back(tmp);
        }
        currSet.emplace_back(locations["home"]);
        currNames.emplace_back("home");
        memset(dist, 0, sizeof dist);
        for (int i = 0; i < MAX_n; ++i) {
            for (int j = 0; j < (1 << (MAX_n - 1)); ++j) {
                memo[i][j] = -1;
            }
        }
        for (int i = 0; i < currSet.size(); ++i) {
            for (int j = i + 1; j < currSet.size(); ++j) {
                dist[i][j] = dist[j][i] = sqrt(pow(currSet[i].first - currSet[j].first, 2) +
                                               pow(currSet[i].second - currSet[j].second, 2));
            }
        }
        lastId = currSet.size() - 1;
        path.clear();
        getPath(0, (1 << (currSet.size() - 1)) - 1);
        for (int i = 0; i < path.size() - 1; ++i) {
            cout << currNames[path[i]] << " ";
        }
        cout << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}