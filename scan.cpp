#include <bits/stdc++.h>
using namespace std;

class SCAN {
    int head, total = 0, direction;

public:
    void run(vector<int> requests, int diskSize) {
        cin>>head>>direction;
        vector<int> left, right;
        for (int r : requests) {
            if (r < head) left.push_back(r);
            else right.push_back(r);
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        if (direction == 0) {
            for (int i = left.size() - 1; i >= 0; i--) {
                total += abs(head - left[i]);
                head = left[i];
            }
            total += head;
            head = 0;
            for (int r : right) {
                total += abs(head - r);
                head = r;
            }
        } else {
            for (int r : right) {
                total += abs(head - r);
                head = r;
            }
            total += abs(head - (diskSize - 1));
            head = diskSize - 1;
            for (int i = left.size() - 1; i >= 0; i--) {
                total += abs(head - left[i]);
                head = left[i];
            }
        }
        cout<<"Total Seek Time: "<<total<<"\n";
    }
};

int main() {
    SCAN s;
    s.run({82, 170, 43, 140, 24, 16, 190}, 200);
    return 0;
}
