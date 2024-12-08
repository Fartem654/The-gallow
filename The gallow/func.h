// Заголовочный файл с функциями и необходимыми модулями

// Модули
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

//Фунции

// Случайным образом выбирается слово из заготовленного списка.
string choice_word()
{
    const int n = 18;
    string words[n] = { "кант",
        "хроника", "зал", "галера", "балл", "вес", "кафель", "знак", "фильтр", "башня", "кондитер", "омар", "чан", "пламя", "банк", "тетерев", "муж",
        "камбала" }, str;
    str = words[rand() % n];

    return str;
}

// Проверка ввода букв пользователем.
// А - 192 Я - 223 а - 224 я - 255
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
        else if (value == 184 or value == 168) {// замена Ё/ё на е
            f = 1;
            value = 229;
        }
        else {
            //system("cls");
            cout << "Вы ввели не тот символ.\nВведите букву из русского алфавита еще раз: ";
            cin >> lt;
        }
    }
    lett = (char)value;
}
