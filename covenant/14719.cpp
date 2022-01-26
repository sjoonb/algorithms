#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h, w;
vector<int> board(500);

// using complement set

int solve() {
    int sum=0;
    for(int i=1; i<w-1; ++i) {
        int height = board[i];
        int l = i-1;
        int lMaxV = board[l];
        while(l-- >= 0) {
            if(board[l] > lMaxV)
                lMaxV = board[l];
        }
        int r = i+1;
        int rMaxV = board[r];
        while(r++ <= w-1) {
            if(board[r] > rMaxV)
                rMaxV = board[r];
        }
        int temp = max(min(lMaxV, rMaxV) - height, 0);
        sum += temp;
    }
    return sum;
}

int main() {
    cin >> h >> w;
    for(int i=0; i<w; ++i)
        cin >> board[i];
    cout << solve();
}

