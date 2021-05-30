#include <iostream>
#include <string>
#include <vector>
#include <clocale>  // wstring,wcin,wcout 사용
#include <ctime>
#include <random>
#include <iomanip> //출력포멧팅을 위한 헤더 print_Word함수에서 사용

//**********************************************************************************
//원래 코드에선 구조체로 되어있지만 채점을 위해 분리하다보니 나누어 적게 되었습니다.
//**********************************************************************************
//메인함수에서 여러가지 한글인코딩 문제를 해결하고 각 함수로 넘어가도록 적음

int main()
{

    _wsetlocale(LC_ALL, L"korean");//한글때문에 출력이안되는경우가있어 선언
    setlocale(LC_ALL, "korean");  //한글때문에 출력이안되는경우가있어 선언

    Word_Test_Diary test;   // 단어장
    int select,review_num;
    init();
    do {
        select = mainmenu();
        system("cls");
        switch (select)
        {
        case 1:
        {
            test.Input_Word();
            break;
        }
        case 2:
        {
            test.Delete_Word();
            break;
        }
        case 3:
        {
            test.Shuffle_Word();
            break;
        }
        case 4:
        {
            test.Print_Word();
            break;
        }
        case 5:
        {
            test.English_Word_Quiz();
            break;
        }
        case 6:
        {
            test.Korean_Word_Quiz();
            break;
        }
        case 7:
        {
            review_num = reviewmenu(); // 오답노트 안의 메뉴선택
            system("cls");
            if (review_num == 1) {
                test.Review_note();
            }
            else if (review_num == 2) {
                test.Review_Eng_Quiz();
            }
            else if (review_num == 3) {
                test.Review_Kor_Quiz();
            }
            else{
            }
            break;
        }
        case 8:
        {
            test.Save_Word();
            break;
        }
        case 9:
        {
            test.Load_Word();
            break;
        }
        default:
            break;
        }

    } while (select != 10);

    cout << "\n<<<<<<< 프로그램을 종료합니다 >>>>>>>>" << endl;

    return 0;
}