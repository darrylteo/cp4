#include <bits/stdc++.h>

using namespace std;

int N;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> N;
    while (N--){
        int a, b, c;
        cin >> a >> b >> c;

        // don't do anything if no players, just clear input
        if (a == 0){
            for (int i = 0; i < b; i++){
                int x, y;
                cin >> x >> y;
            }
            for (int i = 0; i < c; i++){
                int x;
                cin >> x;
            }
            continue;
        }

        vector<int> playerPos;
        vector<vector<int>> SnL;

        // all players start at 1
        for (int i = 0; i < a; i++){
            playerPos.push_back(1);
        }

        // snakes and ladders
        for (int i = 0; i < b; i++){
            int x, y;
            cin >> x >> y;
            vector<int> temp;
            temp.push_back(x);
            temp.push_back(y);
            SnL.push_back(temp);
        }

        // dice rolls
        int x[c+10];
        for (int i = 0; i < c; i++){
            cin >> x[i];
        }
        for (int i = 0; i < c; i++){
            int y = x[i];
            playerPos[i % a] += y;
            for (int j = 0; j < SnL.size(); j++){
                if (playerPos[i % a] == SnL[j][0]){
                    playerPos[i % a] = SnL[j][1];
                    break; // only one snake or ladder per turn
                }
            }
            if (playerPos[i % a] >= 100){
                playerPos[i % a] = 100;
                break; // game ends when 1 person wins
            }
        }

        // output
        for (int i = 0; i < a; i++){
            cout << "Position of player " << i + 1 << " is " << playerPos[i] << "." << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

