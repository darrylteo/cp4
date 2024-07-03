#include <bits/stdc++.h>

using namespace std;

string update(bool vert, int idx, const string &grid) {
    string s = grid;
    if (vert) {
        char temp = s[idx + 6];
        s[idx + 6] = s[idx + 3];
        s[idx + 3] = s[idx];
        s[idx] = temp;
    } else {
        int start = 3 * idx;
        char temp = s[start];
        s[start] = s[start + 1];
        s[start + 1] = s[start + 2];
        s[start + 2] = temp;
    }
    return s;
}

string grid_to_str(const vector<vector<int>> &grid) {
    string s;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s += to_string(grid[i][j]);
        }
    }
    return s;
}

// initially took very long as i found how to go from input to correct
// but actually can do reverse moves from correct to all possible configurations and print from back

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string correct = "123456789";

    map<string, string> dist;
    queue<string> q;
    q.push(correct);
    dist[correct] = "";
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            string new_grid = update(true, i, cur);
            if (dist.find(new_grid) == dist.end()) {
                dist[new_grid] = "V" + to_string(i + 1) + dist[cur] ;
                q.push(new_grid);
            }
            new_grid = update(false, i, cur);
            if (dist.find(new_grid) == dist.end()) {
                dist[new_grid] = "H" + to_string(i + 1) + dist[cur] ;
                q.push(new_grid);
            }
        }
    }

    while (true) {
        vector<vector<int>> grid(3, vector<int>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> grid[i][j];
            }
        }
        if (grid[0][0] == 0) break;
        string s = grid_to_str(grid);
        if (dist.find(s) != dist.end()) {
            cout << dist[s].size() / 2 << ' ' << dist[s] << endl;
        } else {
            cout << "Not solvable" << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}



