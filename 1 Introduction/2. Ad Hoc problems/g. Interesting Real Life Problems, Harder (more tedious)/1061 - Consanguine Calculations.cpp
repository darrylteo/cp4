#include <bits/stdc++.h>

using namespace std;

string getChild(const string& parent1, const string& parent2) {
    string p1, p2, child = "{";
    // replace blood type AB with C so only read 1 char
    if (parent1.length() == 3) p1 = "C" + parent1.substr(2, 1);
    else p1 = parent1;
    if (parent2.length() == 3) p2 = "C" + parent2.substr(2, 1);
    else p2 = parent2;

    int i = 1; // i == 0 means child must be negative Rh
    if (p1[1] == '-' && p2[1] == '-') i = 0;

    // 4 case, A B C O... 4C2 with replacement = 10 cases
    if (p1[0] == 'A' && p2[0] == 'A') {
        if (i == 0) child += "O-, A-, ";
        else child += "O-, O+, A-, A+, ";
    }
    else if (p1[0] == 'A' && p2[0] == 'B' || p1[0] == 'B' && p2[0] == 'A') {
        if (i == 0) child += "O-, AB-, B-, A-, ";
        else child += "O-, O+, AB-, AB+, B-, B+, A-, A+, ";
    }
    else if (p1[0] == 'A' && p2[0] == 'C' || p1[0] == 'C' && p2[0] == 'A') {
        if (i == 0) child += "AB-, B-, A-, ";
        else child += "AB-, AB+, B-, B+, A-, A+, ";
    }
    else if (p1[0] == 'A' && p2[0] == 'O' || p1[0] == 'O' && p2[0] == 'A') {
        if (i == 0) child += "O-, A-, ";
        else child += "O-, O+, A-, A+, ";
    }
    else if (p1[0] == 'B' && p2[0] == 'B') {
        if (i == 0) child += "O-, B-, ";
        else child += "O-, O+, B-, B+, ";
    }
    else if (p1[0] == 'B' && p2[0] == 'C' || p1[0] == 'C' && p2[0] == 'B') {
        if (i == 0) child += "AB-, B-, A-, ";
        else child += "AB-, AB+, B-, B+, A-, A+, ";
    }
    else if (p1[0] == 'B' && p2[0] == 'O' || p1[0] == 'O' && p2[0] == 'B') {
        if (i == 0) child += "O-, B-, ";
        else child += "O-, O+, B-, B+, ";
    }
    else if (p1[0] == 'C' && p2[0] == 'C') {
        if (i == 0) child += "AB-, B-, A-, ";
        else child += "AB-, AB+, B-, B+, A-, A+, ";
    }
    else if (p1[0] == 'C' && p2[0] == 'O' || p1[0] == 'O' && p2[0] == 'C') {
        if (i == 0) child += "B-, A-, ";
        else child += "B-, B+, A-, A+, ";
    }
    else if (p1[0] == 'O' && p2[0] == 'O') {
        if (i == 0) child += "O-, ";
        else child += "O-, O+, ";
    }

    // remove last 2 chars
    child.pop_back();
    child.pop_back();
    child += "}";

    // special case if only 1 result {O-}
    if (child.length() == 4) child = child.substr(1, 2);

    return child;
}

const vector<string> bloodType = {"O-", "O+", "AB-", "AB+", "B-", "B+", "A-", "A+"};

string getParent(const string& parent, const string& child){
    string p, parentPrint = "{", childPrint;
    if (parent.length() == 3) p = "C" + parent.substr(2, 1);
    else p = parent;

    for (string s : bloodType){
        childPrint = getChild(s, p);
        // if possible parent for child
        if (childPrint.find(child) != string::npos){
            parentPrint += s + ", ";
        }
    }

    // if no possible parent
    if (parentPrint.length() == 1) return "IMPOSSIBLE";

    // else remove last 2 chars
    parentPrint.pop_back();
    parentPrint.pop_back();
    parentPrint += "}";

    return parentPrint;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string parent1, parent2, child;
    int i = 0;
    while (cin >> parent1 >> parent2 >> child && parent1 != "E"){
        if (child == "?") {
            child = getChild(parent1, parent2);
        } else if (parent1 == "?") {
            parent1 = getParent(parent2, child);
        } else if (parent2 == "?") {
            parent2 = getParent(parent1, child);
        }

        cout << "Case " << ++i << ": " << parent1 << " " << parent2 << " " << child << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
