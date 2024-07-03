#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--) {
        vector<int> digits, doubled_digits;
        string d;
        int sum = 0;
        cin >> d;
        // if even
        if (d.size() % 2 == 0) {
            // get digits to double
            for (int i = 0; i < d.size(); i += 2) {
                digits.push_back(d[i] - '0');
            }
            // add digits that do not need to be doubled
            for (int i = 1; i < d.size(); i += 2) {
                sum += d[i] - '0';
            }
        } else {
            // get digits to double
            for (int i = 1; i < d.size(); i += 2) {
                digits.push_back(d[i] - '0');
            }
            // add digits that do not need to be doubled
            for (int i = 0; i < d.size(); i += 2) {
                sum += d[i] - '0';
            }
        }

        // double digits
        for (int i = 0; i < digits.size(); i++) {
            int doubled = digits[i] * 2;
            // e.g. 14 -> 1 + 4
            if (doubled > 9) {
                doubled_digits.push_back(doubled / 10); // 1
                doubled_digits.push_back(doubled % 10); // 4
            } else {
                doubled_digits.push_back(doubled);
            }
        }
        // add doubled digits
        for (int i = 0; i < doubled_digits.size(); i++) {
            sum += doubled_digits[i];
        }
        // check if valid
        if (sum % 10 == 0) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
