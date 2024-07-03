#include <bits/stdc++.h>

using namespace std;

struct medicine {
    int time, priority, period;
    string name;
};

bool cmp(const medicine &a, const medicine &b) {
    if (a.time == b.time) return a.priority > b.priority;
    return a.time > b.time; // sort by time first, then by priority
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k;
    string s;
    cin >> t;
    while (t--) {
        // custom comparator for priority queue
        // https://stackoverflow.com/questions/16111337/declaring-a-priority-queue-in-c-with-a-custom-comparator
        priority_queue<medicine, vector<medicine>, decltype(&cmp)> Q(cmp);
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            int period;
            string name;
            cin >> name >> period;
            medicine m = {period, i, period, name};
            Q.push(m);
        }
        while (k--) {
            medicine m = Q.top();
            Q.pop();
            cout << m.time << " " << m.name << "\n";
            m.time += m.period;
            Q.push(m);
        }

    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
