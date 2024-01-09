/*
    [BOJ22233_가희와_키워드] - 23.01.09
    * unordered_set 사용법 및 split 함수 구현하는 방법 두 가지
*/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<string> split(string str, string delim) {
    vector<string> saver;

    int findFrom = 0, check;
    while(true){
        check = str.find(delim, findFrom);
        saver.push_back(str.substr(findFrom, check - findFrom));
        
        if (check == string::npos) break;
        findFrom = check + 1;
    }

    return saver;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int KEYWORD_NUM, POST_NUM;
    cin >> KEYWORD_NUM >> POST_NUM;

    unordered_set<string> mySet;

    string keyword;
    for (int i = 0; i < KEYWORD_NUM; i++) {
        cin >> keyword;
        mySet.insert(keyword);
    }

    string rl;
    for (int i = 0; i < POST_NUM; i++) {
        cin >> rl;
        vector<string> splited = split(rl, ",");

        int count = 0;
        for (string str : splited) {
            if (mySet.find(str) != mySet.end()) mySet.erase(str);
        }

        cout << mySet.size() << "\n";
    }

    return 0;
}
