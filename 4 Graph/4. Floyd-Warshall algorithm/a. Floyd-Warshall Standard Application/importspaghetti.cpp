#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// note that tarjan SCC does not work here since there could be subSCCs within the SCC printed
// smart twist on floyd warshall to find size of cycle by setting cost of each step = 1 and finding grid[i][i] = size of cycle
// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_4_Graph/APSP/kattis_importspaghetti.cpp
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // making input into adjacency matrix
    int N;
    cin >> N;
    unordered_map<string, int> name_to_id;
    unordered_map<int, string> id_to_name;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        name_to_id[name] = i;
        id_to_name[i] = name;
    }
    int K, grid[505][505];
    string buf;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = 1e9;
        }
    }
    for (int i = 0; i < N; ++i) {
        cin >> buf >> K >> ws;
        while (K--) {
            getline(cin, buf);
            stringstream ss(buf);
            string name;
            ss >> name; // ignore "import"
            while (ss >> name) {
                if (name.back() == ',') name.pop_back();
                grid[name_to_id[name]][i] = 1;
                if (name_to_id[name] == i) {
                    cout << name << endl;
                    return 0;
                }
            }
        }
    }

    // standard floyd warshall with path reconstruction from book
    vector<vector<int>> p(N, vector<int>(N, -1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            p[i][j] = i;
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][k] + grid[k][j] < grid[i][j]) {
                    grid[i][j] = grid[i][k] + grid[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
    int minCycleSize = 1e9, cycleStart = -1;
    for (int i = 0; i < N; ++i) {
        if (grid[i][i] < minCycleSize) {
            minCycleSize = grid[i][i];
            cycleStart = i;
        }
    }
    if (cycleStart == -1) {
        cout << "SHIP IT" << endl;
        return 0;
    }
    vector<int> cycle;
    cycle.push_back(cycleStart);
    int cur = p[cycleStart][cycleStart];
    while (cur != cycleStart) {
        cycle.push_back(cur);
        cur = p[cycleStart][cur];
    }
    for (int i: cycle) {
        cout << id_to_name[i] << " ";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


