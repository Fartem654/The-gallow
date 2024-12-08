#include "func.h"
using namespace std;
int main() {
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // описание игры и дальнейших действий
    cout << "Игра Виселица\n";

    // Объявление переменных
    int miss=0,u=0;
    char letter;
    string word=choice_word(),word_copy=word,word_res;
    for (int i = 0;i < word.size();i++)
        word_res.append("*");

    while (!(word_copy==word_res or miss==6)) {
        // Ввод буквы
        cout << "Введите букву";
        cin >> letter;
        // Проверка введенной буквы на корректность
        check_input(letter);
        // Анализ буквы и исходного слова
        proverka(word, word_copy, letter, miss);
    }

    // Конечный вывод
    if (miss != 6) {
        cout << "Поздравляем, Вы отгадали слово!\nЧисло ошибок: " << miss;
    }
    else {
        for (int i = 0;i < word.size();i++)
            if (word_copy[i] == '*')
                u++;
        cout << "Вы проиграли :(\nВы отгадали: "<<u<<" из "<<word.size()<<" букв";
    }
}