// ������������ ���� � ��������� � ������������ ��������

// ������
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

//������

// ��������� ������� ���������� ����� �� �������������� ������.
string choice_word()
{
    const int n = 18;
    string words[n] = { "����",
        "�������", "���", "������", "����", "���", "������", "����", "������", "�����", "��������", "����", "���", "�����", "����", "�������", "���",
        "�������" }, str;
    str = words[rand() % n];

    return str;
}

// �������� ����� ���� �������������.
// � - 192 � - 223 � - 224 � - 255
void check_input(char& lett) {
    unsigned char lt = lett;
    int value;
    bool f = 0;
    while (!f) {
        value = (int)lt;
        if ((value >= 224 and value <= 255) or (value >= 192 and value <= 223)) {
            f = 1;
            if (value >= 192 and value <= 223)
                value = value + 32;
        }
        else if (value == 184 or value == 168) {// ������ �/� �� �
            f = 1;
            value = 229;
        }
        else {
            //system("cls");
            cout << "�� ����� �� ��� ������.\n������� ����� �� �������� �������� ��� ���: ";
            cin >> lt;
        }
    }
    lett = (char)value;
}
