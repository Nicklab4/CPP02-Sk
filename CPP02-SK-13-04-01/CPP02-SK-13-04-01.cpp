// Задание 1. Очередь из роботов с помощью push_back
// С помощью push_back() реализуйте очередь из роботов-андроидов. Роботы приходят в
// очередь и называют(вводят с клавиатуры) свои порядковые номера (целые положительные).
// Последний робот в очереди всегда имеет номер -1. Когда он пришёл, необходимо
// вывести на экран все номера в очереди.

#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> vec, int val)
{
    vec.push_back(val);

    return vec;
}

void printVec(std::vector<int> vec)
{
    std::cout << "{";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i == vec.size() - 1)
            break;
        else
            std::cout << ", ";
    }
    std::cout << "}\n";
}

int main()
{
    std::vector<int> vec;

    int num = 0;

    while (num != -1)
    {
        std::cout << "Введите номер робота: ";
        std::cin >> num;

        vec= add(vec, num);
    }

    std::cout << "Роботы в очереди: ";
    printVec(vec);
}
