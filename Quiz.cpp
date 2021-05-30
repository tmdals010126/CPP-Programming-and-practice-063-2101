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
//���͹迭���� �����Ʈ���� ����Ǯ�ÿ� Ǯ���� ������ �����Ǵ� ��ɿ��� ������ ����Ű�°� �����߽��ϴ�.
//��Ÿ ���� ���� ������ �����߽��ϴ�.



vector< vector<wstring>>text; // 2���� ���͸� ���������� �ѱ��� string ���� �ҽ� ������ �߻��ؼ� wstring ���� ����
vector< vector<wstring>>review_korean_quiz; // ���䳻�� ����
vector< vector<wstring>>review_english_quiz; // ���䳻�� ����
vector<wstring> temp;         // Eng_Word,Kor_Word ����
vector<wstring> review_temp;  // Ʋ�� Eng_Word,Kor_Word ����
vector<wstring> load_data;    // �ؽ�Ʈ���Ͽ� ����� ��Ʈ�� ����

void Shuffle_vector(vector< vector<wstring>>& v) //�ٸ��迭�� �����Ҽ��ֵ��� �Լ� �߰�
{
    wstring temp1;              // �ܾ�  �ӽ� �������
    wstring temp2;              // �ܾ��� �� �ӽ� �������
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
        cout << "������ ���� ��ŭ �ܾ �������� �ʾҽ��ϴ�." << endl;
        return;
    }
    int Input_Number;
    cout << "Ǯ���� �ϴ� ���� ������ �Է��� �ֽÿ�. ( 1 ~ " << text.size() << " )" << endl;
    cin >> Input_Number;

    for (int i = 0; i < Input_Number; i++)
    {
        int Input_Answer; //����� �Է� ����
        int Correct_Answer;    // ���� ����
        int Example_Index = 123; //3�̻��� �ɼ����⿡ �ӽ÷� 123���� �ʱ�ȭ 

        minstd_rand rand_kor(time(NULL));

        wcout << L"����" << i + 1 << L": " << text[i][0] << endl; //����ܾ� ���

        Correct_Answer = rand_kor() % 3 + 1;  // ���� ���� ��ȣ �ű��
        for (int j = 1; j < 4; j++)
        {

            if (j == Correct_Answer)                              // ���� ���� ����
            {
                wcout << j << L": " << text[i][1] << endl; //���� �ѱ� �� ������
            }
            else                                           // ���� ���� ����
            {
                int Kor;
                do {
                    Kor = rand_kor();
                } while (Kor % text.size() == i || Kor % text.size() == Example_Index);                     // ������ ���⿡ 2�� �ִ� ���� ����
                Example_Index = Kor % text.size();

                wcout << j << L": " << text[Example_Index][1] << endl;

            }


        }
        cin >> Input_Answer;
        if (Input_Answer == 'q') // �Լ������� ���������� ����
        {
            break;
        }
        if (Input_Answer == Correct_Answer)
        {
            cout << "���� !" << endl;
            for (int j = 0; j < static_cast<int>(review_korean_quiz.size()); j++)
            {
                if (text[i][0] == review_korean_quiz[j][0]) review_korean_quiz.erase(review_korean_quiz.begin() + j);  //���߸� �����Ʈ���� ����
            }
        }
        else
        {
            wcout << L"���� " << "\n" << L"������ " << text[i][1] << endl;

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
                int count = 0;                        // �ߺ� check count
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
            cout << "Ʋ�� ������ �����ϴ�." << endl;
            system("pause");
            return;
        }
        wcout << L"����" << i + 1 << ": " << review_english_quiz[i][1] << endl; //�ѱ� �ܾ� ���
        getline(wcin, answer); // �����̽��ٵ� �Է��� �ޱ����� wcin ��� ���
        if (answer == L"q")
        {
            break;
        }
        if (answer == review_english_quiz[i][0])
        {
            cout << "Correct ! " << endl;
            review_english_quiz[i][0] = L"";//���߸� �����Ʈ���� ���Ÿ� �ϱ����� erase �Լ��� ����ϸ� ������ ���� ������ �������� �ٲ�
            review_english_quiz[i][1] = L"";
        }
        else
        {
            cout << "Wrong !" << endl;
            wcout << L"Answer is: " << review_english_quiz[i][0] << endl;
        }
        Shuffle_vector(review_english_quiz);
        for (int j = 0; j < review_english_quiz.size(); j++) {//������ �����ϱ����� ó��
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
        for (int j = 0; j < review_english_quiz.size(); j++) {//������ ���� ��
            if (review_english_quiz[j][0] == L"") {
                num++;
            }
        }
        if (num == review_english_quiz.size()) {//������ ���� size�� ������ �����ϰ� ����
            for (int j = 0; j < num; j++) {//���͹迭�� �ʱ�ȭ �� ���� ����
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
            cout << "Ʋ�� ������ �����ϴ�." << endl;
            system("pause");
            return;
        }
        int Input_Answer; //����� �Է� ����
        int Correct_Answer;    // ���� ����
        int Review_Example_Index = 123;//2�ʰ��ϼ����⿡ �ӽ÷� 123����

        minstd_rand rand_kor(time(NULL));

        wcout << L"����" << i + 1 << L": " << review_korean_quiz[i][0] << endl; //����ܾ� ���

        Correct_Answer = rand_kor() % 3 + 1;  // ���� ���� ��ȣ �ű��
        for (int j = 1; j < 4; j++)
        {

            if (j == Correct_Answer)                              // ���� ���� ����
            {
                wcout << j << L": " << review_korean_quiz[i][1] << endl; //���� �ѱ� �� ������
            }
            else                                           // ���� ���� ����
            {
                int Kor;
                do {
                    Kor = rand_kor();
                } while (text[Kor % text.size()][1] == review_korean_quiz[i][1] || Kor % text.size() == Review_Example_Index); // ���� 2��,���� ��������
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
            cout << "���� !" << endl;
            review_korean_quiz[i][0] = L"";  //���߸� �����Ʈ���� ���Ÿ� �ϱ����� erase �Լ��� ����ϸ� ������ ���� ������ �������� �ٲ�
            review_korean_quiz[i][1] = L"";
        }
        else
        {
            wcout << L"���� " << "\n" << L"������ " << review_korean_quiz[i][1] << endl;
        }
        Shuffle_vector(review_korean_quiz);
        for (int j = 0; j < review_korean_quiz.size(); j++) {//������ �����ϱ����� ó��
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
            if (review_korean_quiz[j][0] == L"") { //������ ���� ��.
                num++;
            }
        }
        if (num == review_korean_quiz.size()) { //������ ���� ������� ������ �����ϰ� ����.
            for (int j = 0; j < num; j++) {//�������� �ٲ� �迭�� ����
                review_korean_quiz.pop_back();
            }
            break;
        }
    }
    system("pause");


}