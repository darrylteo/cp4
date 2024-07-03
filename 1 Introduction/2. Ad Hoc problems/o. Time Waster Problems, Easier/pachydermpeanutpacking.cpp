#include <bits/stdc++.h>

using namespace std;

struct box {
    string size;
    double x1, y1, x2, y2;
};

// print the information for just this peanut
void printPeanut(const vector<box>& boxes, tuple<string, double, double> peanut){
    string peanutType = get<0>(peanut); // size
    double x = get<1>(peanut); // x coordinate
    double y = get<2>(peanut); // y coordinate
    cout << peanutType << " ";

    // find the box that this peanut fits in
    string boxType = "floor";
    for (const auto & box : boxes) {
        if (x >= box.x1 && x <= box.x2 && y >= box.y1 && y <= box.y2){
            boxType = box.size;
            break;
        }
    }

    if (peanutType == boxType){
        cout << "correct" << endl;
    } else {
        cout << boxType << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, first = 1;
    while (cin >> n, n){
        if (!first){
            cout << endl;
        }
        first = 0;

        double x1, y1, x2, y2;
        string s;
        vector<box> boxes; // learning to use struct

        // setup boxes for this test case
        for (int i = 0; i < n; ++i) {
            cin >> x1 >> y1 >> x2 >> y2 >> s;
            boxes.push_back({s, x1, y1, x2, y2});
        }
        // setup peanuts for this test case
        int m;
        cin >> m;
        vector<tuple<string, double, double>> peanuts(m);
        for (int i = 0; i < m; ++i) {
            cin >> x1 >> y1 >> s;
            peanuts[i] = {s, x1, y1};
        }
        // print 1 peanut at a time
        for (int i = 0; i < m; ++i) {
            printPeanut(boxes, peanuts[i]);
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}