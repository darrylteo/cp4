#include <bits/stdc++.h>

using namespace std;

// try to do all tasks, once doing all tasks will be past deadline, reject most expensive task

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        vector<pair<int, int>> v(x);
        priority_queue<int> pq;
        for (int i = 0; i < x; i++) {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        int t = 0;
        for (int i = 0; i < x; i++) {
            t += v[i].first; // try to do this task
            pq.push(v[i].first); // add to pq
            if (t > v[i].second) { // if we are past deadline
                t -= pq.top(); // remove most expensive task
                pq.pop();
            }
        }
        cout << pq.size() << '\n';
        if (n) cout << '\n';
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
