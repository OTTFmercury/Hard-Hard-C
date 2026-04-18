

#include <iostream>

using namespace std;

int n;
int m;
int x;
int y;
long long dp[22][33];
int xc[9] = {1, 2, 2, 1, -1, -2, -2, -1, 0};
int yc[9] = {-2, -1, 1, 2, 2, 1, -1, -2, 0};

bool judge (int i, int j) {
    for (int k = 0; k < 9; k++) {
        if (i == x + xc[k] && j == y + yc[k]) {
            return false;
        }
    }
    return true;
}

int main () {
    
    cin >> n >> m >> x >> y;

    n++;
    m++;
    x++;
    y++;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (judge (i, j)) {
                if (i == 1 && j == 1) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}