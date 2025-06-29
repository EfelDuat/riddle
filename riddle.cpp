#include <iostream>
#include <string>
#include <windows.h>  // для SetConsoleCP и SetConsoleOutputCP
#include <algorithm>

using namespace std;

// Приведение русских символов Windows-1251 к нижнему регистру
char toLowerRu(char ch) {
    if (ch >= -64 && ch <= -33) // А-Я (в диапазоне -64..-33 в signed char)
        return ch + 32;         // а-я
    if (ch == -88)              // 'Ё'
        return -72;             // 'ё'
    return ch;
}

int main()
{
    SetConsoleCP(1251);        // ввод с консоли в Windows-1251
    SetConsoleOutputCP(1251);  // вывод в консоль в Windows-1251
    setlocale(LC_ALL, "Russian");

    string answer;
    string correctAnswer = "ёжик";

    cout << "Вот с иголками клубок" << endl;
    cout << "Подкатился на порог" << endl;
    cout << "Глаза - бусинки глядят" << endl;
    cout << "Молочка они хотят" << endl;
    cout << "Ваш ответ: ";

    getline(cin, answer);  // читаем строку

    // Преобразуем в нижний регистр русских символов
    transform(answer.begin(), answer.end(), answer.begin(), toLowerRu);

    if (answer == correctAnswer)
    {
        cout << "Правильно! Вы угадали!" << endl;
    }
    else
    {
        cout << "К сожалению, ваш ответ не верный!" << endl;
        cout << "Правильный ответ: " << correctAnswer << endl;
    }

    return 0;
}