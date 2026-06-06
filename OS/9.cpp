#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    vector<int> req = {82, 170, 43, 140, 24, 16, 190};
    int head = 50, total_seek = 0, n = req.size();
    vector<bool> vis(n, false);

    cout << "SSTF Seek Sequence:\n" << head;

    for (int i = 0; i < n; i++) {
        int min_dist = 9999, idx = -1;
        
        for (int j = 0; j < n; j++) {
            if (!vis[j] && abs(req[j] - head) < min_dist) {
                min_dist = abs(req[j] - head);
                idx = j;
            }
        }
        
        vis[idx] = true;
        total_seek += min_dist;
        head = req[idx];
        cout << " -> " << head;
    }

    cout << "\n\nTotal Seek Operations: " << total_seek << "\n";
    return 0;
}