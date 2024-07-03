#include <bits/stdc++.h>

using namespace std;

int N;

// failed to consider what happens when score 2 bingo at the same time.. waste 2h sad
// baby level bitset, nvr check how to compare contains at least same 1-bits

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> N;
    while (N--) {
        // count from the top to bottom, from left to right
        int num, numCount = 0, flag = 0;
        bitset<25> arr = 0;
        arr[12] = true; // free space
        vector<int> bingoCard;
        for (int i = 0; i < 12; i++) {
            cin >> num;
            bingoCard.push_back(num);
        }
        bingoCard.push_back(-1); // free space
        for (int i = 0; i < 12; i++) {
            cin >> num;
            bingoCard.push_back(num);
        }
        // read numbers up to 75 to clear buffer
        for (int k = 0; k < 75; ++k) {
            cin >> num;
            if (flag) continue;
            numCount++;
            for (int i = 0; i < bingoCard.size(); i++) {
                if (bingoCard[i] == num) {
                    arr[i] = true;
                    break;
                }
            }
            // check for bingo
            // check rows
            for (int i = 0; i < 25; i += 5) {
                if (arr[i] && arr[i + 1] && arr[i + 2] && arr[i + 3] && arr[i + 4]) {
                    cout << "BINGO after " << numCount << " numbers announced" << endl;
                    flag = 1;
                    break;
                }
            }
            // check columns
            for (int i = 0; i < 5; i++) {
                if (arr[i] && arr[i + 5] && arr[i + 10] && arr[i + 15] && arr[i + 20] && !flag) {
                    cout << "BINGO after " << numCount << " numbers announced" << endl;
                    flag = 1;
                    break;
                }
            }
            // check diagonals
            if (arr[0] && arr[6] && arr[12] && arr[18] && arr[24] && !flag) {
                cout << "BINGO after " << numCount << " numbers announced" << endl;
                flag = 1;
            }
            if (arr[4] && arr[8] && arr[12] && arr[16] && arr[20] && !flag) {
                cout << "BINGO after " << numCount << " numbers announced" << endl;
                flag = 1;
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

