#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string game;
    getline(cin, game);
    while (game != "Game Over") {
        vector<int> scores;
        vector<char> games;
        int frame = 1, roll = 1, score = 0;
        stringstream ss(game);
        char c;
        while (ss >> c) {
            games.push_back(c);
            if (c == 'X') {
                scores.push_back(10);
            } else if (c == '/') {
                scores.push_back(10 - scores.back());
            } else {
                scores.push_back(c - '0');
            }
        }
        for (int i = 0; i < games.size(); i++) {
            if (frame < 10){
                if (games[i] == 'X'){
                    score += scores[i] + scores[i+1] + scores[i+2];
                } else if (games[i] == '/'){
                    score += scores[i] + scores[i+1];
                } else {
                    score += scores[i];
                }
            } else {
                score += scores[i];
            }

            // get which frame we are in... using 1-indexing
            roll++;
            if (games[i] == 'X' || roll == 3){
                frame++;
                roll = 1;
            }

        }

        cout << score << endl;


        getline(cin, game);
    }





    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

