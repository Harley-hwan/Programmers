#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// 프로그래머스: 추석 트래픽

// hour, minute, second를 ms로 바꿔 리턴.
int ToGetTime(string str) {
    istringstream ss(str);
    string stringBuffer;
    vector<string> v;
    v.clear();
    while (getline(ss, stringBuffer, ':')) {
        v.push_back(stringBuffer);
    }

    v[2].erase(v[2].begin() + 2, v[2].begin() + 3); // 소수점(.) 제거
    int h = stoi(v[0]) * 60 * 60 * 1000;
    int m = stoi(v[1]) * 60 * 1000;
    int s = stoi(v[2]);

    return h + m + s;
}

// 소수점 제거, ms 로 리턴    
int processingTime(string str) {
    string subStr = str.substr(0, str.length()-1);
    int answer = (int)(stod(subStr) * 1000);
    return answer;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> endTime, processTime;   
    for (int i = 0; i < lines.size(); i++) {
        istringstream ss(lines[i]);
        string stringBuffer;
        vector<string> v;
        v.clear();
        while (getline(ss, stringBuffer, ' ')) {
            v.push_back(stringBuffer);
        }
        endTime.push_back(ToGetTime(v[1]));
        processTime.push_back(processingTime(v[2]));
    }
    int end_time, count, nextTime;

    for (int i = 0; i < lines.size(); i++) {
        end_time = endTime[i] + 1000; // 각각의 끝 지점을 기준으로 1초 구간
        count = 1;  // 시작점 항상 포함 -> 1부터 시작

        for (int j = i + 1; j < lines.size(); j++) {
            nextTime = endTime[j] - processTime[j] + 1;
            if (nextTime < end_time) count++;   // 시작시간이 1초 구간안에 속하면 ++;
        }

        if (answer < count)  answer = count;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<string> lines = {
        "2016-09-15 20:59:57.421 0.351s",
        "2016-09-15 20:59:58.233 1.181s",
        "2016-09-15 20:59:58.299 0.8s",
        "2016-09-15 20:59:58.688 1.041s",
        "2016-09-15 20:59:59.591 1.412s",
        "2016-09-15 21:00:00.464 1.466s",
        "2016-09-15 21:00:00.741 1.581s",
        "2016-09-15 21:00:00.748 2.31s",
        "2016-09-15 21:00:00.966 0.381s",
        "2016-09-15 21:00:02.066 2.62s"
    };

    cout << solution(lines) << "\n";

    return 0;
}


//     istringstream ss(str);
//     string stringBuffer;
//     vector<string> v;
//     v.clear();
//     while (getline(ss, stringBuffer, ' ')) {
//         v.push_back(stringBuffer);
//     }
//     string tmp = v[2];
//     tmp.erase(tmp.find('s'));
//     //double tmpForFloat = (int)(stod(tmp) * 1000);
//     answer = (int)(stod(tmp) * 1000);
//     return answer;
// }

// string RemoveSpace(string str) {
//     string answer;
//     istringstream ss(str);
//     string stringBuffer;
//     vector<string> v;
//     v.clear();
//     while (getline(ss, stringBuffer, ' ')) {
//         v.push_back(stringBuffer);
//     }
//     answer = v[1];
//     return answer;
// }

// string RemoveColon(string str) {
//     string answer;
//     string str_ = RemoveSpace(str);
//     istringstream ss(str_);
//     string stringBuffer;
//     while (getline(ss, stringBuffer, ':')) {
//         answer += stringBuffer;
//     }
//     return answer;
// }

// string RemoveDot(string str) {
//     string answer;
//     string str_ = RemoveColon(str);
//     istringstream ss(str_);
//     string stringBuffer;
//     while (getline(ss, stringBuffer, '.')) {
//         answer += stringBuffer;
//     }
//     return answer;
// }

// int StringToInt(string str) {
//     int answer = stoi(RemoveDot(str));
//     return answer;
// }