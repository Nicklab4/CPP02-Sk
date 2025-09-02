// Задание 1. Очередь из роботов
// Повторите программу из теоретического материала. Напишите электронную очередь для
// андроидов. Их количество неизвестно заранее. Каждый андроид вводит с клавиатуры свой
// идентификационный номер - целое число. Нужно сохранить их номера в векторе в том
// порядке, в котором они записывались в очередь.

#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> vec, int val)
{
    std::vector<int> newVec(vec.size() + 1);
    for (int i = 0; i < vec.size(); i++)
        newVec[i] = vec[i];

    newVec[vec.size()] = val;

    return newVec;
}

int main()
{
    std::vector<int> vec = {3, 4, 35, 19, 1};

    int num = 0;

    while (num != -1)
    {
        std::cout << "Please, enter your number: ";
        std::cin >> num;

        vec= add(vec, num);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n";
}