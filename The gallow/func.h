// ������������ ���� � ��������� � ������������ ��������

// ������
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

//������
bool proverka(string word, string &word_copy, char lett, int &mis)
{
	bool flag = false;
	for (int i = word.size();i >= 0;i--) {
        system("cls");
		if (word[i] == lett) {
			word_copy.replace(i, 1,  "*");
			flag = true;
		}
	}
	if (flag) {
		cout << "����� " << lett << " �����\n";
	}
	else {
		mis++;
		cout << "�������. � ��� �������� " << 6 - mis << " ������� \n";
	}
	for (int i = 0; i < word.size();i++) {
		if (word[i] == word_copy[i]) {
			cout << "_";
		}
		else {
			cout << word[i];
		}
	}
	return flag;
}

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
