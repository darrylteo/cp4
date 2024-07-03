#include <bits/stdc++.h>

using namespace std;

struct window {
    int x, y, w, h, openOrder;
};

vector<window> windows;
int xMax, yMax, command, windowOrder;

void addWindow(int x, int y, int w, int h, int order) {
    window newWindow{};
    newWindow.x = x;
    newWindow.y = y;
    newWindow.w = w;
    newWindow.h = h;
    newWindow.openOrder = order;
    windows.push_back(newWindow);
}

bool overlap(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
    // check if one rectangle is on left side of other
    // touching is fine
    if (x1 + w1 <= x2 || x2 + w2 <= x1) {
        return false;
    }
    // check if one rectangle is above other
    if (y1 + h1 <= y2 || y2 + h2 <= y1) {
        return false;
    }
    return true;
}

void OPEN(int x, int y, int w, int h) {
    // check if beyond boundaries
    if (x + w > xMax || y + h > yMax) {
        cout << "Command " << command << ": OPEN - window does not fit" << endl;
        return;
    }
    // check if overlapping
    for (auto &window: windows) {
        if (overlap(window.x, window.y, window.w, window.h, x, y, w, h)) {
            cout << "Command " << command << ": OPEN - window does not fit" << endl;
            return;
        }
    }
    addWindow(x, y, w, h, windowOrder++);
}

