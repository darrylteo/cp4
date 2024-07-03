#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--){
        double R, B, M;
        int interest;
        cin >> R >> B >> M;

        int month = 1;
        while (month <= 1200){
            interest = static_cast<int>(round(B * R)); // in cents
            B += interest/100.0;
            B = round(B * 100) / 100; // get B back to cents
            B -= M;
            if (B <= 0){
                break;
            }
            month++;
        }
        if (month > 1200){
            cout << "impossible" << endl;
        }
        else{
            cout << month << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
