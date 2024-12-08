// Заголовочный файл с функциями и необходимыми модулями

// Модули
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

//Фунции
bool proverka(string word, string word_copy, char lett, int mis)
{
	bool flag = false;
	for (int i = word.size();i > 0;i--) {
		if (word[i] == lett) {
			word_copy.replace(i, 1, "*");
			flag = true;
		}
	}
	if (flag) {
		cout << "Буква" << lett << " верна";
	}
	else {
		mis--;
		cout << "Неверно. У вас осталось " << 6 - mis << "пыток";
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