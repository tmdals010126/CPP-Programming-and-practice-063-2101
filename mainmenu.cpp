
#include <iostream>
#include <string>
#include<windows.h>//gotoxy�Լ��� ����ϱ����� ���
#include<conio.h>//_getch()�� ����ϱ����� ��� - ����Ű�� ����ϱ�����

using namespace std;

void gotoxy(int x, int y) {
    COORD Pos; //x, y�� ������ �ִ� ����ü 
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void init() {
    system("mode con cols=120 lines=35 | title �ܾ���");//���� â�� �ߴ� ������ â ũ��
}
int mainmenu() { // ���θ޴� �Լ�
    system("cls");//�ܼ�ȭ�� �ʱ�ȭ
    cout << "\n\n\n\n";
    cout << "                    ##      ##  #######  ########  ########     ######## ########  ######  ########" << endl;
    cout << "                    ##  ##  ## ##     ## ##     ## ##     ##       ##    ##       ##    ##    ##   " << endl;
    cout << "                    ##  ##  ## ##     ## ##     ## ##     ##       ##    ##       ##          ##   " << endl;
    cout << "                    ##  ##  ## ##     ## ########  ##     ##       ##    ######    ######     ##   " << endl;
    cout << "                    ##  ##  ## ##     ## ##   ##   ##     ##       ##    ##             ##    ##   " << endl;
    cout << "                    ##  ##  ## ##     ## ##    ##  ##     ##       ##    ##       ##    ##    ##   " << endl;
    cout << "                     ###  ###   #######  ##     ## ########        ##    ########  ######     ##   " << endl;
    //���� https://wepplication.github.io/tools/asciiArtGen/ �� ����Ʈ���� Banner3 Font�� ����Ͽ� ��ȯ�Ͽ���.
    int x = 49;
    int y = 20;
    int input = 0;

    gotoxy(x-3, y);
    cout << ">        �ܾ� �Է�      ";
    gotoxy(x, y + 1);
    cout << "      �ܾ� ����      ";
    gotoxy(x, y + 2);
    cout << "      �ܾ� ����      ";
    gotoxy(x, y + 3);
    cout << "      �ܾ� ���      ";
    gotoxy(x, y + 4);
    cout << "     ���ܾ� ����     ";
    gotoxy(x, y + 5);
    cout << "   ���ܾ� �� ����    ";
    gotoxy(x, y + 6);
    cout << "      �����Ʈ       ";
    gotoxy(x, y + 7);
    cout << "     �ܾ��� ����     ";
    gotoxy(x, y + 8);
    cout << "   �ܾ��� �ҷ�����   ";
    gotoxy(x, y + 9);
    cout << "         ����        ";
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
                if (y < 29) {
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

int reviewmenu() { //�����Ʈ ���� �޴� ���� �Լ�
    system("cls");//�ܼ�ȭ�� �ʱ�ȭ
    cout << "\n\n\n\n";
    cout << "    ########  ######## ##     ## #### ######## ##      ##    ##    ##  #######  ######## ########  ######  " << endl;
    cout << "    ##     ## ##       ##     ##  ##  ##       ##  ##  ##    ###   ## ##     ##    ##    ##       ##    ## " << endl;
    cout << "    ##     ## ##       ##     ##  ##  ##       ##  ##  ##    ####  ## ##     ##    ##    ##       ##       " << endl;
    cout << "    ########  ######   ##     ##  ##  ######   ##  ##  ##    ## ## ## ##     ##    ##    ######    ######  " << endl;
    cout << "    ##   ##   ##        ##   ##   ##  ##       ##  ##  ##    ##  #### ##     ##    ##    ##             ## " << endl;
    cout << "    ##    ##  ##         ## ##    ##  ##       ##  ##  ##    ##   ### ##     ##    ##    ##       ##    ## " << endl;
    cout << "    ##     ## ########    ###    #### ########  ###  ###     ##    ##  #######     ##    ########  ######  " << endl;
    //�����Ʈ ���� ���� https://wepplication.github.io/tools/asciiArtGen/ �� ����Ʈ���� Banner3 Font�� ����Ͽ� ��ȯ�Ͽ���.

    int x = 49;
    int y = 20;
    int input = 0;
    gotoxy(x-3, y + 0);
    cout << ">      Ʋ�� �ܾ� ���   ";
    gotoxy(x, y + 1);
    cout << "   Ʋ�� ���ܾ� Ǯ��  ";
    gotoxy(x, y + 2);
    cout << " Ʋ�� ���ܾ� �� Ǯ�� ";
    gotoxy(x, y + 3);
    cout << "        ������       ";
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
                if (y < 23) {
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

