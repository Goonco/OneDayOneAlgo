/*
    [BOJ2116_주사위_쌓기] - 23.01.22
    * 언급내용 없음. Bruteforcing.
*/

#include <iostream>
#include <vector>

using namespace std;

// A - F | B - D | C - E

int getMax(int n1, int n2) {
    int maxN = max(n1, n2);
    if (maxN != 6) return 6;

    int minN = min(n1, n2);
    if (minN != 5) return 5;

    return 4;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int DICE_NUM;
    cin >> DICE_NUM;
    vector<vector<int>> dices(DICE_NUM, vector<int>(7));

    int a, b, c, d, e, f;
    for (int i = 0; i < DICE_NUM; i++) {
        cin >> a >> b >> c >> d >> e >> f;

        dices[i][a] = f;
        dices[i][b] = d;
        dices[i][c] = e;
        dices[i][d] = b;
        dices[i][e] = c;
        dices[i][f] = a;
    }

    int count = 0;
    int MAXSUM = -1;
    for (int i = 1; i <= 6; i++) {
        int bot = i, top;
        int sum = 0;

        for (int j = 0; j < DICE_NUM; j++) {
            top = dices[j][bot];
            sum += getMax(bot, top);
            bot = top;
        }

        MAXSUM = max(MAXSUM, sum);
    }

    cout << MAXSUM;

    return 0;
}