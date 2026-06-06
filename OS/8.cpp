#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> req = {82, 170, 43, 140, 24, 16, 190};
    int head = 50, total_seek = 0;

    cout << "FCFS Seek Sequence:\n" << head;

    for (int r : req) {
        total_seek += abs(r - head);
        head = r;
        cout << " -> " << head;
    }

    cout << "\n\nTotal Seek Operations: " << total_seek << "\n";
    return 0;
}