#include <bits/stdc++.h>

using namespace std;

int originalLinks[200005], currLinks[200005], leftAlready[200005];
vector<int> adjList[200005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, P, X, L;

    memset(originalLinks, 0, sizeof(originalLinks));
    memset(currLinks, 0, sizeof(currLinks));
    memset(leftAlready, 0, sizeof(leftAlready));
    queue<int> q;
    cin >> C >> P >> X >> L;
    for (int i = 0; i < P; ++i) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        originalLinks[a]++;
        originalLinks[b]++;
        currLinks[a]++;
        currLinks[b]++;
    }
    q.push(L); // q are countries that left
    leftAlready[L] = 1;
    while (!q.empty()) {
        int curr = q.front();
        if (curr == X) {
            break;
        }
        q.pop();
        for (int i = 0; i < adjList[curr].size(); ++i) {
            if (leftAlready[adjList[curr][i]]) {
                continue;
            }
            int next = adjList[curr][i];
            currLinks[next]--;
            if (currLinks[next] <= originalLinks[next] / 2) {
                leftAlready[next] = 1;
                q.push(next);
            }
        }
    }
    if (leftAlready[X]) {
        cout << "leave" << endl;
    } else {
        cout << "stay" << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



