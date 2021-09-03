#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


// 프로그래머스 > 코딩테스트 연습 > 2019 KAKAO BLIND RECRUITMENT > 매칭 점수

// 기본점수: html로 페이지가 넘어가면서 각 페이지에서 등장하는 검색어 수를 카운팅.
// += 기본점수 / 외부 링크 


struct Page {
    int index;  //각 페이지의 인덱스
    int basic, link;    //기본 점수, 링크 수
    double score;
};

bool comp(Page& a, Page& b) {
    if (a.score == b.score)
        return a.index < b.index; // score가 같으면 index가 작은 게 먼저
    return a.score > b.score;     // score가 큰게 먼저.
}

int solution(string word, vector<string> pages) {
    int w_size = word.size();   // word 사이즈
    map<string, int> p_hash;    // 페이지 해시
    vector<Page> p_list;        // 페이지 리스트
    
    // 소문자로 변환
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    for (int i = 0; i < pages.size(); i++) {
        string& s = pages[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        int mid = 0, left = 0, right;
        while (mid <= left) {   // meta tag 안에 있는거.
            left = s.find("<meta", left + 1);
            right = s.find(">", left);          // 내가 원하는 url
            mid = s.rfind("https://", right);
        }

        right = s.find("\"", mid);   // mid 부터 시작해서 처음 큰 따옴표 나오면 끝
        string url = s.substr(mid, right - mid);

        left = s.find("<body>", right);
        int basic = 0;
        for (int start = left; ;) {
            start = s.find(word, start + 1);    // for문이 돌면서 앞으로 진행 (start + 1)
            if (start == string::npos)  break;
            if (!isalpha(s[start-1]) && !isalpha(s[start + w_size])) { // 검색어 바로 다음 문자 - 이것이 알파벳이 아니어야함.
                basic++;
                start += w_size;
            }
        }

        int link = 0;   // 외부 링크 수
        for (int start = left; ;) {                 // 바디의 시작 위치부터
            start = s.find("<a href", start + 1);   // 하이퍼링크를 찾아.
            if (start == string::npos)  break;      // return 값이 있으면 찾은거고 없으면 break
            link++;                                 // 그리고 찾았으니 link를 한개 증가
        }

        p_hash[url] = i;    // key: url(string), i(index: int)
        p_list.push_back({i, basic, link, (double)basic});
    }

    for (int i = 0; i < pages.size(); i++) {
        string& s = pages[i];
        for (int left = 0, right = 0; ;) {
            left = s.find("<a href", right);
            if (left == string::npos) break;

            left = s.find("https://", left);    // url 시작위치 left로 잡힘.
            right = s.find("\"", left);
            string URL = s.substr(left, right - left);

            // pair로 되있으니까, first: key, second: value로 불러냄.
            map<string, int>::iterator it = p_hash.find(URL); 

            if (it != p_hash.end()) {
                p_list[it->second].score += (double)p_list[i].basic / p_list[i].link;  // 페이지에 링크 정보를 올려야하니까. value : index
            }
        }
    }
    // 여기까지 모든 리스트를 다 뽑아봤다.
    // 그러면 이제 최소를 뽑아야하니까 정렬해야한다.

    sort(p_list.begin(), p_list.end(), comp);
    
    return p_list.begin()->index;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // string word = "Muzi"; 
    // vector<string> pages = {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"};


    string word = "blind";
    vector<string> pages = {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"};
    
    cout << solution(word, pages) << "\n";

    return 0;
}
