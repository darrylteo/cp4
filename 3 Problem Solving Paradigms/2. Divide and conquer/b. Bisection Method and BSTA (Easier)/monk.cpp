#include <bits/stdc++.h>

using namespace std;

struct leg {
    int dist, time;
};

double diffDist(double time, const vector<leg> &ascents, const vector<leg> &descents, int mtHeight) {
    // heights are measured from the bottom of the mountain. dist is distance walked
    double currDistA = 0, currDistD = 0, timeLeftA = time, timeLeftD = time;
    for (auto ascent: ascents) {
        if (timeLeftA > ascent.time) { // complete this leg
            currDistA += ascent.dist;
            timeLeftA -= ascent.time;
        } else { // complete part of this leg partway
            currDistA += timeLeftA * ascent.dist / ascent.time;
            break;
        }
    }
    for (auto descent: descents) {
        if (timeLeftD > descent.time) { // complete this leg
            currDistD += descent.dist;
            timeLeftD -= descent.time;
        } else { // complete part of this leg partway
            currDistD += timeLeftD * descent.dist / descent.time;
            break;
        }
    }
    // if 0, they meet at this time
    // if positive, they haven't met
    // if negative, they have met and continued on
    return (mtHeight - currDistD) - currDistA;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, d, mtHeight = 0;
    cin >> a >> d;
    vector<leg> ascents, descents;
    for (int i = 0; i < a; ++i) {
        int x, y;
        cin >> x >> y;
        leg l = {x, y};
        ascents.push_back(l);
        mtHeight += x;
    }
    for (int i = 0; i < d; ++i) {
        int x, y;
        cin >> x >> y;
        leg l = {x, y};
        descents.push_back(l);
    }

    double lo = 0, hi = 1e9;
    while (hi - lo > 1e-6) {
        double mid = (lo + hi) / 2;
        double diff = diffDist(mid, ascents, descents, mtHeight);
        if (diff > 0) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(6) << lo << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
