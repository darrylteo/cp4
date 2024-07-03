#include <bits/stdc++.h>

using namespace std;

int C;
string S, T;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> C;
    for (int k = 1; k <= C; k++){
        cout << "Case " << k << ": ";
        cin >> S >> T;
        // we first check if problem is feasible by counting no. of 0s in T and S
        // if no. of '0' in T is more than no. of '0' + '?' in S, then it is not feasible
        int cntT0 = 0, cntS0 = 0, cntSQ = 0;
        for (int i = 0; i < T.size(); i++){
            if (T[i] == '0') cntT0++;
        }
        for (int i = 0; i < S.size(); i++){
            if (S[i] == '0') cntS0++;
            else if (S[i] == '?') cntSQ++;
        }
        if (cntT0 > cntS0 + cntSQ){
            cout << -1 << endl;
            continue;
        }
        int qTo0 = cntT0 - cntS0; // no. of ? to be converted to 0
        int qTo1 = cntSQ - qTo0; // no. of ? to be converted to 1
        int noOfDiff = 0; // no. of different bits
        // fill up S with correct ? to 0 and 1
        for (int i = 0; i < S.size(); i++){
            if (S[i] == '?' && T[i] == '0'){
                if (qTo0 > 0){
                    S[i] = '0';
                    qTo0--;
                }
                else if (qTo1 > 0){
                    S[i] = '1';
                    qTo1--;
                }
            } else if (S[i] == '?' && T[i] == '1'){
                if (qTo1 > 0){
                    S[i] = '1';
                    qTo1--;
                }
                else if (qTo0 > 0){
                    S[i] = '0';
                    qTo0--;
                }
            }
            if (S[i] != T[i]) noOfDiff++;
        }
        int ans = cntSQ; // for sure must convert all ? to 0 or 1
        int noOf0to1 = max(0, cntS0 - cntT0); // no. of 0 to be converted to 1 (move 1)
        int noOfSwaps = (noOfDiff - noOf0to1) / 2; // no. of swaps needed to move 1 and 0
        cout << ans + noOf0to1 + noOfSwaps << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

