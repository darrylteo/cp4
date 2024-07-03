#include <bits/stdc++.h>

using namespace std;

int N;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &N);
    N--; // wow so lame last line cannot leave extra line... cause of presentation error
    while (N--) {
        cin.ignore();
        vector<char> johnUp, johnDown, janeUp, janeDown;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            janeDown.push_back(s[i]);
        }
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            johnDown.push_back(s[i]);
        }

        int rounds = 1000;
        while (rounds--) {

            // if john wins
            if (johnDown.size() == 0 && johnUp.size() == 0) {
                cout << "Jane wins." << endl << endl;
                break;
            }
            // if jane wins
            if (janeDown.size() == 0 && janeUp.size() == 0) {
                cout << "John wins." << endl << endl;
                break;
            }

            // if john face down pile exhausted
            if (johnDown.size() == 0) {
                // flip johnUp and put it in johnDown
                vector<char> tmp;
                for (int i = 0; i < johnUp.size(); i++) {
                    tmp.push_back(johnUp[i]);
                }
                reverse(tmp.begin(), tmp.end());
                johnDown = tmp;
                johnUp.clear();
            }
            // if jane face down pile exhausted
            if (janeDown.size() == 0) {
                // flip janeUp and put it in janeDown
                vector<char> tmp;
                for (int i = 0; i < janeUp.size(); i++) {
                    tmp.push_back(janeUp[i]);
                }
                reverse(tmp.begin(), tmp.end());
                janeDown = tmp;
                janeUp.clear();
            }

            // can start game if none of above applies
            // if they have same 1st card in down pile
            if (johnDown[0] == janeDown[0]) { // can compare characters
                // put card at top of pile (sort of push_front. inefficient but works)
                johnUp.insert(johnUp.begin(), johnDown[0]);
                janeUp.insert(janeUp.begin(), janeDown[0]);
                johnDown.erase(johnDown.begin());
                janeDown.erase(janeDown.begin());
                // if jane snaps
                if (rand() / 141 % 2 == 0) {
                    cout << "Snap! for Jane: ";
                    // update janeUp
                    vector<char> tmp;
                    for (int i = 0; i < johnUp.size(); i++) {
                        tmp.push_back(johnUp[i]);
                    }
                    for (int i = 0; i < janeUp.size(); i++) {
                        tmp.push_back(janeUp[i]);
                    }
                    janeUp = tmp;
                    for (int i = 0; i < janeUp.size(); i++) {
                        cout << janeUp[i];
                    }
                    cout << endl;
                    // update johnUp
                    johnUp.clear();
                } else { // if john snaps
                    cout << "Snap! for John: ";
                    // update johnUp
                    vector<char> tmp;
                    for (int i = 0; i < janeUp.size(); i++) {
                        tmp.push_back(janeUp[i]);
                    }
                    for (int i = 0; i < johnUp.size(); i++) {
                        tmp.push_back(johnUp[i]);
                    }
                    johnUp = tmp;
                    for (int i = 0; i < johnUp.size(); i++) {
                        cout << johnUp[i];
                    }
                    cout << endl;
                    // update janeUp
                    janeUp.clear();
                }
            } else {
                // put card at top of pile (sort of push_front. inefficient but works)
                johnUp.insert(johnUp.begin(), johnDown[0]);
                janeUp.insert(janeUp.begin(), janeDown[0]);
                johnDown.erase(johnDown.begin());
                janeDown.erase(janeDown.begin());
            }

        }
        if (rounds == -1) {
            cout << "Keeps going and going ..." << endl << endl;
        }
    }

    cin.ignore();
    vector<char> johnUp, johnDown, janeUp, janeDown;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        janeDown.push_back(s[i]);
    }
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        johnDown.push_back(s[i]);
    }

    int rounds = 1000;
    while (rounds--) {

        // if john wins
        if (johnDown.size() == 0 && johnUp.size() == 0) {
            cout << "Jane wins." << endl;
            break;
        }
        // if jane wins
        if (janeDown.size() == 0 && janeUp.size() == 0) {
            cout << "John wins." << endl;
            break;
        }

        // if john face down pile exhausted
        if (johnDown.size() == 0) {
            // flip johnUp and put it in johnDown
            vector<char> tmp;
            for (int i = 0; i < johnUp.size(); i++) {
                tmp.push_back(johnUp[i]);
            }
            reverse(tmp.begin(), tmp.end());
            johnDown = tmp;
            johnUp.clear();
        }
        // if jane face down pile exhausted
        if (janeDown.size() == 0) {
            // flip janeUp and put it in janeDown
            vector<char> tmp;
            for (int i = 0; i < janeUp.size(); i++) {
                tmp.push_back(janeUp[i]);
            }
            reverse(tmp.begin(), tmp.end());
            janeDown = tmp;
            janeUp.clear();
        }

        // can start game if none of above applies
        // if they have same 1st card in down pile
        if (johnDown[0] == janeDown[0]) { // can compare characters
            // put card at top of pile (sort of push_front. inefficient but works)
            johnUp.insert(johnUp.begin(), johnDown[0]);
            janeUp.insert(janeUp.begin(), janeDown[0]);
            johnDown.erase(johnDown.begin());
            janeDown.erase(janeDown.begin());
            // if jane snaps
            if (rand() / 141 % 2 == 0) {
                cout << "Snap! for Jane: ";
                // update janeUp
                vector<char> tmp;
                for (int i = 0; i < johnUp.size(); i++) {
                    tmp.push_back(johnUp[i]);
                }
                for (int i = 0; i < janeUp.size(); i++) {
                    tmp.push_back(janeUp[i]);
                }
                janeUp = tmp;
                for (int i = 0; i < janeUp.size(); i++) {
                    cout << janeUp[i];
                }
                cout << endl;
                // update johnUp
                johnUp.clear();
            } else { // if john snaps
                cout << "Snap! for John: ";
                // update johnUp
                vector<char> tmp;
                for (int i = 0; i < janeUp.size(); i++) {
                    tmp.push_back(janeUp[i]);
                }
                for (int i = 0; i < johnUp.size(); i++) {
                    tmp.push_back(johnUp[i]);
                }
                johnUp = tmp;
                for (int i = 0; i < johnUp.size(); i++) {
                    cout << johnUp[i];
                }
                cout << endl;
                // update janeUp
                janeUp.clear();
            }
        } else {
            // put card at top of pile (sort of push_front. inefficient but works)
            johnUp.insert(johnUp.begin(), johnDown[0]);
            janeUp.insert(janeUp.begin(), janeDown[0]);
            johnDown.erase(johnDown.begin());
            janeDown.erase(janeDown.begin());
        }

    }
    if (rounds == -1) {
        cout << "Keeps going and going ..." << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


