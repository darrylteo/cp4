#include <bits/stdc++.h>

using namespace std;

struct point {
    int row, cFromLeft, cFromRight;
};

// get the distance between two points that are on the same row
// this is to be compared against when measuring distance between other points
int getDistance(vector<point> &points) {
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            if (points[i].row == points[j].row) {
                return abs(points[i].cFromLeft - points[j].cFromLeft);
            }
        }
    }
    return -1;
}

// slightly tedious but use drawing makes it clear

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> rowStart;
    rowStart.push_back(0);
    rowStart.push_back(1);
    for (int i = 1; i < 300; ++i) {
        rowStart.push_back(i * (i + 1) / 2 + 1);
    }
    string buf;
    while (getline(cin, buf)) {
        cout << buf << ' ';
        stringstream ss(buf);
        vector<int> a;
        int x;
        while (ss >> x) {
            a.push_back(x);
        }
        if (a.size() != 3 && a.size() != 4 && a.size() != 6) {
            cout << "are not the vertices of an acceptable figure\n";
            continue;
        }
        vector<point> points;
        for (int i = 0; i < a.size(); ++i) {
            int row = upper_bound(rowStart.begin(), rowStart.end(), a[i]) - rowStart.begin() - 1;
            int cFromLeft = a[i] - rowStart[row];
            int cFromRight = row - cFromLeft - 1;
            points.push_back({row, cFromLeft, cFromRight});
        }
        int distance = getDistance(points);
        if (distance == -1) {
            cout << "are not the vertices of an acceptable figure\n";
            continue;
        }
        // ok now make sure each point is connected to 2 other points with same dist for triangle and hexagon, and that the distance is same
        // for parallelogram, 2 or 3 points is ok. hexagon cannot more than 2 because it can work with 1 point in middle rather than normal at sides
        bool ok = true;
        for (int i = 0; i < points.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) continue;
                if (points[i].row == points[j].row) {
                    if (abs(points[i].cFromLeft - points[j].cFromLeft) == distance) cnt++;
                } else if ((points[i].cFromLeft == points[j].cFromLeft ||
                            points[i].cFromRight == points[j].cFromRight) &&
                           abs(points[i].row - points[j].row) == distance)
                    cnt++;
            }
            if (cnt != 2 && (a.size() == 3 || a.size() == 6)) {
                ok = false;
                break;
            }
            if (cnt < 2 && a.size() == 4) {
                ok = false;
                break;
            }
        }
        if (ok) {
            if (a.size() == 3) {
                cout << "are the vertices of a triangle\n";
            } else if (a.size() == 4) {
                cout << "are the vertices of a parallelogram\n";
            } else {
                cout << "are the vertices of a hexagon\n";
            }
        } else {
            cout << "are not the vertices of an acceptable figure\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}