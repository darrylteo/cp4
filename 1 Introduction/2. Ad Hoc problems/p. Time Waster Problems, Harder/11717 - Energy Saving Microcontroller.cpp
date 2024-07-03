#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T, caseNum = 1;
    cin >> T;
    while (T--) {
        cout << "Case " << caseNum++ << ": ";
        int n, i, k;
        cin >> n >> i >> k;
        vector<int> instructions;
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            instructions.push_back(tmp);
        }

        int inactiveCnt = 0, ignoreCnt = 0, currTime = 0, STATE = 1;
        // STATE: 0 = inactive, 1 = active
        for (int j = 0; j < n; ++j) {
            // check this after completing previous job
            // i.e. currTime should be updated to the time when the previous job is completed
            if (instructions[j] - currTime >= i) {
                STATE = 0;
                inactiveCnt++;
            }
            currTime = instructions[j];
            // perform current job as well as check how many to ignore... increment j
            // if state == 0 means have startup time and might ignore some jobs
            if (STATE == 0) {
                j++; // check next time onwards
                while (j < n) {
                    if (instructions[j] - currTime < k) {
                        ignoreCnt++;
                        j++;
                    } else {
                        break;
                    }
                }
                j--; // outer for loop will increment j
            }

            // update time
            if (STATE == 0) {
                currTime += k;
            }
            STATE = 1; // active just after finish a job
        }
        cout << inactiveCnt << " " << ignoreCnt << endl;

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}