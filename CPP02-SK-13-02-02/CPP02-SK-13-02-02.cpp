// Задание 2. Лечебница
// Напишите программу для картотеки пациентов лечебницы. С клавиатуры вводится
// неизвестное количество целых положительных чисел - возрастов пациентов. Когда
// пациенты заканчиваются, медсестра вводит число -1. Это говорит программе о том,
// что пора заканчивать с приемом пациентов и переходить к расчету статистики.

// Напишите программу, складывающую в вектор целые положительные числа, пока не
// поступит отрицательное число. После этого выведите среднее значение всех введенных
// чисел и их количество.

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
    std::vector<int> vec = {};

    int num = 0;
    int sum = 0;

    while (true)
    {
        std::cout << "Please, enter your age: ";
        std::cin >> num;

        if (num < 0)
            break;

        vec = add(vec, num);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }

    std::cout << "Middle age of pacient is " << (float)sum / vec.size() << "\n";
}