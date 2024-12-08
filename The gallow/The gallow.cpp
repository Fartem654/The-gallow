#include "func.h"
using namespace std;
int main() {
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Описание игры и дальнейших действий
    cout << "Игра Виселица\nКомпьютер загадывает слово, ваша задача отгадать это слово подбирая русские буквы. При выборе неверной буквы вы допускаете ошибку и у вас сгорает одна попытка. Вы можете допустить не более 6 ошибок.\n";
    cout << "\n";
    // Объявление переменных
    int miss=0,hits=0;
    char letter;
    string word=choice_word(),word_copy=word,word_res;

    for (int i = 0;i < word.size();i++)
        word_res.append("*");
    cout << "Длина слова: " << word.size();
    while (!(word_copy==word_res or miss==6)) {
        // Ввод буквы
        cout << "\nВведите букву: ";
        cin >> letter;
        // Проверка введенной буквы на корректность
        check_input(letter);
        // Анализ буквы и исходного слова
        !proverka(word, word_copy, letter, miss);
    }

    // Конечный вывод
    if (miss != 6) {
        cout << "\nПоздравляем, Вы отгадали слово!\nЧисло ошибок: " << miss << endl;
    }
    else {
        for (int i = 0;i < word.size();i++)
            if (word_copy[i] == '*')
                hits++;
        cout << "\nВы проиграли :(\nВы отгадали: "<<hits<<" из "<<word.size()<<" букв\nЗагаданное слово было: "<<word << endl;
    }
}