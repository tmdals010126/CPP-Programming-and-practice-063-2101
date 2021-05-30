
#include <iostream>
#include <string>
#include <vector>
#include <clocale>  // wstring,wcin,wcout ���

using namespace std;

//**********************************************************************************
//���� �ڵ忡�� ����ü�� �Ǿ������� ä���� ���� �и��ϴٺ��� ������ ���� �Ǿ����ϴ�.
//**********************************************************************************

vector< vector<wstring>>text; // 2���� ���͸� ���������� �ѱ��� string ���� �ҽ� ������ �߻��ؼ� wstring ���� ����
vector<wstring> temp;         // Eng_Word,Kor_Word ����, ���������ܾ ��� �����Ͽ� 2���� ���� �迭�� �Է��Ҷ� ���

bool IsEnglish(wchar_t ch) // ���� ����
    {
        if ((0x61 <= ch && ch <= 0x7A) || (0x41 <= ch && ch <= 0x5A))
            return true;
        else
            return false;
    }

    bool IsKorean(wchar_t ch) // �ѱ� ����
    {
        //( �ѱ��� || ���� , ���� )
        if ((0xAC00 <= ch && ch <= 0xD7A3) || (0x3131 <= ch && ch <= 0x318E))
            return true;
        else
            return false;
    }

    void Input_Word()
    {
        wstring Eng_Word;
        wstring Kor_Word;
        int if_diff_lang = 0; //������ ���� �ܾ ���Դ��� Ȯ���ϴ� ����
        while (true)
        {
            cout << "<<<<<<< ������ �ܾ �Է����ּ��� (�Է��� �׸��ϰ� ������ q�� �Է����ּ���.) >>>>>>>" << endl;
            getline(wcin, Eng_Word); // �����̽��ٵ� �Է��� �ޱ����� wcin ��� ���
            cout << "\n";

            if (Eng_Word == L"q") {
                break;
            }

            for (int i = 0; i < Eng_Word.size(); i++) {
                if (!IsEnglish(Eng_Word.c_str()[i])) {
                    cout << "��� �Է����ֽñ� �ٶ��ϴ�." << endl;
                    if_diff_lang = 1;
                    break;
                }
            }
            if (if_diff_lang == 1) {
                if_diff_lang = 0;
                continue;
            }
            cout << "<<<<<<< �ܾ��� ���� �Է����ּ��� >>>>>>>" << endl;
            getline(wcin, Kor_Word);// �����̽��ٵ� �Է��� �ޱ����� wcin ��� ���
            cout << "\n";
            if (Eng_Word == L"q" || Kor_Word == L"q") {
                break;
            }
            for (int i = 0; i < Kor_Word.size(); i++) {
                if (!IsKorean(Kor_Word.c_str()[i])) {
                    if (Kor_Word.c_str()[i]==0x20){ //�����̽��� ó��
                        continue;
                    }
                    cout << "�ѱ��� �Է����ֽñ� �ٶ��ϴ�." << endl;
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