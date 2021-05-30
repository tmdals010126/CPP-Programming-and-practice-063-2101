
#include <iostream>
#include <string>
#include <vector>
#include <clocale>  // wstring,wcin,wcout 사용
#include <ctime>
#include <random>

using namespace std;

//**********************************************************************************
//원래 코드에선 구조체로 되어있지만 채점을 위해 분리하다보니 나누어 적게 되었습니다.
//**********************************************************************************
vector< vector<wstring>>text; // 2차원 백터를 선언하지만 한글은 string 으로 할시 오류가 발생해서 wstring 으로 선언
void Shuffle_Word()
{
    wstring temp1;              // 단어  임시 저장공간
    wstring temp2;              // 단어의 뜻 임시 저장공간
    minstd_rand rand_shuffle(time(nullptr));
    int n;
    for (int i = static_cast<int>(text.size()) - 1; i >= 0; i--)
    {
        n = rand_shuffle() % text.size();
        temp1 = text[i][0];
        text[i][0] = text[n][0];
        text[n][0] = temp1;
        temp2 = text[i][1];
        text[i][1] = text[n][1];
        text[n][1] = temp2;
    }
}
    void Shuffle_vector(vector< vector<wstring>>&v) //다른배열도 셔플할수있도록 함수 추가
    {
        wstring temp1;              // 단어  임시 저장공간
        wstring temp2;              // 단어의 뜻 임시 저장공간
        minstd_rand rand_shuffle(time(nullptr));
        int n;
        for (int i = static_cast<int>(v.size()) - 1; i >= 0; i--)
        {
            n = rand_shuffle() % text.size();
            temp1 = v[i][0];
            v[i][0] = v[n][0];
            v[n][0] = temp1;
            temp2 = v[i][1];
            v[i][1] = v[n][1];
            v[n][1] = temp2;
        }
    }

