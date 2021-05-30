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
//벡터배열에서 오답노트에서 문제풀시에 풀이한 문제는 삭제되는 기능에서 오류를 일으키는걸 수정했습니다.
//기타 여러 가지 문제를 수정했습니다.



vector< vector<wstring>>text; // 2차원 백터를 선언하지만 한글은 string 으로 할시 오류가 발생해서 wstring 으로 선언
vector< vector<wstring>>review_korean_quiz; // 오답내용 저장
vector< vector<wstring>>review_english_quiz; // 오답내용 저장
vector<wstring> temp;         // Eng_Word,Kor_Word 저장
vector<wstring> review_temp;  // 틀린 Eng_Word,Kor_Word 저장
vector<wstring> load_data;    // 텍스트파일에 저장된 스트링 저장

void Shuffle_vector(vector< vector<wstring>>& v) //다른배열도 셔플할수있도록 함수 추가
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

void Korean_Word_Quiz()
{
    if (text.size() < 3)
    {
        cout << "문제를 만들 만큼 단어를 저장하지 않았습니다." << endl;
        return;
    }
    int Input_Number;
    cout << "풀고자 하는 문제 갯수를 입력해 주시오. ( 1 ~ " << text.size() << " )" << endl;
    cin >> Input_Number;

    for (int i = 0; i < Input_Number; i++)
    {
        int Input_Answer; //사용자 입력 정답
        int Correct_Answer;    // 정답 보기
        int Example_Index = 123; //3이상은 될수없기에 임시로 123으로 초기화 

        minstd_rand rand_kor(time(NULL));

        wcout << L"문제" << i + 1 << L": " << text[i][0] << endl; //영어단어 출력

        Correct_Answer = rand_kor() % 3 + 1;  // 랜덤 보기 번호 매기기
        for (int j = 1; j < 4; j++)
        {

            if (j == Correct_Answer)                              // 정답 보기 생성
            {
                wcout << j << L": " << text[i][1] << endl; //옳은 한글 뜻 가져옴
            }
            else                                           // 오답 보기 생성
            {
                int Kor;
                do {
                    Kor = rand_kor();
                } while (Kor % text.size() == i || Kor % text.size() == Example_Index);                     // 정답이 보기에 2개 있는 것을 방지
                Example_Index = Kor % text.size();

                wcout << j << L": " << text[Example_Index][1] << endl;

            }


        }
        cin >> Input_Answer;
        if (Input_Answer == 'q') // 함수밖으로 나가기위해 수정
        {
            break;
        }
        if (Input_Answer == Correct_Answer)
        {
            cout << "정답 !" << endl;
            for (int j = 0; j < static_cast<int>(review_korean_quiz.size()); j++)
            {
                if (text[i][0] == review_korean_quiz[j][0]) review_korean_quiz.erase(review_korean_quiz.begin() + j);  //맞추면 오답노트에서 제거
            }
        }
        else
        {
            wcout << L"오답 " << "\n" << L"정답은 " << text[i][1] << endl;

            if (review_korean_quiz.size() < 1)
            {
                review_temp.push_back(text[i][0]);
                review_temp.push_back(text[i][1]);
                review_korean_quiz.push_back(review_temp);
                review_temp.pop_back();
                review_temp.pop_back();
            }
            else
            {
                int count = 0;                        // 중복 check count
                for (int j = 0; j < static_cast<int>(review_korean_quiz.size()); j++)
                {
                    if (text[i][0] != review_korean_quiz[j][0]) count++;
                }
                if (count == review_korean_quiz.size())
                {
                    review_temp.push_back(text[i][0]);
                    review_temp.push_back(text[i][1]);
                    review_korean_quiz.push_back(review_temp);
                    review_temp.pop_back();
                    review_temp.pop_back();
                }
            }
        }
    }
    system("pause");
}

