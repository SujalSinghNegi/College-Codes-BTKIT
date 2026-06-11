#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    vector<int> req = {82, 170, 43, 140, 24, 16, 190};
    int head = 50;
    int disk_size = 200; 
    int total_seek = 0;
    
    vector<int> left, right;
    
    for (int r : req) {
        if (r < head) left.push_back(r);
        else right.push_back(r);
    }
    
    right.push_back(disk_size - 1);
    sort(right.begin(), right.end());
    sort(left.begin(), left.end(), greater<int>()); 
    cout << "SCAN Seek Sequence:\n" << head;
    for (int r : right) {
        total_seek += abs(r - head);
        head = r;
        cout << " -> " << head;
    }
    
    for (int r : left) {
        total_seek += abs(r - head);
        head = r;
        cout << " -> " << head;
    }
    
    cout << "\n\nTotal Seek Operations: " << total_seek << "\n";
    return 0;
}