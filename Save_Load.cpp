#include <iostream>
#include <string>
#include <vector>
#include <clocale>  // wstring,wcin,wcout ���
#include <ctime>
#include <random>
#include <iomanip> //����������� ���� ��� print_Word�Լ����� ���
#include<windows.h>//gotoxy�Լ��� ����ϱ����� ���
#include<conio.h>//_getch()�� ����ϱ����� ��� - ����Ű�� ����ϱ�����
#include<fstream>//����������� ���� ���


using namespace std;
//**********************************************************************************
//���� �ڵ忡�� ����ü�� �Ǿ������� ä���� ���� �и��ϴٺ��� ������ ���� �Ǿ����ϴ�.
//**********************************************************************************

vector<wstring> load_data;    // �ؽ�Ʈ���Ͽ� ����� ��Ʈ�� ����
vector< vector<wstring>>text; // 2���� ���͸� ���������� �ѱ��� string ���� �ҽ� ������ �߻��ؼ� wstring ���� ����
vector< vector<wstring>>review_korean_quiz; // ���䳻�� ����
vector< vector<wstring>>review_english_quiz; // ���䳻�� ����
vector<wstring> temp;         // Eng_Word,Kor_Word ����, ���������ܾ ��� �����Ͽ� 2���� ���� �迭�� �Է��Ҷ� ���

void fileRead(wifstream& fin, vector<wstring>& v)
{
    wstring line;

    while (getline(fin, line))
        v.push_back(line);
}
void Load_Word() { //�����Ʈ�� �о������ ����
    wstring Load_Kor, Load_Eng;
    Load_Kor = L"";
    Load_Eng = L"";
    wifstream fin("Word.txt");
    fin.imbue(std::locale("kor"));//�ѱ����ڵ������ؼ� ���������� �ѱ��� ������
    int if_find = 0;
    if (fin.fail()) {
        cout << "����� �ܾ����� �����ϴ�." << endl;
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
            temp.pop_back(); //text ���� �ڿ� �̾� ������
            Load_Kor = L"";
            Load_Eng = L""; //�ʱ�ȭ
        }
    }
    int num = load_data.size();
    for (int i = 0; i < num; i++) {
        load_data.pop_back();//load_data �ʱ�ȭ
    }
    wifstream kfin("review_korean_quiz.txt");
    kfin.imbue(std::locale("kor"));//�ѱ����ڵ������ؼ� ���������� �ѱ��� ������
    if_find = 0;
    if (kfin.fail()) {
        cout << "����� �ܾ����� �����ϴ�." << endl;
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
            temp.pop_back(); //text ���� �ڿ� �̾� ������
            Load_Kor = L"";
            Load_Eng = L""; //�ʱ�ȭ
        }
    }
    num = load_data.size();
    for (int i = 0; i < num; i++) {
        load_data.pop_back();//load_data �ʱ�ȭ
    }
    wifstream efin("review_english_quiz.txt");
    efin.imbue(std::locale("kor"));//�ѱ����ڵ������ؼ� ���������� �ѱ��� ������
    if_find = 0;
    if (efin.fail()) {
        cout << "����� �ܾ����� �����ϴ�." << endl;
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
            temp.pop_back(); //text ���� �ڿ� �̾� ������
            Load_Kor = L"";
            Load_Eng = L""; //�ʱ�ȭ
        }
        wcout << L"���������� �ҷ��Խ��ϴ�." << endl;
        system("pause");
        return;
    }

}

void Save_Word() { //�����Ʈ�� ����ϵ��� ����
    wstring Save_data;

    wofstream fout("Word.txt", wios::out);
    fout.imbue(std::locale("kor")); //�ѱ����ڵ������ؼ� �� �ڵ带 ���������� �ѱ��� ������
    for (int i = 0; i < text.size(); i++) {
        Save_data = text[i][0] + L"|" + text[i][1];
        fout << Save_data << endl;
    }
    fout.close();
    wofstream kfout("review_korean_quiz.txt", wios::out);
    kfout.imbue(std::locale("kor")); //�ѱ����ڵ������ؼ� �� �ڵ带 ���������� �ѱ��� ������
    for (int i = 0; i < review_korean_quiz.size(); i++) {
        Save_data = review_korean_quiz[i][0] + L"|" + review_korean_quiz[i][1];
        kfout << Save_data << endl;
    }
    kfout.close();
    wofstream efout("review_english_quiz.txt", wios::out);
    efout.imbue(std::locale("kor")); //�ѱ����ڵ������ؼ� �� �ڵ带 ���������� �ѱ��� ������
    for (int i = 0; i < review_english_quiz.size(); i++) {
        Save_data = review_english_quiz[i][0] + L"|" + review_english_quiz[i][1];
        efout << Save_data << endl;
    }
    efout.close();
    wcout << L"���������� �����߽��ϴ�." << endl;
    system("pause");
    return;
}
