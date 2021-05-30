#include <iostream>
#include <string>
#include<windows.h>//gotoxy함수를 사용하기위해 사용
#include<conio.h>//_getch()를 사용하기위해 사용 - 방향키를 사용하기위함

using namespace std;

void gotoxy(int x, int y) {
    COORD Pos; //x, y를 가지고 있는 구조체 
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void init() {
    system("mode con cols=120 lines=35 | title 단어장");//위에 창에 뜨는 정보와 창 크기
}
int mainmenu() {
    system("cls");//콘솔화면 초기화
    cout << "\n\n\n\n";
    cout << "                    ##      ##  #######  ########  ########     ######## ########  ######  ########" << endl;
    cout << "                    ##  ##  ## ##     ## ##     ## ##     ##       ##    ##       ##    ##    ##" << endl;
    cout << "                    ##  ##  ## ##     ## ##     ## ##     ##       ##    ##       ##          ##" << endl;
    cout << "                    ##  ##  ## ##     ## ########  ##     ##       ##    ######    ######     ##" << endl;
    cout << "                    ##  ##  ## ##     ## ##   ##   ##     ##       ##    ##             ##    ##" << endl;
    cout << "                    ##  ##  ## ##     ## ##    ##  ##     ##       ##    ##       ##    ##    ##" << endl;
    cout << "                     ###  ###   #######  ##     ## ########        ##    ########  ######     ##" << endl;
    //제목
    int x = 49;
    int y = 20;
    int input = 0;

    gotoxy(x - 3, y);
    cout << ">        단어 입력      ";
    gotoxy(x, y + 1);
    cout << "      단어 삭제      ";
    gotoxy(x, y + 2);
    cout << "      단어 섞기      ";
    gotoxy(x, y + 3);
    cout << "      단어 출력      ";
    gotoxy(x, y + 4);
    cout << "     영단어 퀴즈     ";
    gotoxy(x, y + 5);
    cout << "   영단어 뜻 퀴즈    ";
    gotoxy(x, y + 6);
    cout << "      오답노트       ";
    gotoxy(x, y + 7);
    cout << "   틀린 영단어 풀기  ";
    gotoxy(x, y + 8);
    cout << " 틀린 영단어 뜻 풀기 ";
    gotoxy(x, y + 9);
    cout << "     단어장 저장     ";
    gotoxy(x, y + 10);
    cout << "   단어장 불러오기   ";
    gotoxy(x, y + 11);
    cout << "         종료        ";
    while (true) {
        input = _getch();
        if (input == 224) {
            switch (_getch()) {
            case 72: {
                if (y > 20) {
                    gotoxy(x - 3, y);
                    cout << " ";
                    gotoxy(x - 3, --y);
                    cout << "> ";
                }
                break;
            }
            case 80: {
                if (y < 31) {
                    gotoxy(x - 3, y);
                    cout << " ";
                    gotoxy(x - 3, ++y);
                    cout << "> ";
                }
                break;
            }
            }
        }
        if (input == 13) {
            return y - 19;
        }
    }
    return 0;
}
