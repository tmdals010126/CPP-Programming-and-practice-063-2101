#include <iostream>
#include <string>
#include <vector>
#include <clocale>  // wstring,wcin,wcout 사용
#include <iomanip> //출력포멧팅을 위한 헤더 print_Word함수에서 사용

using namespace std;

//**********************************************************************************
//원래 코드에선 구조체로 되어있지만 채점을 위해 분리하다보니 나누어 적게 되었습니다.
//**********************************************************************************

vector< vector<wstring>>text; // 2차원 백터를 선언하지만 한글은 string 으로 할시 오류가 발생해서 wstring 으로 선언

bool IsKorean(wchar_t ch) //한글 구분
{
    //( 한글자 || 자음 , 모음 )
    if ((0xAC00 <= ch && ch <= 0xD7A3) || (0x3131 <= ch && ch <= 0x318E))
        return true;
    else
        return false;
}

void Print_Word()
{
    int Kornum;
    cout << " ------- ---------------------------------------- ---------------------------- " << endl;
    cout << "|       |                                        |                            |" << endl;
    cout << "|  번호 |                   영어뜻               |             한글뜻         |" << endl;
    cout << "|       |                                        |                            |" << endl;
    cout << " ------- ---------------------------------------- ---------------------------- " << endl;
    for (int i = 0; i < static_cast<int>(text.size()); i++)
    {
        cout << " ------- ---------------------------------------- ---------------------------- " << endl;
        wcout << "|" << setw(6) << i + 1 << " |" << setw(39) << text[i][0] << " |";
        Kornum = text[i][1].size();
        for (int j = 0; j < text[i][1].size(); j++) { //스페이스바가 섞이게 된다면 스페이스바는 1byte 한글은 2byte라 스페이스바개수를 분류
            if (IsKorean(text[i][1].c_str()[j])) {
                Kornum++;
            }
        }
        for (int j = 0; j < 27 - Kornum; j++) { //한글은 2byte문자라서 setw함수를 사용하면 출력이 밀리기때문에 한글은 따로 처리
            cout << " ";
        }
        wcout << text[i][1] << " |" << endl;
        cout << " ------- ---------------------------------------- ---------------------------- " << endl;
        if ((i + 1) % 10 == 0) {
            system("pause"); //10개 이상의 단어가 출력되면 보이지않는 단어가 생기므로 10개씩 출력하고 입력을 기다림
        }
    }
    cout << "\n";
    system("pause");
}