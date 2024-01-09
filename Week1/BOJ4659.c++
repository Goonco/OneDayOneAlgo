/*
    [BOJ4659_비밀번호 발음하기] - 23.01.04
    * 따로 언급할 내용은 없어보인다.
    * 단, 이번에도 변수 초기화 문제로 최초에 실패했었는데, 적어도 PS 할 때 만큼은 초기화 효율성을 고려하지 않는 것이 좋을까..?
*/

#include <iostream>
#include <string.h>

using namespace std;

bool isMo(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    while (true) {
        cin >> s;
        if(!s.compare("end")) break;

        int moCount = 0, jaCount = 0;
        bool flag = true, hasMo = false;
        for (int i = 0; i < s.size(); i++) {
            if (isMo(s[i])) {
                hasMo = true;
                moCount++;
                jaCount = 0;
            }
            else {
                jaCount++;
                moCount = 0;
            }

            if (moCount == 3 || jaCount == 3) {
                flag = false;
                break;
            }

            if(!i) continue;
            if(s[i] == s[i-1] && (s[i] != 'e' && s[i] != 'o')){
                flag = false;
                break;
            }
        }

        flag = flag && hasMo;
        if (flag) cout << "<" + s + "> is acceptable.\n" ;
        else cout << "<" + s + "> is not acceptable.\n";
    }

    return 0;
}
