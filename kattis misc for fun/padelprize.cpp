#include <bits/stdc++.h>

using namespace std;

// fenwick and segment tree are one of my greatest enemies :<
// ref: https://pastebin.com/se1heatP

// Fenwick
void update(vector<int> &fenwick, int index, int value) {
    while (index < (int)fenwick.size()) {
        fenwick[index] += value;
        index += index & -index; // LSOne(index) in book terminology
    }
}
int getSum(vector<int> &fenwick, int index) {
    int sum = 0;
    while (index) {
        sum += fenwick[index];
        index -= index & -index;
    }
    return sum;
}
// using fenwick with range update, point query

// tin tout depth is mainly used for LCA
// https://courses.edx.org/assets/courseware/v1/434ab5b19542aa5fcbab8f631ff85b48/asset-v1:ITMOx+I2CPx+3T2016+type@asset+block/lecture-04.pdf
tuple<vector<int>, vector<int>, vector<int>> get_DFS_order(const vector<vector<int>> &children) {
    int m = (int)children.size()-1;
    vector<int> tin(m+1), tout(m+1), depth(m+1);
    int t = 0;
    function<void(int, int)> dfs = [&](int node, int d) {
        depth[node] = d; // number of times the medal changed hands
        tin[node] = t++; // time of entry
        for (int child : children[node]) dfs(child, d+1);
        tout[node] = t; // time of exit
    };
    dfs(m, 0);

    return {tin, tout, depth};
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> x(m), y(m);
    for (int i = 0; i < m; ++i) cin >> x[i] >> y[i];

    // precalculate winBackMoment
    //  - first moment after t that the initial winner of medal t wins medal t back
    vector<int> winBackMoment(m);
    {
        // create rooted tree with every node i being linked upwards to the next time x[i] is beaten
        vector<vector<int>> children(1+m);
        vector<int> nextLoss(n, m);
        for (int i = m-1; i >= 0; --i) {
            children[nextLoss[x[i]]].push_back(i);
            nextLoss[y[i]] = i;
        }

        // generate dfs order for this tree, root being at m
        tuple<vector<int>, vector<int>, vector<int>> triple = get_DFS_order(children);
        vector<int> tin = get<0>(triple), tout = get<1>(triple), depth = get<2>(triple);

        // for each node i, find winBackMoment: nearest ancestor j such that x[i] == x[j]. same guy won back the medal
        vector<vector<int>> iWithX(n);
        for (int i = 0; i < m; ++i) iWithX[x[i]].push_back(i);


        vector<int> fenwick(1+m+10); // indexed by tin and tout
        update(fenwick, 1, m); // all answers initially m
        for (int X = 0; X < n; ++X) { // find winBackMoment for all i with this x
            // sort by depth
            sort(iWithX[X].begin(), iWithX[X].end(), [&depth](int i, int j){
                return depth[i] < depth[j];
            });
            vector<pair<int, int>> pastUpdates;
            for (int i : iWithX[X]) {
                // read fenwick at tin[i] for ans i
                int ancestor = getSum(fenwick, tin[i]);
                winBackMoment[i] = ancestor;
                // update fenwick by setting [tin[i], tout[i]) to i
                // but all values on that range are currently == ancestor, so just add i-ancestor
                update(fenwick, tin[i], i-ancestor); // tin and tout always positive since root (m) has tin 0
                update(fenwick, tout[i], ancestor-i);
                pastUpdates.emplace_back(tin[i], i-ancestor);
                pastUpdates.emplace_back(tout[i], ancestor-i);
            }
            while (!pastUpdates.empty()) {
                auto [i, v] = pastUpdates.back();
                update(fenwick, i, -v);
                pastUpdates.pop_back();
            }
        }
    }


    vector<int> timeKeptByWinner(m); // time spent by winner of match i with the medal won at that time

    vector<pair<int, int>> medalWinner(1+m, {0, 0}); // time, -person
    vector<int> nextLoss(n, m);
    for (int t = m-1; t >= 0; --t) {
        int i = x[t], j = y[t]; // i beat j at time t

        // how much time does i spend with medal t after this point?
        //  - initial time before losing
        timeKeptByWinner[t] = nextLoss[i]-t;
        //  - possible time later after winning it back
        if (winBackMoment[t] < m) timeKeptByWinner[t] += timeKeptByWinner[winBackMoment[t]];

        medalWinner[t] = max(medalWinner[nextLoss[i]], {timeKeptByWinner[t], -i});

        // update nextLoss
        nextLoss[j] = t;
    }

    vector<int> medalsWon(n);
    for (int i = 0; i < m; ++i) ++medalsWon[-medalWinner[i].second];
    for (int v : medalsWon) cout << v << ' ';
    cout << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
