// Задание 1
// Пользователь вводит с клавиатуры число n, а затем -- n целых чисел.
// Необходимо вычислить их среднее арифметическое и вывести на экран.

#include <iostream>
#include <vector>

int main()
{
    int n;
    int sum = 0;
    float middle = 0;

    std::cout << "Введите общее количество элементов: ";
    std::cin >> n;

    std::vector<int> massiv(n);

    std::cout << "Задайте значения элементов: \n";

    for (int i = 0; i < n; i++)
    {
        std::cin >> massiv[i];
        sum += massiv[i];
    }

    middle = sum / (float)n;

    std::cout << "Среднее арифметическое значение: " << middle << "\n";
}