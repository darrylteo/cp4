#include <bits/stdc++.h>

using namespace std;

// reuse code from 735 - Dart-a-Mania.cpp

void printVal(int val) {
    if (val == 0) {

    } else if (val <= 20) {
        cout << "single " << val << endl;
    } else if (val <= 40 && val % 2 == 0) {
        cout << "double " << val / 2 << endl;
    } else {
        cout << "triple " << val / 3 << endl;
    }
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // based on last example, can miss
    // also, cannot bullseye
    set<int> possibleValues;
    for (int i = 0; i <= 20; ++i) {
        possibleValues.insert(i);
        possibleValues.insert(i * 2);
        possibleValues.insert(i * 3);
    }

    int n;
    cin >> n;
    int permutations = 0;
    vector<int> v;

    // all breaks are optional
    for (int i1: possibleValues) {
        if (i1 > n) {
            break;
        }
        for (int i2: possibleValues) {
            if (i1 + i2 > n) {
                break;
            }
            if (i1 + 60 + 60 < n) {
                break;
            }
            for (int i3: possibleValues) {
                if (i1 + i2 + 60 < n) { // exit if i1 and i2 too small
                    break;
                }
                if (i1 + i2 + i3 > n) { // exit if dunnid check rest of i3
                    break;
                }
                if (i1 + i2 + i3 == n) {
                    v = {i1, i2, i3};
                    break;
                }
            }
        }
    }
    if (v.empty()) {
        cout << "impossible" << endl;
    } else {
        for (int i: v) {
            printVal(i);
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
