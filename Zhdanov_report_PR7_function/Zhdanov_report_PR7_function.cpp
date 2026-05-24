#include <iostream>
#include <string>
#include <limits>
#include <clocale>

using namespace std;
// ======================================
// ЗАДАНИЕ 1
// Перегрузка функций, void
// ======================================

// Палиндром
void checkString(string& str, bool& result)
{
    result = true;

    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            result = false;
            return;
        }

        left++;
        right--;
    }
}

// Только латинские буквы
void checkString(char* str, int* result)
{
    *result = 1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z')))
        {
            *result = 0;
            return;
        }
    }
}

// Главная функция задания 1
void task1()
{
    string str;
    bool pal;

    cout << "Введите строку: ";
    cin >> str;

    checkString(str, pal);

    if (pal)
        cout << "Палиндром\n";
    else
        cout << "Не палиндром\n";

    char text[100];
    int res;

    cout << "Введите строку из латинских букв: ";
    cin >> text;

    checkString(text, &res);

    if (res == 1)
        cout << "Только латинские буквы\n";
    else
        cout << "Есть другие символы\n";
}
// ======================================
// ЗАДАНИЕ 2
// Пространства имен
// ======================================

namespace Palindrome
{
    void check(const string& str, bool& result)
    {
        result = true;

        int left = 0;
        int right = str.length() - 1;

        while (left < right)
        {
            if (str[left] != str[right])
            {
                result = false;
                return;
            }

            left++;
            right--;
        }
    }
}

namespace Latin
{
    void check(const string& str, bool& result)
    {
        result = true;

        for (char c : str)
        {
            if (!((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z')))
            {
                result = false;
                return;
            }
        }
    }
}

// Главная функция задания 2
void task2()
{
    string str;
    bool result;

    cout << "Введите строку: ";
    cin >> str;

    Palindrome::check(str, result);

    if (result)
        cout << "Палиндром\n";
    else
        cout << "Не палиндром\n";

    Latin::check(str, result);

    if (result)
        cout << "Только латинские буквы\n";
    else
        cout << "Есть другие символы\n";
}

// ======================================
// ЗАДАНИЕ 3
// Шаблонная функция
// ======================================

template <typename T>
T maxNegative(T arr[], int size)
{
    bool found = false;
    T maxNeg = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (!found || arr[i] > maxNeg)
            {
                maxNeg = arr[i];
                found = true;
            }
        }
    }

    return maxNeg;
}

// Главная функция задания 3
void task3()
{
    const int SIZE = 5;

    int arr1[SIZE] = { -5, -2, 4, -1, 8 };
    double arr2[SIZE] = { -7.5, 2.1, -3.4, -1.2, 9.0 };

    cout << "Максимальный отрицательный int: "
        << maxNegative(arr1, SIZE) << endl;

    cout << "Максимальный отрицательный double: "
        << maxNegative(arr2, SIZE) << endl;
}

// ======================================
// ЗАДАНИЕ 4
// Рекурсия
// ======================================

int countDigits(int n)
{
    n = abs(n);

    if (n < 10)
        return 1;

    return 1 + countDigits(n / 10);
}

// Главная функция задания 4
void task4()
{
    int number;

    cout << "Введите число: ";
    cin >> number;

    cout << "Количество разрядов: "
        << countDigits(number) << endl;
}

// ======================================
// ЗАДАНИЕ 5
// Лямбда-функция
// ======================================

int secondMax(int arr[], int size,
    auto compare)
{
    int max1 = arr[0];
    int max2 = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (compare(arr[i], max1))
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (compare(arr[i], max2) &&
            arr[i] != max1)
        {
            max2 = arr[i];
        }
    }

    return max2;
}

// Главная функция задания 5
void task5()
{
    int arr[5] = { 4, 9, 2, 7, 5 };

    auto compare = [](int a, int b)
        {
            return a > b;
        };

    cout << "Второй максимальный элемент: "
        << secondMax(arr, 5, compare)
        << endl;
}

// ======================================
// Проверка ввода
// ======================================

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ======================================
// MAIN
// ======================================

int main()
{
	setlocale(LC_ALL, "Russian");
    int choice;

    do
    {
        cout << "\n========== МЕНЮ ==========\n";
        cout << "1. Задание 1\n";
        cout << "2. Задание 2\n";
        cout << "3. Задание 3\n";
        cout << "4. Задание 4\n";
        cout << "5. Задание 5\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";

        cin >> choice;

        if (cin.fail())
        {
            clearInput();
            cout << "Ошибка ввода!\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            task1();
            break;

        case 2:
            task2();
            break;

        case 3:
            task3();
            break;

        case 4:
            task4();
            break;

        case 5:
            task5();
            break;

        case 0:
            cout << "Программа завершена.\n";
            break;

        default:
            cout << "Неверный пункт меню!\n";
        }

    } while (choice != 0);

    return 0;
}