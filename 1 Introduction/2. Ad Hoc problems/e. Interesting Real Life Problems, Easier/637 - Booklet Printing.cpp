#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    while(cin >> n, n) {
        // let top be count ascending, bot be count descending
        // count until top meets bot
        // really should check the results for 1-10 to see clear pattern
        int blank, sheet = 1, top = 1, bot = n;
        blank = 4 - n%4; // e.g. 5 pages need 2 sheets, blanks = 2*4 - 5 = 3
        cout << "Printing order for " << n << " pages:" << endl;
        if (n == 1){
            cout << "Sheet 1, front: Blank, 1" << endl;
            continue;
        }
        else if(blank == 1) {
            cout << "Sheet 1, front: Blank, 1" << endl;
            cout << "Sheet " << sheet << ", back : " << top+1 << ", " << bot << endl;
            sheet++;
            top += 2;
            bot--;
        }
        else if (blank == 2) {
            cout << "Sheet 1, front: Blank, 1" << endl;
            cout << "Sheet 1, back : 2, Blank" << endl;
            sheet++;
            top += 2;
        }
        else if (blank == 3){
            cout << "Sheet 1, front: Blank, 1" << endl;
            cout << "Sheet 1, back : 2, Blank" << endl;
            cout << "Sheet 2, front: Blank, 3" << endl;
            cout << "Sheet 2, back : 4, " << bot << endl;
            sheet += 2;
            top += 4;
            bot--;
        }
        while(top < bot) {
            cout << "Sheet " << sheet << ", front: " << bot << ", " << top << endl;
            cout << "Sheet " << sheet << ", back : " << top+1 << ", " << bot-1 << endl;
            top += 2;
            bot -= 2;
            sheet++;
        }


    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

