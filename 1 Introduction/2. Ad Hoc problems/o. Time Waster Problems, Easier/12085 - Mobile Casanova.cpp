#include <bits/stdc++.h>

using namespace std;

void printRange(long long start, long long end) {
    string startString = to_string(start);
    string endString = to_string(end);
    int sameMaxIdx = 0;
    for (int i = 0; i < startString.length(); i++) {
        if (startString[i] == endString[i]) {
            sameMaxIdx = i;
        } else {
            break;
        }
    }

    //  if sameMaxIdx is the first idx, see the loop above we cant account for i = 0
    // that means there's 2 cases for i = 0
    // we have to print the full endstring
    if(sameMaxIdx == 0 && startString[0] != endString[0]) {
        cout << "0" << startString << "-" << endString << endl;
        return;
    }
    cout << "0" << startString << "-" << endString.substr(sameMaxIdx + 1) << endl;

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int cases = 1, n;
    while (cin >> n) {
        if (n != 0) cout << "Case " << cases++ << ":" << endl;
        if (n == 0) break;
        long long number;
        vector<long long> numbers;
        for (int i = 0; i < n; i++) {
            cin >> number;
            numbers.push_back(number); // remember to add 0 in front later
        }

        for (int i = 0; i < n - 1; i++) {
            if (numbers[i] + 1 == numbers[i + 1]) {
                int start = i;
                while (numbers[i] + 1 == numbers[i + 1]) {
                    i++;
                }
                printRange(numbers[start], numbers[i]);
            } else {
                cout << "0" << numbers[i] << endl;
            }
        }

        //  if not included in last range, print last number
        if(numbers[n-2] + 1 != numbers[n-1]) {
            cout << "0" << numbers[n-1] << endl;
        }

        cout << endl;

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}