void CLOSE(int x, int y) {
    bool found = false;
    for (int i = 0; i < windows.size(); i++) {
        if (x >= windows[i].x && x < windows[i].x + windows[i].w && y >= windows[i].y &&
            y < windows[i].y + windows[i].h) {
            windows.erase(windows.begin() + i);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Command " << command << ": CLOSE - no window at given position" << endl;
    }
}

void RESIZE(int x, int y, int w, int h) {
    bool found = false;
    for (int i = 0; i < windows.size(); i++) {
        if (x >= windows[i].x && x < windows[i].x + windows[i].w && y >= windows[i].y &&
            y < windows[i].y + windows[i].h) {
            // check if beyond boundaries
            if (windows[i].x + w > xMax || windows[i].y + h > yMax) {
                cout << "Command " << command << ": RESIZE - window does not fit" << endl;
                return;
            }
            // check if overlapping
            for (int j = 0; j < windows.size(); j++) {
                if (i != j &&
                    overlap(windows[j].x, windows[j].y, windows[j].w, windows[j].h, windows[i].x, windows[i].y, w, h)) {
                    cout << "Command " << command << ": RESIZE - window does not fit" << endl;
                    return;
                }
            }
            windows[i].w = w;
            windows[i].h = h;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Command " << command << ": RESIZE - no window at given position" << endl;
    }
}

void MOVE(int x, int y, int x2, int y2) {
    // make sure valid first (cursor is in a window)
    int windowIndex = -1;
    for (int i = 0; i < windows.size(); i++) {
        if (x >= windows[i].x && x < windows[i].x + windows[i].w && y >= windows[i].y &&
            y < windows[i].y + windows[i].h) {
            windowIndex = i;
            break;
        }
    }
    if (windowIndex == -1) {
        cout << "Command " << command << ": MOVE - no window at given position" << endl;
        return;
    }
    int originalY = windows[windowIndex].y;
    int originalX = windows[windowIndex].x;
    // inFormation are windows that are in the way of the window being moved so they get moved too
    int inFormation[1000] = {};
    inFormation[windowIndex] = 1;
    int distanceLeftX = abs(x2);
    int distanceLeftY = abs(y2);
    int minFreeSpace;
    int freeSpace[1000]; // to record how much space is left in each direction (boundary or another window)
    int next[1000]; // to note down the next window current window touched
    int end = 0;

    if (y2 < 0) { // move UP
        while (true) {
            // check if touch boundary
            end = 0;
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i] && windows[i].y == 0) {
                    end = 1;
                    break;
                }
            }
            if (end == 1) {
                break;
            }
            for (int i = 0; i < windows.size(); i++) {
                freeSpace[i] = 1000000000;
            }
            for (int i = 0; i < windows.size(); i++) {
                next[i] = -1;
            }
            // for each window in formation, check how much space is left to the left
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i]) {
                    for (int j = 0; j < windows.size(); j++) {
                        if (i != j && !inFormation[j] &&
                            overlap(windows[j].x, windows[j].y, windows[j].w, windows[j].h, windows[i].x,
                                    windows[i].y - 1100000000,
                                    windows[i].w, windows[i].h + 1100000000)) {
                            if (freeSpace[i] > windows[i].y - (windows[j].y + windows[j].h)) {
                                freeSpace[i] = windows[i].y - (windows[j].y + windows[j].h);
                                next[i] = j; // window i in formation will touch window j (not in formation)
                            }
                        }
                    }
                    freeSpace[i] = min(freeSpace[i], windows[i].y - 0);
                }
            }
            minFreeSpace = distanceLeftY;
            int windowToAddFormation = -1;
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i] && freeSpace[i] < minFreeSpace) {
                    minFreeSpace = freeSpace[i];
                    windowToAddFormation = next[i];
                }
            }
            // move all up by minFreeSpace
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i]) {
                    windows[i].y -= minFreeSpace;
                }
            }
            distanceLeftY -= minFreeSpace;
            if (distanceLeftY == 0) {
                break;
            }
            // add window to formation (if any)
            if (windowToAddFormation != -1) {
                inFormation[windowToAddFormation] = 1;
                continue; // if added window means touch window not boundary...
                // continue so can add more windows without moving. covers cases where
                // the window being added is already stuck onto another window
            }

        }
        if (end == 1 && (originalY - windows[windowIndex].y) != -y2) {
            cout << "Command " << command << ": MOVE - moved " << originalY - windows[windowIndex].y << " instead of "
                 << -y2
                 << endl;
        }
    }

    if (y2 > 0) { // move DOWN
        while (true) {
            // check if touch boundary
            end = 0;
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i] && windows[i].y + windows[i].h == yMax) {
                    end = 1;
                    break;
                }
            }
            if (end == 1) {
                break;
            }
            for (int i = 0; i < windows.size(); i++) {
                freeSpace[i] = 1000000000;
            }
            for (int i = 0; i < windows.size(); i++) {
                next[i] = -1;
            }
            // for each window in formation, check how much space is left below
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i]) {
                    for (int j = 0; j < windows.size(); j++) {
                        if (i != j && !inFormation[j] &&
                            overlap(windows[j].x, windows[j].y, windows[j].w, windows[j].h, windows[i].x,
                                    windows[i].y,
                                    windows[i].w, windows[i].h + 1100000000)) {
                            if (freeSpace[i] > windows[j].y - (windows[i].y + windows[i].h)) {
                                freeSpace[i] = windows[j].y - (windows[i].y + windows[i].h);
                                next[i] = j; // window i in formation will touch window j (not in formation)
                            }
                        }
                    }
                    freeSpace[i] = min(freeSpace[i], yMax - (windows[i].y + windows[i].h));
                }
            }
            minFreeSpace = distanceLeftY;
            int windowToAddFormation = -1;
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i] && freeSpace[i] < minFreeSpace) {
                    minFreeSpace = freeSpace[i];
                    windowToAddFormation = next[i];
                }
            }
            // move all down by minFreeSpace
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i]) {
                    windows[i].y += minFreeSpace;
                }
            }
            distanceLeftY -= minFreeSpace;
            if (distanceLeftY == 0) {
                break;
            }
            // add window to formation (if any)
            if (windowToAddFormation != -1) {
                inFormation[windowToAddFormation] = 1;
                continue; // if added window means touch window not boundary
            }

        }
        if (end == 1 && (windows[windowIndex].y - originalY) != y2) {
            cout << "Command " << command << ": MOVE - moved " << windows[windowIndex].y - originalY << " instead of "
                 << y2
                 << endl;
        }
    }

    if (x2 < 0) { // move LEFT
        while (true) {
            // check if touch boundary
            end = 0;
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i] && windows[i].x == 0) {
                    end = 1;
                    break;
                }
            }
            if (end == 1) {
                break;
            }
            for (int i = 0; i < windows.size(); i++) {
                freeSpace[i] = 1000000000;
            }
            for (int i = 0; i < windows.size(); i++) {
                next[i] = -1;
            }
            // for each window in formation, check how much space is left to the left
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i]) {
                    for (int j = 0; j < windows.size(); j++) {
                        if (i != j && !inFormation[j] &&
                            overlap(windows[j].x, windows[j].y, windows[j].w, windows[j].h, windows[i].x - 1100000000,
                                    windows[i].y,
                                    windows[i].w + 1100000000, windows[i].h)) {
                            if (freeSpace[i] > windows[i].x - (windows[j].x + windows[j].w)) {
                                freeSpace[i] = windows[i].x - (windows[j].x + windows[j].w);
                                next[i] = j; // window i in formation will touch window j (not in formation)
                            }
                        }
                    }
                    freeSpace[i] = min(freeSpace[i], windows[i].x - 0);
                }
            }
            minFreeSpace = distanceLeftX;
            int windowToAddFormation = -1;
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i] && freeSpace[i] < minFreeSpace) {
                    minFreeSpace = freeSpace[i];
                    windowToAddFormation = next[i];
                }
            }
            // move all left by minFreeSpace
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i]) {
                    windows[i].x -= minFreeSpace;
                }
            }
            distanceLeftX -= minFreeSpace;
            if (distanceLeftX == 0) {
                break;
            }

            // add window to formation (if any)
            if (windowToAddFormation != -1) {
                inFormation[windowToAddFormation] = 1;
                continue; // if added window means touch window not boundary
            }

        }
        if (end == 1 && (originalX - windows[windowIndex].x) != -x2) {
            cout << "Command " << command << ": MOVE - moved " << originalX - windows[windowIndex].x << " instead of "
                 << -x2
                 << endl;
        }
    }

    if (x2 > 0) { // move RIGHT
        while (true) {
            // check if touch boundary
            end = 0;
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i] && windows[i].x + windows[i].w == xMax) {
                    end = 1;
                    break;
                }
            }
            if (end == 1) {
                break;
            }
            for (int i = 0; i < windows.size(); i++) {
                freeSpace[i] = 1000000000;
            }
            for (int i = 0; i < windows.size(); i++) {
                next[i] = -1;
            }
            // for each window in formation, check how much space is left to the right
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i]) {
                    for (int j = 0; j < windows.size(); j++) {
                        if (i != j && !inFormation[j] &&
                            overlap(windows[j].x, windows[j].y, windows[j].w, windows[j].h, windows[i].x,
                                    windows[i].y,
                                    windows[i].w + 1100000000, windows[i].h)) {
                            if (freeSpace[i] > windows[j].x - (windows[i].x + windows[i].w)) {
                                freeSpace[i] = windows[j].x - (windows[i].x + windows[i].w);
                                next[i] = j; // window i in formation will touch window j (not in formation)
                            }
                        }
                    }
                    freeSpace[i] = min(freeSpace[i], xMax - (windows[i].x + windows[i].w));
                }
            }
            minFreeSpace = distanceLeftX;
            int windowToAddFormation = -1;
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i] && freeSpace[i] < minFreeSpace) {
                    minFreeSpace = freeSpace[i];
                    windowToAddFormation = next[i];
                }
            }
            // move all right by minFreeSpace
            for (int i = 0; i < windows.size(); i++) {
                if (inFormation[i]) {
                    windows[i].x += minFreeSpace;
                }
            }
            distanceLeftX -= minFreeSpace;
            if (distanceLeftX == 0) {
                break;
            }
            // add window to formation (if any)
            if (windowToAddFormation != -1) {
                inFormation[windowToAddFormation] = 1;
                continue; // if added window means touch window not boundary
            }

        }
        if (end == 1 && (windows[windowIndex].x - originalX) != x2) {
            cout << "Command " << command << ": MOVE - moved " << windows[windowIndex].x - originalX << " instead of "
                 << x2
                 << endl;
        }
    }


}

void printWindows() {
    cout << windows.size() << " window(s):" << endl;
    for (auto &window: windows) {
        cout << window.x << " " << window.y << " " << window.w << " " << window.h << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> xMax;
    while (cin >> yMax) {
        command = 1;
        windowOrder = 1;
        windows.clear();
        string cmd;
        while (cin >> cmd) {
            if (isdigit(cmd[0])) {
                xMax = stoi(cmd);
                break;
            }
            if (cmd == "OPEN") {
                int x, y, w, h;
                cin >> x >> y >> w >> h;
                OPEN(x, y, w, h);
            } else if (cmd == "CLOSE") {
                int x, y;
                cin >> x >> y;
                CLOSE(x, y);
            } else if (cmd == "RESIZE") {
                int x, y, w, h;
                cin >> x >> y >> w >> h;
                RESIZE(x, y, w, h);
            } else if (cmd == "MOVE") {
                int x, y, x2, y2;
                cin >> x >> y >> x2 >> y2;
                MOVE(x, y, x2, y2);
            }
            command++;
        }
        printWindows();
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}