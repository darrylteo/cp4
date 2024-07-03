#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q_num, Period;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;
    string s;
    while (cin >> s) {
        if (s == "#") break;
        cin >> Q_num >> Period;
        Q.push({Period, Q_num, Period}); // 1. time, 2. q_num, 3. period (it is "sorted"... at least the top is :P)
    }
    int K;
    cin >> K;
    while (K--) {
        int time = get<0>(Q.top());
        int q_num = get<1>(Q.top());
        int period = get<2>(Q.top());
        Q.pop();
        cout << q_num << '\n';
        Q.push({time + period, q_num, period});
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
