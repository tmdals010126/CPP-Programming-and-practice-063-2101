
#include <iostream>
#include <string>
#include <vector>
#include <clocale>  // wstring,wcin,wcout 사용

using namespace std;

//**********************************************************************************
//원래 코드에선 구조체로 되어있지만 채점을 위해 분리하다보니 나누어 적게 되었습니다.
//**********************************************************************************

vector< vector<wstring>>text; // 2차원 백터를 선언하지만 한글은 string 으로 할시 오류가 발생해서 wstring 으로 선언
vector<wstring> temp;         // Eng_Word,Kor_Word 저장, 여러가지단어를 잠시 저장하여 2차원 벡터 배열로 입력할때 사용

bool IsEnglish(wchar_t ch) // 영어 구분
    {
        if ((0x61 <= ch && ch <= 0x7A) || (0x41 <= ch && ch <= 0x5A))
            return true;
        else
            return false;
    }

    bool IsKorean(wchar_t ch) // 한글 구분
    {
        //( 한글자 || 자음 , 모음 )
        if ((0xAC00 <= ch && ch <= 0xD7A3) || (0x3131 <= ch && ch <= 0x318E))
            return true;
        else
            return false;
    }

    void Input_Word()
    {
        wstring Eng_Word;
        wstring Kor_Word;
        int if_diff_lang = 0; //허용되지 않은 단어가 들어왔는지 확인하는 변수
        while (true)
        {
            cout << "<<<<<<< 저장할 단어를 입력해주세요 (입력을 그만하고 싶으면 q를 입력해주세요.) >>>>>>>" << endl;
            getline(wcin, Eng_Word); // 스페이스바도 입력을 받기위해 wcin 대신 사용
            cout << "\n";

            if (Eng_Word == L"q") {
                break;
            }

            for (int i = 0; i < Eng_Word.size(); i++) {
                if (!IsEnglish(Eng_Word.c_str()[i])) {
                    cout << "영어를 입력해주시기 바랍니다." << endl;
                    if_diff_lang = 1;
                    break;
                }
            }
            if (if_diff_lang == 1) {
                if_diff_lang = 0;
                continue;
            }
            cout << "<<<<<<< 단어의 뜻을 입력해주세요 >>>>>>>" << endl;
            getline(wcin, Kor_Word);// 스페이스바도 입력을 받기위해 wcin 대신 사용
            cout << "\n";
            if (Eng_Word == L"q" || Kor_Word == L"q") {
                break;
            }
            for (int i = 0; i < Kor_Word.size(); i++) {
                if (!IsKorean(Kor_Word.c_str()[i])) {
                    if (Kor_Word.c_str()[i]==0x20){ //스페이스바 처리
                        continue;
                    }
                    cout << "한글을 입력해주시기 바랍니다." << endl;
                    if_diff_lang = 1;
                    break;
                }
            }
            if (if_diff_lang == 1) {
                if_diff_lang = 0;
                continue;
            }
            temp.push_back(Eng_Word);
            temp.push_back(Kor_Word);
            text.push_back(temp);
            temp.pop_back();
            temp.pop_back();
        }
    }