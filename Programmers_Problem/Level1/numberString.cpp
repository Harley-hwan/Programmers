#include <iostream>
#include <string>
#include <map>

using namespace std;

map <string, string> words= { {"zero", "0"},
                            {"one", "1"},
                            {"two", "2"},
                            {"three", "3"},
                            {"four", "4"},
                            {"five", "5"},
                            {"six", "6"},
                            {"seven", "7"},
                            {"eight", "8"},
                            {"nine", "9"} };

int solution(string s) {
    string answer = "";
    string temp = "";

    for (int i = 0; i < s.size(); i++) {
       if (!isdigit(s[i])) {
           temp += s[i];
           if (words[temp] != "") {
               answer += words[temp];
               temp = "";
           }
       }
       else answer += s[i];
    }
    return stoi(answer);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s = "one4seveneight";
    cout << solution(s);

    return 0;
}