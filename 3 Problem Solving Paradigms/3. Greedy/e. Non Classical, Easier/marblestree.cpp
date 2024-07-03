#include <bits/stdc++.h>

using namespace std;

// follow this: https://algorithmist.com/wiki/UVa_10672_-_Marbles_on_a_tree

struct node {
    int parentId, childCnt, marbles;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        vector<node> nodes(n + 1);
        nodes[0] = {0, 0, 1};
        for (int i = 1; i <= n; ++i) {
            int id, marbles, childCnt;
            cin >> id >> marbles >> childCnt;
            for (int j = 0; j < childCnt; ++j) {
                int childId;
                cin >> childId;
                nodes[childId].parentId = id;
            }
            nodes[id].marbles = marbles;
            nodes[id].childCnt = childCnt;
        }
        int shifts = 0;

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (nodes[i].childCnt == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int id = q.front();
            q.pop();
            if (nodes[id].parentId != 0) {
                // remove child from parent and ensure child has 1 marble
                nodes[nodes[id].parentId].childCnt--;
                // has parent, is leaf, and has incorrect marbles
                if (nodes[id].marbles > 1) {
                    // give parent marbles if too many, leaving 1 for itself
                    nodes[nodes[id].parentId].marbles += nodes[id].marbles - 1;
                    shifts += nodes[id].marbles - 1;
                    nodes[id].marbles = 1;
                } else {
                    // take marbles from parent if too few, nodes[id].marbles may be negative
                    nodes[nodes[id].parentId].marbles -= 1 - nodes[id].marbles;
                    shifts += 1 - nodes[id].marbles;
                    nodes[id].marbles = 1;
                }
            }
            if (nodes[id].parentId != 0 && nodes[nodes[id].parentId].childCnt == 0) {
                q.push(nodes[id].parentId);
            }
        }
        cout << shifts << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
