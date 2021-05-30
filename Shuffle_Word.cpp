
#include <iostream>
#include <string>
#include <vector>
#include <clocale>  // wstring,wcin,wcout ���
#include <ctime>
#include <random>

using namespace std;

//**********************************************************************************
//���� �ڵ忡�� ����ü�� �Ǿ������� ä���� ���� �и��ϴٺ��� ������ ���� �Ǿ����ϴ�.
//**********************************************************************************
vector< vector<wstring>>text; // 2���� ���͸� ���������� �ѱ��� string ���� �ҽ� ������ �߻��ؼ� wstring ���� ����
void Shuffle_Word()
{
    wstring temp1;              // �ܾ�  �ӽ� �������
    wstring temp2;              // �ܾ��� �� �ӽ� �������
    minstd_rand rand_shuffle(time(nullptr));
    int n;
    for (int i = static_cast<int>(text.size()) - 1; i >= 0; i--)
    {
        n = rand_shuffle() % text.size();
        temp1 = text[i][0];
        text[i][0] = text[n][0];
        text[n][0] = temp1;
        temp2 = text[i][1];
        text[i][1] = text[n][1];
        text[n][1] = temp2;
    }
}
    void Shuffle_vector(vector< vector<wstring>>&v) //�ٸ��迭�� �����Ҽ��ֵ��� �Լ� �߰�
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

