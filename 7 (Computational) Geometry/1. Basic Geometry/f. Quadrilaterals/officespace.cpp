#include <bits/stdc++.h>

using namespace std;

struct person {
    string name;
    int x1, y1, x2, y2;
};


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int w, h;
    while (cin >> w >> h) {
        int n;
        cin >> n;
        vector<person> people(n);
        for (int i = 0; i < n; i++) {
            cin >> people[i].name >> people[i].x1 >> people[i].y1 >> people[i].x2 >> people[i].y2;
        }
        vector<vector<int>> grid(w, vector<int>(h, 0));
        for (int i = 0; i < n; i++) {
            for (int x = people[i].x1; x < people[i].x2; x++) {
                for (int y = people[i].y1; y < people[i].y2; y++) {
                    grid[x][y] += 1 << i;
                }
            }
        }
        vector<int> count(n, 0); // counting when they have a space to themselves
        int countShared = 0, unoccupied = 0;
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                if (grid[x][y] == 0) {
                    unoccupied++;
                } else if (__builtin_popcount(grid[x][y]) > 1) {
                    countShared++;
                } else {
                    int mask = grid[x][y];
                    for (int i = 0; i < n; i++) {
                        if (mask & (1 << i)) {
                            count[i]++;
                            break;
                        }
                    }
                }
            }
        }
        cout << "Total " << w * h << '\n';
        cout << "Unallocated " << unoccupied << '\n';
        cout << "Contested " << countShared << '\n';
        for (int i = 0; i < n; i++) {
            cout << people[i].name << " " << count[i] << '\n';
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}