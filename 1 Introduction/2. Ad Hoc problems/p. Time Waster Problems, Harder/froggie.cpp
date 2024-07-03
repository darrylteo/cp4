#include <bits/stdc++.h>

using namespace std;

struct lane {
    int offset, interval, speed;
    vector<int> carsOldPos, carsNewPos;
    bool isLeft;
};


int L, W, frogPos, frogLane;

void initializeCars(vector<lane> &lanes) {
    for (int i = 0; i < L; i++) {
        if (lanes[i].isLeft) { // cars start from right + offset
            int pos = W - 1 - lanes[i].offset;
            while (pos >= 0) { // find first car on left
                pos -= lanes[i].interval;
            }
            pos += lanes[i].interval; // add to account for the minus in loop
            while (pos < W) { // add as before
                lanes[i].carsOldPos.push_back(pos);
                lanes[i].carsNewPos.push_back(pos);
                pos += lanes[i].interval;
            }
        } else { // cars start from left + offset
            int pos = lanes[i].offset;
            while (pos < W) {
                lanes[i].carsOldPos.push_back(pos);
                lanes[i].carsNewPos.push_back(pos);
                pos += lanes[i].interval;
            }

        }

    }
}

void updateMap(vector<lane> &lanes) {

    for (int i = 0; i < L; i++) {
        vector<int> newPos;
        vector<int> oldPos;
        if(lanes[i].isLeft){
            int leftest = *min_element(lanes[i].carsNewPos.begin(), lanes[i].carsNewPos.end());
            leftest -= lanes[i].speed;
            // set the first car (after moving left), then add each car separated by interval
            while (leftest < W) {
                newPos.push_back(leftest);
                leftest += lanes[i].interval;
            }
            // set old pos based on new pos - speed
            for (int j = 0; j < newPos.size(); j++) {
                oldPos.push_back(newPos[j] + lanes[i].speed);
            }
        } else {
            int rightest = *max_element(lanes[i].carsNewPos.begin(), lanes[i].carsNewPos.end());
            rightest += lanes[i].speed;
            // set the first car (after moving right), then add each car separated by interval
            while (rightest >= 0) {
                newPos.push_back(rightest);
                rightest -= lanes[i].interval;
            }
            // set old pos based on new pos + speed
            for (int j = 0; j < newPos.size(); j++) {
                oldPos.push_back(newPos[j] - lanes[i].speed);
            }
        }
        // update carsOldPos and carsNewPos
        lanes[i].carsOldPos = oldPos;
        lanes[i].carsNewPos = newPos;
    }

}

bool isSquished(lane oneLane) {
    int carOldPos, carNewPos;
    for (int i = 0; i < oneLane.carsOldPos.size(); i++) {
        carOldPos = oneLane.carsOldPos[i];
        carNewPos = oneLane.carsNewPos[i];
        if (carOldPos == carNewPos) {
            if (frogPos == carNewPos) {
                return true;
            }
        } else if (!oneLane.isLeft) {
            // for cars that "exited and reentered", check up to left border
            if (carNewPos < oneLane.interval && carOldPos > carNewPos) {
                while (carNewPos >= 0) {
                    if (frogPos == carNewPos) {
                        return true;
                    }
                    carNewPos--;
                }
            } else {
                while (carNewPos >= carOldPos + 1) {
                    if (frogPos == carNewPos) {
                        return true;
                    }
                    carNewPos--;
                }
            }

        } else if (oneLane.isLeft) {
            // for cars that "exited and reentered", check up to right border
            if (carNewPos > W - 1 - oneLane.interval && carOldPos < carNewPos) {
                while (carNewPos <= W - 1) {
                    if (frogPos == carNewPos) {
                        return true;
                    }
                    carNewPos++;
                }
            } else {
                while (carNewPos <= carOldPos - 1) {
                    if (frogPos == carNewPos) {
                        return true;
                    }
                    carNewPos++;
                }
            }
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int left = 0;
    bool dead = false;
    string instructions;
    cin >> L >> W;
    vector<lane> lanes(L);
    // setup lanes, top lane is lane[0]
    for (int i = 0; i < L; i++) {
        cin >> lanes[i].offset >> lanes[i].interval >> lanes[i].speed;
        lanes[i].isLeft = (left);
        left = 1 - left;
    }
    initializeCars(lanes); // initialize carsOldPos and carsNewPos
    cin >> frogPos; // 0 is left
    frogLane = L; // start from bottom lane
    cin >> instructions;

    for (int i = 0; i < instructions.length(); i++) {
        if (instructions[i] == 'U') {
            frogLane--;
        } else if (instructions[i] == 'D') {
            frogLane++;
        } else if (instructions[i] == 'L') {
            frogPos--;
        } else if (instructions[i] == 'R') {
            frogPos++;
        }
        updateMap(lanes);
        if (frogLane == -1) break; // froggie reached top lane
        if (frogLane == L) continue; // froggie is in pond (no cars)
        if (frogPos < 0 || frogPos >= W || frogLane >= L) { // froggie is outside the path
            dead = true;
            break;
        }
        // froggie on road. check for cars
        lane oneLane = lanes[frogLane];
        if (isSquished(oneLane)) {
            dead = true;
            break;
        }
    }

    if (frogLane != -1) dead = true; // froggie didn't reach top lane
    if (dead) cout << "squish" << endl;
    else cout << "safe" << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}