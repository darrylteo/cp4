#include <bits/stdc++.h>

using namespace std;

const int numPPS[50] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int scoreToPower(int score) {
    if (score == 0) return 6;
    int power = 0;
    while (score > 0) {
        power += numPPS[score % 10];
        score /= 10;
    }
    return power;
}

// string time to seconds
int sTimeToSec(const string& sTime) {
    int h = stoi(sTime.substr(0, 2));
    int m = stoi(sTime.substr(3, 2));
    int s = stoi(sTime.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string tmp;
    int h, m, s, sCurr, sPrev, hScore, gScore, tmpScore, power, cases = 0;
    while (cin >> tmp) {
        if (tmp == "START") {
            cin >> tmp;
            sCurr = sTimeToSec(tmp);
            hScore = 0;
            gScore = 0;
            power = 0;
        } else if (tmp == "SCORE") {
            cin >> tmp;
            sCurr = sTimeToSec(tmp);
            // it showed previous scores for sCurr - sPrev seconds
            power += (sCurr - sPrev) * (scoreToPower(hScore) + scoreToPower(gScore));
            // update scores
            cin >> tmp >> tmpScore;
            if (tmp == "home") hScore += tmpScore;
            else gScore += tmpScore;
        } else if (tmp == "END") {
            cin >> tmp;
            sCurr = sTimeToSec(tmp);
            power += (sCurr - sPrev) * (scoreToPower(hScore) + scoreToPower(gScore));
            cout << "Case " << ++cases << ": " << power << endl;
        }
        sPrev = sCurr;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}