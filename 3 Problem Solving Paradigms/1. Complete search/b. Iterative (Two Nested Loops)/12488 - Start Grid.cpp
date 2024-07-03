#include <bits/stdc++.h>

using namespace std;

// small N just brute force
// for each CAR in 1st vector, check who is in front of him and add to frontal vector
// for each car in frontal vector, check if CAR is in front of him. if yes add overtakeCnt

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<int> car1, car2, frontal;
        int overtakeCnt = 0;
        for (int i = 0; i < n; ++i) {
            int car;
            cin >> car;
            car1.push_back(car);
        }
        for (int i = 0; i < n; ++i) {
            int car;
            cin >> car;
            car2.push_back(car);
        }
        // 1st car could not overtake anyone
        for (int i = 1; i < n; ++i) {
            frontal.clear();
            for (int j = 0; j < i; ++j) {
                frontal.push_back(car1[j]);
            }
            // check if car1[i] is in front of any car in frontal at end of race
            for (int car : frontal) {
                if (find(car2.begin(), car2.end(), car) > find(car2.begin(), car2.end(), car1[i])) {
                    overtakeCnt++;
                }
            }
        }
        cout << overtakeCnt << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
