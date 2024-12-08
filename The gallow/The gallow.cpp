#include "func.h"
using namespace std;
int main() {
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // описание игры и дальнейших действий
    cout << "Игра Виселица\n";

    // Объявление переменных
    int miss;
    char letter;
    string word=choice_word();
    while () {
        // Ввод буквы
        cout << "Введите букву";
        cin >> letter;
        // Проверка введенной буквы на корректность
        check_input(letter);
        // Анализ буквы и исходного слова
        proverka(word, letter, miss);
        // Проверка условий выйгрыша/пройгрыша
        // ......  
    }

    // Конечный вывод
    if () {
        cout << "Поздравляем, Вы отгадали слово!\nЧисло ошибок: " << mis;
    }
    else {
        cout << "Вы проиграли :(\n";
    }
}