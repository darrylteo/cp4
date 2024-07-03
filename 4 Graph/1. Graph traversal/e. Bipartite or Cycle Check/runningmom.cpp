#include <bits/stdc++.h>

using namespace std;

// ref: https://www.geeksforgeeks.org/print-nodes-which-are-not-part-of-any-cycle-in-a-directed-graph/

int n, id = 0, visited[5005], recStack[5005], cyclePart[5005];
vector<int> adjList[5005];
unordered_map<string, int> mapper;
unordered_set<string> cities; // to check if city is already in the map

bool isCycle(int u) {
    if (!visited[u]) {
        visited[u] = 1;
        recStack[u] = 1;
        for (int v : adjList[u]) {
            if ((!visited[v] && isCycle(v)) || recStack[v]) { // recStack[v] if found loop. isCycle[v] recurses back out of loop
                cyclePart[v] = 1;
                return true;
            }
        }
    }
    recStack[u] = 0;
    return false;
}

void checkAllCycle() {
    for (int i = 0; i < id; ++i) {
        if (!visited[i] && isCycle(i)) {
            cyclePart[i] = 1;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (cities.insert(s1).second) {
            mapper[s1] = id++;
        }
        if (cities.insert(s2).second) {
            mapper[s2] = id++;
        }
        adjList[mapper[s1]].push_back(mapper[s2]); // 1st city points to 2nd city
    }
    checkAllCycle();

    string s;
    while (cin >> s) {
        if (cyclePart[mapper[s]] == 1) {
            cout << s << " safe\n";
        } else {
            cout << s << " trapped\n";
        }
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



