#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<int> vi; // but shortcuts are useful in competitive programming

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    int T;
    getline(cin, buf);
    T = stoi(buf);
    while (T--) {
        map<string, int> mapper;
        vector<vi> AL(205, vi());
        vector<string> words;
        int idx = 0;
        while (getline(cin, buf)) {
            if (buf == "*") break;
            words.push_back(buf);
            mapper[buf] = idx++;
        }
        // point to words that it can be transformed into
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                string a = words[i], b = words[j];
                if (a.size() == b.size()) {
                    int diff = 0;
                    for (int k = 0; k < a.size(); k++) {
                        if (a[k] != b[k]) diff++;
                    }
                    if (diff == 1) {
                        AL[mapper[a]].push_back(mapper[b]);
                        AL[mapper[b]].push_back(mapper[a]);
                    }
                }
            }
        }
        // get words
        while (getline(cin, buf)) {
            if (buf.empty()) break;
            stringstream ss(buf);
            string a, b;
            ss >> a >> b;
            int start = mapper[a], end = mapper[b];
            vi dist(mapper.size(), 1e9);
            dist[start] = 0;
            queue<int> q;
            q.push(start);
            while (!q.empty()) {
                if (dist[end] != 1e9) break;
                int u = q.front();
                q.pop();
                for (int v: AL[u]) {
                    if (dist[v] == 1e9) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            cout << a << " " << b << " " << dist[end] << "\n";
        }
        if (T) cout << "\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}