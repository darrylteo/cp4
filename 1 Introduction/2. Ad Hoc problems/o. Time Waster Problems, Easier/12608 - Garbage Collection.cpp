#include <bits/stdc++.h>

using namespace std;

// consider using global vars and updating each move like goToDump, loadGarbage etc.

struct garbage {
    int distance, weight;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    while (T--) {
        int W, N;
        cin >> W >> N;
        vector<garbage> garbageList(N);
        for (int i = 0; i < N; i++) {
            cin >> garbageList[i].distance >> garbageList[i].weight;
        }
        int weight = 0, pickUp = 0, totalWeight = 0, distance = 0, garbageCount = 0, currDistance = 0;
        totalWeight = accumulate(garbageList.begin(), garbageList.end(), 0, [](int sum, garbage g) {
            return sum + g.weight;
        });
        while (garbageCount < totalWeight) { // while there is garbage to collect
            while (garbageList[pickUp].weight == 0) { // search for next pickup point index
                pickUp++;
            }
            distance += garbageList[pickUp].distance - currDistance; // add to total distance
            currDistance = garbageList[pickUp].distance; // update current distance
            if (weight + garbageList[pickUp].weight <= W) { // if truck can carry all garbage
                weight += garbageList[pickUp].weight; // load garbage
                garbageCount += garbageList[pickUp].weight; // update garbage count
                garbageList[pickUp].weight = 0; // don't visit this pickup point again
                if (weight == W) { // if truck is full
                    distance += currDistance; // move to dump point
                    currDistance = 0; // update current distance
                    weight = 0; // empty truck
                }
            } else { // if truck cannot carry all garbage
                distance += currDistance; // move to dump point
                currDistance = 0; // update current distance
                weight = 0; // empty truck
            }
        }
        distance += currDistance; // move to dump point
        cout << distance << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}