void Review_Eng_Quiz()
{
    wstring answer;
    int i = 0;
    while (true) {
        if (review_english_quiz.size() == 0)
        {
            cout << "틀린 문제가 없습니다." << endl;
            system("pause");
            return;
        }
        wcout << L"문제" << i + 1 << ": " << review_english_quiz[i][1] << endl; //한글 단어 출력
        getline(wcin, answer); // 스페이스바도 입력을 받기위해 wcin 대신 사용
        if (answer == L"q")
        {
            break;
        }
        if (answer == review_english_quiz[i][0])
        {
            cout << "Correct ! " << endl;
            review_english_quiz[i][0] = L"";//맞추면 오답노트에서 제거를 하기위해 erase 함수를 사용하면 에러가 나기 때문에 공백으로 바꿈
            review_english_quiz[i][1] = L"";
        }
        else
        {
            cout << "Wrong !" << endl;
            wcout << L"Answer is: " << review_english_quiz[i][0] << endl;
        }
        Shuffle_vector(review_english_quiz);
        for (int j = 0; j < review_english_quiz.size(); j++) {//공백은 제외하기위해 처리
            i++;
            if (i > review_english_quiz.size()) {
                i = 0;
            }
            if (review_english_quiz[j][0] != L"") {
                i = j;
                break;
            }
        }
        int num = 0;
        for (int j = 0; j < review_english_quiz.size(); j++) {//공백의 수를 셈
            if (review_english_quiz[j][0] == L"") {
                num++;
            }
        }
        if (num == review_english_quiz.size()) {//공백의 수가 size와 같으면 삭제하고 나감
            for (int j = 0; j < num; j++) {//벡터배열의 초기화 및 공백 삭제
                review_english_quiz.pop_back();
            }
            break;
        }
    }
    system("pause");
}


void Review_Kor_Quiz()
{
    int i = 0;

    while (true) {
        if (review_korean_quiz.size() == 0)
        {
            cout << "틀린 문제가 없습니다." << endl;
            system("pause");
            return;
        }
        int Input_Answer; //사용자 입력 정답
        int Correct_Answer;    // 정답 보기
        int Review_Example_Index = 123;//2초과일수없기에 임시로 123적음

        minstd_rand rand_kor(time(NULL));

        wcout << L"문제" << i + 1 << L": " << review_korean_quiz[i][0] << endl; //영어단어 출력

        Correct_Answer = rand_kor() % 3 + 1;  // 랜덤 보기 번호 매기기
        for (int j = 1; j < 4; j++)
        {

            if (j == Correct_Answer)                              // 정답 보기 생성
            {
                wcout << j << L": " << review_korean_quiz[i][1] << endl; //옳은 한글 뜻 가져옴
            }
            else                                           // 오답 보기 생성
            {
                int Kor;
                do {
                    Kor = rand_kor();
                } while (text[Kor % text.size()][1] == review_korean_quiz[i][1] || Kor % text.size() == Review_Example_Index); // 정답 2개,복수 보기제거
                Review_Example_Index = Kor % text.size();

                wcout << j << L": " << text[Review_Example_Index][1] << endl;

            }


        }
        cin >> Input_Answer;
        if (Input_Answer == 'q')
        {
            break;
        }
        if (Input_Answer == Correct_Answer)
        {
            cout << "정답 !" << endl;
            review_korean_quiz[i][0] = L"";  //맞추면 오답노트에서 제거를 하기위해 erase 함수를 사용하면 에러가 나기 때문에 공백으로 바꿈
            review_korean_quiz[i][1] = L"";
        }
        else
        {
            wcout << L"오답 " << "\n" << L"정답은 " << review_korean_quiz[i][1] << endl;
        }
        Shuffle_vector(review_korean_quiz);
        for (int j = 0; j < review_korean_quiz.size(); j++) {//공백은 제외하기위해 처리
            i++;
            if (i > review_korean_quiz.size()) {
                i = 0;
            }
            if (review_korean_quiz[j][0] != L"") {
                i = j;
                break;
            }
        }
        int num = 0;
        for (int j = 0; j < review_korean_quiz.size(); j++) {
            if (review_korean_quiz[j][0] == L"") { //공백의 수를 셈.
                num++;
            }
        }
        if (num == review_korean_quiz.size()) { //공백의 수가 사이즈와 같으면 삭제하고 나감.
            for (int j = 0; j < num; j++) {//공백으로 바뀐 배열은 삭제
                review_korean_quiz.pop_back();
            }
            break;
        }
    }
    system("pause");


}