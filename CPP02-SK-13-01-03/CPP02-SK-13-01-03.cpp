// Задание 3
// Пользователь вводит с клавиатуры число n, а затем -- n целых чисел. Необходимо
// отыскать второе по величине из этих чисел и вывести на экран.

// Дополнение от меня: Если требуется второе число, то предполагается, что чисел
// будет как минимум - два

#include <iostream>
#include <vector>

int main()
{
    int n = -1;
    int max = 0;
    int maxCount = 0;
    int second = 0;

    while (n <= 1)
    {
        std::cout << "Введите общее количество элементов: ";
        std::cin >> n;
        if (n <= 1)
            std::cout << "Ошибка! Количество элементов должно быть 2 или больше. \n";
    }

    std::vector<int> massiv(n);

    std::cout << "Задайте значения элементов: \n";
    std::cin >> massiv[0];
    max = massiv[0];

    for (int i = 1; i < n; i++)
    {
        std::cin >> massiv[i];
        if (massiv[i] > max)
        {
            max = massiv[i];
            maxCount = i;
        }
    }


    if (maxCount == 0)
        second = massiv[1];
    else
        second = massiv[0];

    for (int i = 0; i < n; i++)
    {
        if (i == maxCount)
            continue;

        if (massiv[i] > second)
            second = massiv[i];
    }

    std::cout << "Второе по величине число: " << second << "\n";
}