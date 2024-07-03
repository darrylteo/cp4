#include <bits/stdc++.h>

using namespace std;

// mistakes when debugging
// forgot check for bad char -1
// forgot that sep must be double not int
// wrong use of || and &&

// check if have more than 5% tolerance
// sep is value between min and max of widths
// for example range of 5% so we have 95 - 105 (original value 100)
// its bad if 105/105*95 > 95
bool checkTolerance(const vector<int> &widths, double sep) {
    vector<int> myWidths = widths;
    int min = 1000000000, max = 0;
    for (int i = 0; i < myWidths.size(); i++) {
        if (widths[i] < sep) myWidths[i] *= 2;
        if (myWidths[i] < min) min = myWidths[i];
        if (myWidths[i] > max) max = myWidths[i];
    }
    return min >= max / 105.0 * 95;
}

// make sure there is a thin line between each char, and total no. of bars is legal
bool checkSepBetweenChars(const vector<int> &widths, double sep) {
    // smallest barcode is start char1 C K stop
    if (widths.size() < 29) return false;
    if (widths.size() % 6 != 5) return false;
    // exclude last 5 widths
    for (int i = 0; i < widths.size() - 5; i += 6) {
        if (widths[i + 5] > sep) return false;
    }
    return true;
}


const vector<string> encoding = {"00001", "10001", "01001", "11000", "00101",
                                 "10100", "01100", "00011", "10010", "10000",
                                 "00100", "00110"};

int getChar(const string &s) {
    for (int i = 0; i < encoding.size(); i++) {
        if (s == encoding[i]) return i;
    }
    return -1;
}

// if -1, then error
// 10 is -, 11 is start/stop
vector<int> getChars(const vector<int> &widths, double sep) {
    vector<int> res;
    // read 5 widths at a time
    for (int i = 0; i < widths.size(); i += 6) {
        string s;
        for (int j = 0; j < 5; j++) {
            if (widths[i + j] < sep) s += '0';
            else s += '1';
        }
        res.push_back(getChar(s));
    }
    return res;
}

// 0 good code (0 errors)
// 1 bad code (general error)
// 2 bad code (wrong C)
// 3 bad code (wrong K)
int checkCKStartStop(const vector<int> &chars) {
    int n = static_cast<int>(chars.size());
    // ensure start/stop only at start and end
    if (chars[0] != 11 || chars[n - 1] != 11) return 1;
    for (int i = 1; i < n - 1; i++) {
        if (chars[i] == 11) return 1;
    }
    // make sure no bad characters
    for (int i = 0; i < n; i++) {
        if (chars[i] == -1) return 1;
    }

    // check if C is correct
    int sum = 0;
    // -3 is remove start/stop and 2 checks
    for (int i = 1; i < n - 3; i++) {
        sum += ((n - 4 - i) % 10 + 1) * chars[i];
    }
    if (sum % 11 != chars[n - 3]) return 2;

    // check if K is correct.. remove start/stop and 1 check
    sum = 0;
    for (int i = 1; i < chars.size() - 2; i++) {
        sum += ((n - 4 - i + 1) % 9 + 1) * chars[i];
    }
    if (sum % 11 != chars[n - 2]) return 3;

    return 0;
}

int printRes(const vector<int> &chars) {
    int errorCode = checkCKStartStop(chars);
    if (errorCode == 0) {
        for (int i = 1; i < chars.size() - 3; i++) {
            if (chars[i] == 10) cout << "-";
            else cout << chars[i];
        }
        cout << endl;
    } else if (errorCode == 2) cout << "bad C" << endl;
    else if (errorCode == 3) cout << "bad K" << endl;

    return errorCode;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int m, cases = 0;
    while (cin >> m && m != 0) {
        cout << "Case " << ++cases << ": ";
        vector<int> widths;
        int min = 1000000000;
        for (int i = 0; i < m; i++) {
            int w;
            cin >> w;
            widths.push_back(w);
            if (w < min) min = w;
        }
        double sep = min * 1.5;
        if (!checkTolerance(widths, sep) || !checkSepBetweenChars(widths, sep)) {
            cout << "bad code" << endl;
            continue;
        }

        vector<int> chars = getChars(widths, sep);
        if (printRes(chars) == 1) {
            // reverse widths
            reverse(widths.begin(), widths.end());
            chars = getChars(widths, sep);
            if (printRes(chars) == 1) cout << "bad code" << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
