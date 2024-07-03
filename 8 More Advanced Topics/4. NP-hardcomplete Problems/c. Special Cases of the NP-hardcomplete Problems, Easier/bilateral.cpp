#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int e, n, nL = 0;
set<int> nodes;
map<int, int> m, m_reverse; // map node to index
vector<int> adjlist[2000];
vector<pair<int, int>> edges;
vector<int> match, visited;

// MCBM Augmenting Path Algorithm (from book)
int aug(int L) {
    if (visited[L]) return 0;
    visited[L] = 1;
    for (auto &R: adjlist[L]) {
        if (match[R] == -1 || aug(match[R])) {
            match[R] = L;
            match[L] = R;
            return 1;
        }
    }
    return 0;
}

// look at konig from book
set<int> U;  // U is the unmatched vertices in the left set
set<int> Z;  // is the vertices in U or connected to U via an augmenting path
set<int> mvc;

void connected_to_u(int i) {
    if (visited[i]) return;
    visited[i] = true;

    if (i < nL) {  // left side
        for (auto &j: adjlist[i]) {
            if (match[i] != j) {
                connected_to_u(j);
            }
        }
    } else {  // right side
        for (auto &j: adjlist[i]) {
            if (match[i] == j) {
                connected_to_u(j);
            }
        }
    }
}

// hard.. ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_8_Advanced_Topics/8.7_Problem_Decomposition/kattis_bilateral.cpp
// mostly copy pasta since i tried my own version for 3h already and it didn't work >:(
// just some optimization to get Z which sped up code from 0.17s to 0.01s

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    n = 0;
    cin >> e;

    int u, v;
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
        if (nodes.find(u) == nodes.end()) {
            nodes.insert(u);
            nL++;
            n++;
        }
        if (nodes.find(v) == nodes.end()) {
            nodes.insert(v);
            n++;
        }
    }
    int counter = 0;
    if (nodes.find(1009) != nodes.end()) { // ensure 1009 is vertex 0
        m[1009] = 0;
        m_reverse[0] = 1009;
        nodes.erase(1009);
        counter = 1;
    }
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        m[*it] = counter;
        m_reverse[counter] = *it;
        counter++;
    }
    for (auto &[u, v]: edges) {
        u = m[u];  // convert to our own naming
        v = m[v];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    match.assign(n, -1);
    int MCBM = 0;
    for (int u = 0; u < nL; u++) {    // all left vectices
        for (auto &v: adjlist[u]) {  // all right vectices neighbouring u
            if (match[v] == -1) {     // if v is unassigned
                match[v] = u;         // match v to u
                match[u] = v;         // match u to v
                MCBM++;
                break;
            }
        }
    }

    // MCBM Calculation
    for (int L = 1; L < nL; L++) { // vertex 0 already matched if possible
        if (match[L] == -1) {
            visited.assign(n, 0);
            MCBM += aug(L);
        }
    }
    cout << MCBM << endl;

    for (int i = 0; i < nL; i++) {
        if (match[i] == -1) {
            U.insert(i);
        }
    }

    visited.assign(n, 0);
    for (auto &i: U) {
        connected_to_u(i);
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) Z.insert(i);
    }

    // MVC = (L \ Z) union (R intersect Z)
    for (int i = 0; i < nL; i++) {
        if (Z.count(i) == 0) {
            mvc.insert(i);
        }
    }
    for (int i = nL; i < n; i++) {
        if (Z.count(i)) {
            mvc.insert(i);
        }
    }

    for (auto i: mvc) {
        cout << m_reverse[i] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
