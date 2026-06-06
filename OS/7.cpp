#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> pages = {1, 3, 0, 3, 5, 6, 3};
    int f_cnt = 3, faults = 0, n = pages.size();
    vector<int> frames;

    for (int i = 0; i < n; i++) {
        int p = pages[i];
        cout << "Req: " << p << " -> ";
        
        if (find(frames.begin(), frames.end(), p) == frames.end()) {
            faults++;
            cout << "FAULT | ";
            if (frames.size() < f_cnt) {
                frames.push_back(p);
            } else {
                int farthest = i, replace_idx = -1;
                for (int j = 0; j < frames.size(); j++) {
                    int next_use = n;
                    for (int k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            next_use = k;
                            break;
                        }
                    }
                    if (next_use > farthest) {
                        farthest = next_use;
                        replace_idx = j;
                    }
                }
                frames[replace_idx] = p;
            }
        } else {
            cout << "HIT   | ";
        }
        
        for (int j = 0; j < f_cnt; j++) {
            if (j < frames.size()) cout << "[" << frames[j] << "] ";
            else cout << "[ ] ";
        }
        cout << "\n";
    }
    cout << "\nTotal Page Faults: " << faults << "\n";
    return 0;
}