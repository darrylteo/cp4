#include <bits/stdc++.h>

using namespace std;

int weightConvert(char c){
    int code = (int)c;
    int W = 0;
    while (code > 0){
        if (code % 2 == 0)
            W += 250;
        else
            W += 500;
        code >>= 1;
    }
    return W;
}

int stringToWeight(string s) {
    int weight = 0;
    for (int i = 0; i < s.size(); i++) {
        weight += weightConvert(s[i]);
    }
    return weight;
}

string pictureTilt(vector<string> picture) {
    if (picture[0][3] == '/') {
        return "right";
    } else if (picture[1][3] == '/') {
        return "equal";
    } else {
        return "left";
    }
}

// return left word, right word, acutal tilt
vector<string> pictureActualTilt(vector<string> picture, string tilt) {
    vector<string> results;
    string leftStr, rightStr;
    if (tilt == "left") {
        // could be more exact but this is good enough
        // it failed me in equal case :(
        for (int i = 0; i < picture[0].size(); ++i) {
            if (isalpha(picture[5][i])) {
                leftStr += picture[5][i];
            }
            if (isalpha(picture[3][i])) {
                rightStr += picture[3][i];
            }
        }
    }
    if (tilt == "right") {
        for (int i = 0; i < picture[0].size(); ++i) {
            if (isalpha(picture[3][i])) {
                leftStr += picture[3][i];
            }
            if (isalpha(picture[5][i])) {
                rightStr += picture[5][i];
            }
        }
    }
    if (tilt == "equal") {
        for (int i = 0; i < 8; ++i) {
            if (isalpha(picture[4][i])) {
                leftStr += picture[4][i];
            }
        }
        for (int i = 8; i < picture[0].size(); ++i) {
            if (isalpha(picture[4][i])) {
                rightStr += picture[4][i];
            }
        }
    }
    results.emplace_back(leftStr);
    results.emplace_back(rightStr);
    int leftWeight = stringToWeight(leftStr);
    int rightWeight = stringToWeight(rightStr);
    if (leftWeight > rightWeight) {
        results.emplace_back("left");
    } else if (leftWeight < rightWeight) {
        results.emplace_back("right");
    } else {
        results.emplace_back("equal");
    }
    return results;
}

void printMyPic(vector<string> myPic, vector<string> results) {
    if (results[2] == "left") {
        for (int i = 0; i < results[0].size(); ++i) {
            myPic[5][i+1] = results[0][i];
        }
        for (int i = 0; i < results[1].size(); ++i) {
            myPic[3][i+11] = results[1][i];
        }
    } else if (results[2] == "right") {
        for (int i = 0; i < results[0].size(); ++i) {
            myPic[3][i+1] = results[0][i];
        }
        for (int i = 0; i < results[1].size(); ++i) {
            myPic[5][i+11] = results[1][i];
        }
    } else {
        for (int i = 0; i < results[0].size(); ++i) {
            myPic[4][i+1] = results[0][i];
        }
        for (int i = 0; i < results[1].size(); ++i) {
            myPic[4][i+11] = results[1][i];
        }
    }

    for (int i = 0; i < 7; i++) {
        cout << myPic[i] << endl;
    }

}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // set up images
    vector<string> leftPic;
    vector<string> rightPic;
    vector<string> equalPic;
    leftPic.emplace_back("........||.../\\...");
    leftPic.emplace_back("........||../..\\..");
    leftPic.emplace_back(".../\\...||./....\\.");
    leftPic.emplace_back("../..\\..||/......\\");
    leftPic.emplace_back("./....\\.||\\______/");
    leftPic.emplace_back("/......\\||........");
    leftPic.emplace_back("\\______/||........");

    rightPic.emplace_back(".../\\...||........");
    rightPic.emplace_back("../..\\..||........");
    rightPic.emplace_back("./....\\.||.../\\...");
    rightPic.emplace_back("/......\\||../..\\..");
    rightPic.emplace_back("\\______/||./....\\.");
    rightPic.emplace_back("........||/......\\");
    rightPic.emplace_back("........||\\______/");

    equalPic.emplace_back("........||........");
    equalPic.emplace_back(".../\\...||.../\\...");
    equalPic.emplace_back("../..\\..||../..\\..");
    equalPic.emplace_back("./....\\.||./....\\.");
    equalPic.emplace_back("/......\\||/......\\");
    equalPic.emplace_back("\\______/||\\______/");
    equalPic.emplace_back("........||........");

    int T, caseNum = 1;
    cin >> T;
    while (T--) {
        cout << "Case " << caseNum++ << ":" << endl;
        vector<string> currPic;
        string s;
        for (int i = 0; i < 7; i++) {
            cin >> s;
            currPic.emplace_back(s);
        }
        cin >> s; // clear ------------------
        string currTilt = pictureTilt(currPic);
        vector<string> results = pictureActualTilt(currPic, currTilt);
        if (currTilt == results[2]) {
            cout << "The figure is correct." << endl;
        } else {
            vector<string> myPic;
            if (results[2] == "left") {
                myPic = leftPic;
                printMyPic(myPic, results);
            } else if (results[2] == "right") {
                myPic = rightPic;
                printMyPic(myPic, results);
            } else {
                myPic = equalPic;
                printMyPic(myPic, results);
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}