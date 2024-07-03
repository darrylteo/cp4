#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

enum {
    UNVISITED = -1
};

struct charac {
    int name, langSpoken;
    vi langUnderstood;
};

int dfsNumberCounter, SCCSize[105], SCCCnt;
vi dfs_num, dfs_low, visited, AL[105];                 // global variables
stack<int> St;

inline void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter;    // dfs_low[u]<=dfs_num[u]
    dfsNumberCounter++;                            // increase counter
    St.push(u);                                    // remember the order
    visited[u] = 1;
    for (int &v: AL[u]) {
        if (dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if (visited[v])                              // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {                // a root/start of an SCC
        int cnt = 0;
        SCCCnt++;
        while (true) {
            cnt++;
            int v = St.top();
            St.pop();
            visited[v] = 0;
            if (u == v) break;
        }
        SCCSize[SCCCnt] = cnt;
    }
}

// tedious to make AL, otherwise standard
// AL is which point u to v if u can speak a language that v understands

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string buf;
    getline(cin, buf);
    N = stoi(buf);
    vector<charac> characs(N);
    map<string, int> langToId;
    set<string> langs;
    for (int i = 0; i < N; ++i) {
        getline(cin, buf);
        stringstream ss(buf);
        string name, lang;
        ss >> name;
        ss >> lang;
        characs[i].name = i; // sure unique so no need the map and set
        if (langs.insert(lang).second) { // in case new lang
            langToId[lang] = langs.size();
        }
        characs[i].langSpoken = langToId[lang]; // insert regardless new or not
        characs[i].langUnderstood.push_back(langToId[lang]); // he can understand his own language
        while (ss >> lang) {
            if (langs.insert(lang).second) { // in case new lang
                langToId[lang] = langs.size();
            }
            characs[i].langUnderstood.push_back(langToId[lang]);
        }
    }

    // get directed graph
    for (int i = 0; i < N; ++i) { // for each person
        int langSpoken = characs[i].langSpoken;
        for (int j = 0; j < N; ++j) { // for each other person
            if (i == j) continue;
            for (int &langUnderstood: characs[j].langUnderstood) {
                if (langUnderstood == langSpoken) {
                    AL[i].push_back(j);
                    break;
                }
            }
        }
    }


    // run Tarjan's SCC code here
    dfsNumberCounter = SCCCnt = 0;
    dfs_num.assign(N, UNVISITED);
    dfs_low.assign(N, 0);
    visited.assign(N, 0);
    memset(SCCSize, 0, sizeof SCCSize);
    while (!St.empty()) St.pop();
    for (int u = 0; u < N; ++u)
        if (dfs_num[u] == UNVISITED)
            tarjanSCC(u);

    int ans = 0;
    for (int i = 1; i <= SCCCnt; ++i) {
        ans = max(ans, SCCSize[i]);
    }
    cout << N - ans << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}