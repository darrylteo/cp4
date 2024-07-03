#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> buttons = {
        {0, 1, 2, 3, 6},
        {0, 1, 2, 4, 7},
        {0, 1, 2, 5, 8},
        {3, 4, 5, 0, 6},
        {3, 4, 5, 1, 7},
        {3, 4, 5, 2, 8},
        {6, 7, 8, 0, 3},
        {6, 7, 8, 1, 4},
        {6, 7, 8, 2, 5}
};

vector<int> success(9, 0);

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> initial(9);
    for (int i = 0; i < 9; i++) cin >> initial[i];
    map<vector<int>, int> visited;
    queue<vector<int>> q;
    q.push(initial);
    visited[initial] = 0;
    int found = 0;
    while (!q.empty()) {
        vector<int> current = q.front();
        if (current == success) {
            cout << visited[current] << endl;
            found = 1;
            break;
        }
        q.pop();

        for (int i = 0; i < 9; ++i) {
            vector<int> next = current;
            for (int j: buttons[i]) {
                next[j] = (next[j] + 1) % 4;
            }
            if (visited.find(next) == visited.end()) {
                visited[next] = visited[current] + 1;
                q.push(next);
            }
        }
    }

    if (!found) cout << -1 << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}