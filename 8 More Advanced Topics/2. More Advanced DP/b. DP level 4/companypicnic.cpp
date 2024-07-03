#include <bits/stdc++.h>

using namespace std;

struct res {
    int num; // num of teams
    double spd; // sum of spd

    bool operator<(const res &other) const {
        if (num != other.num) return num < other.num;
        return spd < other.spd;
    }
};

vector<double> speed;
vector<int> adj[1005]; // directed. points to children
res memo[1005][2]; // (starting from node i, (0 = not taken, 1 = taken)) gives the best result

res dp(int node, int taken) {
    if (memo[node][taken].num != -1) return memo[node][taken];

    res ans = {0, 0}; // current best ans if we do not take this guy+child. his children are free to form teams (taken = 0)
    for (int child: adj[node]) {
        res tmp = dp(child, 0);
        ans.num += tmp.num;
        ans.spd += tmp.spd;
    }
    res best = ans;
    if (!taken) {
        for (int child: adj[node]) {
            res tmp1 = dp(child, 1);
            res tmp2 = dp(child, 0);
            // subtract to remove tmp2 soln since it was counted for above. add tmp1 soln since it is new, plus 1 for this guy+child team
            res newAns = {ans.num - tmp2.num + tmp1.num + 1,
                          ans.spd - tmp2.spd + tmp1.spd + min(speed[node], speed[child])};
            best = max(best, newAns);
        }
    }

    return memo[node][taken] = best;
}


// not obvious to see from the offset that don't need to show entire visited vector for the tree
// just whether last guy was taken or not

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    n++;
    speed.resize(n);
    string parent, child;
    unordered_map<string, int> nameToIdx;
    nameToIdx["CEO"] = 0;
    for (int i = 1; i < n; i++) {
        double tmpSpd;
        cin >> child >> tmpSpd >> parent;
        if (nameToIdx.find(parent) == nameToIdx.end()) nameToIdx[parent] = nameToIdx.size();
        if (nameToIdx.find(child) == nameToIdx.end()) nameToIdx[child] = nameToIdx.size();
        speed[nameToIdx[child]] = tmpSpd;
        adj[nameToIdx[parent]].push_back(nameToIdx[child]);
    }
    for (int i = 0; i < n; i++) memo[i][0] = memo[i][1] = {-1, -1};
    res ans = dp(0, 1); // CEO is "taken" since it is dummy node
    cout << ans.num << " " << fixed << setprecision(8) << ans.spd / ans.num << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
