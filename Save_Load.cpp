#include <iostream>
#include <string>
#include <vector>
#include <clocale>  // wstring,wcin,wcout 사용
#include <ctime>
#include <random>
#include <iomanip> //출력포멧팅을 위한 헤더 print_Word함수에서 사용
#include<windows.h>//gotoxy함수를 사용하기위해 사용
#include<conio.h>//_getch()를 사용하기위해 사용 - 방향키를 사용하기위함
#include<fstream>//파일입출력을 위해 사용


using namespace std;
//**********************************************************************************
//원래 코드에선 구조체로 되어있지만 채점을 위해 분리하다보니 나누어 적게 되었습니다.
//**********************************************************************************

vector<wstring> load_data;    // 텍스트파일에 저장된 스트링 저장
vector< vector<wstring>>text; // 2차원 백터를 선언하지만 한글은 string 으로 할시 오류가 발생해서 wstring 으로 선언
vector< vector<wstring>>review_korean_quiz; // 오답내용 저장
vector< vector<wstring>>review_english_quiz; // 오답내용 저장
vector<wstring> temp;         // Eng_Word,Kor_Word 저장, 여러가지단어를 잠시 저장하여 2차원 벡터 배열로 입력할때 사용

void fileRead(wifstream& fin, vector<wstring>& v)
{
    wstring line;

    while (getline(fin, line))
        v.push_back(line);
}
void Load_Word() { //오답노트도 읽어오도록 변경
    wstring Load_Kor, Load_Eng;
    Load_Kor = L"";
    Load_Eng = L"";
    wifstream fin("Word.txt");
    fin.imbue(std::locale("kor"));//한굴인코딩관련해서 적지않으면 한글이 안적힘
    int if_find = 0;
    if (fin.fail()) {
        cout << "저장된 단어장이 없습니다." << endl;
        system("pause");
        return;
    }
    else {
        fileRead(fin, load_data);
        fin.close();
        for (int i = 0; i < load_data.size(); i++) {
            for (int j = 0; j < load_data[i].size(); j++) {
                if (load_data[i][j] == '|') {
                    if_find = 1;
                    continue;
                }
                else {
                    if (if_find == 0) {
                        Load_Eng = Load_Eng + load_data[i][j];
                    }
                    if (if_find == 1) {
                        Load_Kor = Load_Kor + load_data[i][j];
                    }
                }

            }
            if_find = 0;
            temp.push_back(Load_Eng);
            temp.push_back(Load_Kor);
            text.push_back(temp);
            temp.pop_back();
            temp.pop_back(); //text 벡터 뒤에 이어 덧붙임
            Load_Kor = L"";
            Load_Eng = L""; //초기화
        }
    }
    int num = load_data.size();
    for (int i = 0; i < num; i++) {
        load_data.pop_back();//load_data 초기화
    }
    wifstream kfin("review_korean_quiz.txt");
    kfin.imbue(std::locale("kor"));//한굴인코딩관련해서 적지않으면 한글이 안적힘
    if_find = 0;
    if (kfin.fail()) {
        cout << "저장된 단어장이 없습니다." << endl;
        system("pause");
        return;
    }
    else {
        fileRead(kfin, load_data);
        kfin.close();
        for (int i = 0; i < load_data.size(); i++) {
            for (int j = 0; j < load_data[i].size(); j++) {
                if (load_data[i][j] == '|') {
                    if_find = 1;
                    continue;
                }
                else {
                    if (if_find == 0) {
                        Load_Eng = Load_Eng + load_data[i][j];
                    }
                    if (if_find == 1) {
                        Load_Kor = Load_Kor + load_data[i][j];
                    }
                }

            }
            if_find = 0;
            temp.push_back(Load_Eng);
            temp.push_back(Load_Kor);
            review_korean_quiz.push_back(temp);
            temp.pop_back();
            temp.pop_back(); //text 벡터 뒤에 이어 덧붙임
            Load_Kor = L"";
            Load_Eng = L""; //초기화
        }
    }
    num = load_data.size();
    for (int i = 0; i < num; i++) {
        load_data.pop_back();//load_data 초기화
    }
    wifstream efin("review_english_quiz.txt");
    efin.imbue(std::locale("kor"));//한굴인코딩관련해서 적지않으면 한글이 안적힘
    if_find = 0;
    if (efin.fail()) {
        cout << "저장된 단어장이 없습니다." << endl;
        system("pause");
        return;
    }
    else {
        fileRead(efin, load_data);
        efin.close();
        for (int i = 0; i < load_data.size(); i++) {
            for (int j = 0; j < load_data[i].size(); j++) {
                if (load_data[i][j] == '|') {
                    if_find = 1;
                    continue;
                }
                else {
                    if (if_find == 0) {
                        Load_Eng = Load_Eng + load_data[i][j];
                    }
                    if (if_find == 1) {
                        Load_Kor = Load_Kor + load_data[i][j];
                    }
                }

            }
            if_find = 0;
            temp.push_back(Load_Eng);
            temp.push_back(Load_Kor);
            review_english_quiz.push_back(temp);
            temp.pop_back();
            temp.pop_back(); //text 벡터 뒤에 이어 덧붙임
            Load_Kor = L"";
            Load_Eng = L""; //초기화
        }
        wcout << L"성공적으로 불러왔습니다." << endl;
        system("pause");
        return;
    }

}

void Save_Word() { //오답노트도 백업하도록 변경
    wstring Save_data;

    wofstream fout("Word.txt", wios::out);
    fout.imbue(std::locale("kor")); //한굴인코딩관련해서 이 코드를 적지않으면 한글이 안적힘
    for (int i = 0; i < text.size(); i++) {
        Save_data = text[i][0] + L"|" + text[i][1];
        fout << Save_data << endl;
    }
    fout.close();
    wofstream kfout("review_korean_quiz.txt", wios::out);
    kfout.imbue(std::locale("kor")); //한굴인코딩관련해서 이 코드를 적지않으면 한글이 안적힘
    for (int i = 0; i < review_korean_quiz.size(); i++) {
        Save_data = review_korean_quiz[i][0] + L"|" + review_korean_quiz[i][1];
        kfout << Save_data << endl;
    }
    kfout.close();
    wofstream efout("review_english_quiz.txt", wios::out);
    efout.imbue(std::locale("kor")); //한굴인코딩관련해서 이 코드를 적지않으면 한글이 안적힘
    for (int i = 0; i < review_english_quiz.size(); i++) {
        Save_data = review_english_quiz[i][0] + L"|" + review_english_quiz[i][1];
        efout << Save_data << endl;
    }
    efout.close();
    wcout << L"성공적으로 저장했습니다." << endl;
    system("pause");
    return;
}
