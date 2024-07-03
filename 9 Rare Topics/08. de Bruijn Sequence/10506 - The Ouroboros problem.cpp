#include <bits/stdc++.h>

using namespace std;

unordered_set<string> seen;
vector<int> edges;

void dfs(const string &node, int &k, string &A) {
    for (int i = 0; i < k; ++i) {
        string str = node + A[i];
        if (seen.find(str) == seen.end()) {
            seen.insert(str);
            dfs(str.substr(1), k, A);
            edges.push_back(i); // follows hierholzer where u visit all neighbours then pushback edge
        }
    }
}

string deBruijn(int n, int k, string A) {
    seen.clear();
    edges.clear();
    string startingNode = string(n - 1, A[0]);
    dfs(startingNode, k, A);
    string S;
    for (int edge : edges) S += A[edge];
//    S += startingNode; // qn allows wrap around so don't add this
    return S;
}

// code from gfg

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    while (cin >> n >> k) {
        string A;
        for (int i = 0; i < k; ++i) A += (char) ('0' + i);
        cout << deBruijn(n, k, A) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}