#include <bits/stdc++.h>

using namespace std;

// send to the furthest post office, if got spare capacity, drop it into previous furthest post office
// separate the left and right offices

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> officesL, officesR; // distance, required letters
    for (int i = 0; i < N; i++) {
        int dist, req;
        cin >> dist >> req;
        if (dist < 0) {
            officesL.emplace_back(-dist, req);
        } else {
            officesR.emplace_back(dist, req);
        }
    }
    sort(officesL.begin(), officesL.end(), greater<pair<int, int>>());
    sort(officesR.begin(), officesR.end(), greater<pair<int, int>>());
    int distL = 0, distR = 0, extraL = 0, extraR = 0;
    for (int i = 0; i < officesL.size(); ++i) {
        int dist = officesL[i].first;
        int req = officesL[i].second;
        if (extraL >= req) { // on the way
            extraL -= req;
        } else {
            req -= extraL;
            int num = ceil((double)req / K);
            distL += num * 2 * dist;
            extraL = num * K - req;
        }
    }
    for (int i = 0; i < officesR.size(); ++i) {
        int dist = officesR[i].first;
        int req = officesR[i].second;
        if (extraR >= req) { // on the way
            extraR -= req;
        } else {
            req -= extraR;
            int num = ceil((double)req / K);
            distR += num * 2 * dist;
            extraR = num * K - req;
        }
    }
    cout << distL + distR << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
