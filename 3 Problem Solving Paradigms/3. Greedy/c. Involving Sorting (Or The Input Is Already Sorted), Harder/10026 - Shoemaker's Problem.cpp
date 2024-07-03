#include <bits/stdc++.h>

using namespace std;

struct job {
    double time, fine, ratio, id;
};

// the job with worst fine to time ratio will have to be completed first

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        vector<job> jobs(m);
        for (int i = 0; i < m; ++i) {
            cin >> jobs[i].time >> jobs[i].fine;
            jobs[i].ratio = jobs[i].fine / jobs[i].time;
            jobs[i].id = i + 1;
        }
        sort(jobs.begin(), jobs.end(), [](const job &a, const job &b) {
            if (a.ratio == b.ratio) {
                return a.id < b.id; // smaller id 1st
            }
            return a.ratio > b.ratio; // worst ratio 1st
        });
        for (int i = 0; i < m; ++i) {
            cout << jobs[i].id;
            if (i != m - 1) cout << " ";
        }
        cout << endl;
        if (n != 0) cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

