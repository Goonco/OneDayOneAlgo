/*
    [BOJ10844_쉬운_계단_수] - 23.01.19
    * Modular Add
    * (A + B) % C = (A % C + B % C) % C
*/

#include <iostream>
#include <vector>

typedef long long ll;
ll MOD = 1000000000;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<ll>> dp(N+1, vector<ll>(10,0));

    dp[0] = { 0,0,0,0,0,0,0,0,0,0 };
    dp[1] = { 0,1,1,1,1,1,1,1,1,1 };

    for (int i = 2; i <= N; i++) {
        
        for (int j = 0; j <= 9; j++) {
            if (j - 1 >= 0)
                dp[i][j - 1] = ((dp[i][j - 1] % MOD) + (dp[i - 1][j] % MOD)) % MOD;
            if (j + 1 <= 9)
                dp[i][j + 1] = ((dp[i][j + 1] % MOD) + (dp[i - 1][j] % MOD)) % MOD;
        }
     
    }

    ll sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum = (sum % MOD + dp[N][i] % MOD) % MOD;
    }

    cout << sum;

    return 0;
}
