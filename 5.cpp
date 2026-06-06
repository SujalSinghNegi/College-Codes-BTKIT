#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> pages = {1, 3, 0, 3, 5, 6, 3};
    int f_cnt = 3, faults = 0, idx = 0;
    vector<int> frames(f_cnt, -1);

    for (int p : pages) {
        cout << "Req: " << p << " -> ";
        
        if (find(frames.begin(), frames.end(), p) == frames.end()) {
            frames[idx] = p;
            idx = (idx + 1) % f_cnt;
            faults++;
            cout << "FAULT | ";
        } else {
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