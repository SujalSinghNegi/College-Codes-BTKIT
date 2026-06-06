#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> pages = {1, 3, 0, 3, 5, 6, 3};
    int f_cnt = 3, faults = 0, time = 0;
    vector<int> frames(f_cnt, -1), last_used(f_cnt, 0);

    for (int p : pages) {
        cout << "Req: " << p << " -> ";
        time++;
        auto it = find(frames.begin(), frames.end(), p);
        
        if (it == frames.end()) {
            faults++;
            int lru_idx = min_element(last_used.begin(), last_used.end()) - last_used.begin();
            frames[lru_idx] = p;
            last_used[lru_idx] = time;
            cout << "FAULT | ";
        } else {
            last_used[it - frames.begin()] = time;
            cout << "HIT   | ";
        }
        
        for (int f : frames) {
            if (f != -1) cout << "[" << f << "] ";
            else cout << "[ ] ";
        }
        cout << "\n";
    }
    cout << "\nTotal Page Faults: " << faults << "\n";
    return 0;
}