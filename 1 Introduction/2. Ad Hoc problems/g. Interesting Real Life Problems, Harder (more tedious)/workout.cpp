#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    vector<int> jimU, jimR, gymU, gymR, gymT;
    int tmp;
    for (int i = 0; i < 20; i++) {
        cin >> tmp;
        if (i % 2 == 0) {
            jimU.push_back(tmp);
        } else {
            jimR.push_back(tmp);
        }
    }
    for (int i = 0; i < 10; i++){
        cin >> tmp;
        gymU.push_back(tmp);
        cin >> tmp;
        gymR.push_back(tmp);
        cin >> tmp;
        gymT.push_back(tmp);
    }

    int time = 0;
    // machine is in use from T+(U+R)*n to T+(U+R)*n + U
    for (int i = 0; i < 30; i++) {
        // here can interpret time = jimReady
        // gymStart will be the closest time (just before) to jimReady
        int n, gymStart, gymEnd, gymNextStart, j = i%10;
        n = max((time - gymT[j]), 0) / (gymU[j] + gymR[j]);
        gymStart = gymT[j] + (gymU[j] + gymR[j]) * n;
        gymEnd = gymStart + gymU[j];
        if (gymEnd > time && time >= gymStart) { // cannot use machine
            time = gymEnd + jimU[j] + jimR[j];
        } else { // can use machine
            time = time + jimU[j] + jimR[j];
        }

        // find next start time of gym (closest to when jimEnd i.e. gymReady)
        int jimStart = time - jimR[j] - jimU[j], jimEnd = time - jimR[j];
        n = max((jimEnd - gymT[j]), 0) / (gymU[j] + gymR[j]);
        gymNextStart = gymT[j] + (gymU[j] + gymR[j]) * n;

        // if gym has to wait for jim, update gym.
        if (jimEnd > gymNextStart && gymNextStart > jimStart) {
            gymT[j] = time - jimR[j];
        }
    }
    // last rest no count
    time -= jimR[9];
    cout << time << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}