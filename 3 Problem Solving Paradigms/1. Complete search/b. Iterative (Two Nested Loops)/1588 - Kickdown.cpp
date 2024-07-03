#include <bits/stdc++.h>

using namespace std;

// worst case is when small string cannot fit in longer string, then need print length of short + long
// best case is when fit in, then print length of long

// steps:
// take the shorter string, put it at left of longer string
// push shorter string 1 char to the right until it exits the longer string
// record the length of the overlap and break if overlap == length of shorter string (can fit in, means ans is length of longer string)
// overlap is when each char of short + long <= 3. if short + long > 3 can skip this cuz it doesn't fit

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string shortStr, longStr;
    while (cin >> shortStr >> longStr) {
        // slow but length <= 100
        if (shortStr.size() > longStr.size()) swap(shortStr, longStr);
        unsigned long long totalLen = shortStr.size() + longStr.size();
        string padding1(longStr.size(), '0'), padding2(shortStr.size(), '0');
        string shortStr1 = padding1.append(shortStr);
        string longStr1 = longStr + padding2;
        // "00000000002212112"
        // "21121121120000000"
        // it checks from left to right all the way until short string exits longer string
        int bestOverlap = 0;
        for (int i = 0; i < totalLen; i++) {
            int overlap = 0, flag = 0;
            for (int j = 0; j < shortStr1.size(); j++) {
                if (shortStr1[j] == '0' || longStr1[j] == '0') {
                    // gears not touching, just padded . do nothing
                } else if (shortStr1[j] == '2' && longStr1[j] == '2') {
                    // gears cannot fit
                    flag = 1;
                    break;
                } else {
                    // gears can fit
                    overlap++;
                }
            }
            if (flag == 1) {
                // gears cannot fit. shift strings and try again
                shortStr1 = shortStr1.substr(1, shortStr1.size() - 1); // remove 1st char
                longStr1.pop_back(); // remove last char
                continue;
            }
            // if completely overlap, then break
            if (overlap == shortStr.size()) {
                bestOverlap = overlap;
                break;
            }
            // update bestOverlap if current overlap is better
            if (overlap > bestOverlap) {
                bestOverlap = overlap;
            }
            // shift strings
            shortStr1 = shortStr1.substr(1, shortStr1.size() - 1); // remove 1st char
            longStr1.pop_back(); // remove last char
        }
        unsigned long long juttingOut = shortStr.size() - bestOverlap;
        cout << longStr.size() + juttingOut << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
