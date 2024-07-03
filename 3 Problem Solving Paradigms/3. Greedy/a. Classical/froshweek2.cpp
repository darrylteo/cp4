#include <bits/stdc++.h>

using namespace std;

// for each task, find the shortest valid interval

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> task(n), quiet(m);
    for (int &i: task) cin >> i;
    for (int &i: quiet) cin >> i;
    sort(task.begin(), task.end());
    sort(quiet.begin(), quiet.end());
    int ans = 0, qIdx = 0;
    for (int i = 0; i < task.size(); ++i) {
        while (qIdx < m && quiet[qIdx] < task[i]) {
            qIdx++;
        }
        if (qIdx == m) break;
        else {
            qIdx++;
            ans++;
        }
    }
    cout << ans << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

