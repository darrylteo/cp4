#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

// trivial if identified euler graph
// it is euler because each road has 2 lanes so inDegree = outDegree for all

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        double dist = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> ws; // doesn't matter can clear hanger
        string buf;
        while (getline(cin, buf) && !buf.empty()) {
            stringstream ss(buf);
            ss >> x1 >> y1 >> x2 >> y2;
            dist += 2 * hypot(x1 - x2, y1 - y2);
        }
        dist /= 1000;
        dist /= 20;
        int mins = round(dist * 60);
        cout << mins / 60 << ":" << setw(2) << setfill('0') << mins % 60 << '\n';
        if (T) cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
