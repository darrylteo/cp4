#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // first launch month = 4, year = 2018
    // advance 2 years and 2 months... say normalize year 2018 = 0
    // so some examples of "yes"
    // year = 2, month = 6
    // year = 4, month = 8
    // year = 6, month = 10
    // year = 8, month = 12
    // year = 11, month = 2
    // year = 13, month = 4
    // year = 15, month = 6
    // year = 17, month = 8
    // year = 19, month = 10
    // year = 21, month = 12
    // year = 24, month = 2
    // make this into simple pattern: 0, 2, 4, 6, 8 @@ 11, 13, 15, 17, 19, 21 @@ 24
    // first set 0-9 even are yes, odd are no
    // second set 10-22 even are no, odd are yes


    int yearTest, year, n;

        cin >> yearTest;
        year = yearTest - 2018;

        n = (year - 9) / 13.0 + 0.99; // 0.99 instead of 1 so 9 goes into set 0, 10 goes into set 1 etc
        if (n % 2 == 0 || n < 0){
            if (year % 2 == 0) cout << "yes" << endl;
            else cout << "no" << endl;
        } else {
            if (year % 2 == 0) cout << "no" << endl;
            else cout << "yes" << endl;
        }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}