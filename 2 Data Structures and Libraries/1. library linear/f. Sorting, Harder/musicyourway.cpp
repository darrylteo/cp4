#include <bits/stdc++.h>

using namespace std;

// we use getline for all input for consistency

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // get attributes
    string buf;
    vector<string> attributes;
    getline(cin, buf);
    stringstream ss(buf);
    while (ss >> buf) {
        attributes.push_back(buf);
    }
    // get songs
    int n;
    vector<vector<string>> songs;
    getline(cin, buf);
    n = stoi(buf);
    while (n--) {
        getline(cin, buf);
        stringstream ss(buf);
        vector<string> song;
        while (ss >> buf) {
            song.push_back(buf);
        }
        songs.push_back(song);
    }
    // get queries (don't go back to original list, the sort is consecutive)
    getline(cin, buf);
    n = stoi(buf);
    while (n--) {
        getline(cin, buf);
        int attrNo = 0;
        for (int i = 0; i < attributes.size(); i++) {
            if (attributes[i] == buf) {
                attrNo = i;
                break;
            }
        }
        stable_sort(songs.begin(), songs.end(), [&attrNo](vector<string> a, vector<string> b) {
            return a[attrNo] < b[attrNo];
        });
        for (int i = 0; i < attributes.size(); ++i) {
            cout << attributes[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < songs.size(); i++) {
            for (int j = 0; j < songs[i].size(); j++) {
                cout << songs[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
