#include <bits/stdc++.h>

using namespace std;

// qn ALOT of info but only 2 choices for driver. refill or don't refill. base dfs on this choice
// これは私の苦手 backtracking ._. simple qn 45min

struct station {
    double dist;
    double cost;
};
vector<station> stations;
double bestCost, dist, cap, mpg, cost, numStops, lastDist;

void dfs(int i, double curCost, double curGas) {
    if (i == numStops) {
        bestCost = min(bestCost, curCost);
        return;
    }
    double gasRemaining = curGas - stations[i].dist / mpg;
    // cannot make it to next town MUST refill
    if (stations[i + 1].dist > gasRemaining * mpg) {
        dfs(i + 1, curCost + 2 + round(stations[i].cost * (cap - gasRemaining)) / 100, cap);
    } else if (gasRemaining > cap / 2) {
        // he doesn't refill when have > half gas
        dfs(i + 1, curCost, gasRemaining);
    } else {
        // he refills
        dfs(i + 1, curCost + 2 + round(stations[i].cost * (cap - gasRemaining)) / 100, cap);
        // he doesn't refill
        dfs(i + 1, curCost, gasRemaining);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count = 0;
    while (cin >> dist >> cap >> mpg >> cost >> numStops) {
        if (dist == -1) {
            break;
        }
        stations.clear();
        bestCost = INT_MAX;
        for (int i = 0; i < numStops; i++) {
            station s;
            cin >> s.dist >> s.cost;
            stations.push_back(s);
        }
        // make it distance, not cum distance. stations[3].dist will be distance from station 2 to 3
        lastDist = dist - stations[numStops - 1].dist;
        for (int i = numStops - 1; i > 0; i--) {
            stations[i].dist = stations[i].dist - stations[i - 1].dist;
        }
        stations.push_back({lastDist, 0});
        dfs(0, cost, cap);
        cout << "Data Set #" << ++count << endl;
        cout << "minimum cost = $" << fixed << setprecision(2) << bestCost << endl;


    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

