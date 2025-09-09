// Задание 2
// Представим, что роботов могут не только покупать, забирая с витрины, но и
// «выставлять» в конец витрины. Пусть с клавиатуры вводят число K, а потом — K
// запросов вида 1 n и 2 m. Запрос вида 1 n означает, что в конец витрины поставили
// робота с номером n. Запрос 2 m означает, что с витрины забрали робота по индексу m.
// Необходимо смоделировать такое взаимодействие и после проведения всех запросов
// вывести на экран оставшихся на витрине роботов.

#include <iostream>
#include <vector>

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

std::vector<int> vecOut(std::vector<int> vec, int n)
{

    std::vector<int> newVec(vec.size() - 1);

    for (int i = 0; i < n; i++)
    {
        newVec[i] = vec[i];
    }

    for (int i = n; i < vec.size() - 1; i++)
    {
        newVec[i] = vec[i + 1];
    }

    return newVec;
}

std::vector<int> vecAdd(std::vector<int> vec, int n)
{
    vec.resize(vec.size() + 1);
    vec[vec.size() - 1] = n;

    return vec;
}

int main()
{
    std::vector<int> vec;
    int k, n, m;

    std::cout << "Введите количество запросов (K): ";
    std::cin >> k;



    std::cout << "Введите запрос:\n1 n - добавить робота с номером n\n2 m - убрать робота с индексом m\n";

    for (int i = 1; i <= k; i++)
    {
        std::cin >> n >> m;
        if (n == 1)
        {
            vec = vecAdd(vec, m);
            std::cout << "Добавили робота с номером " << m << "\n";
            std::cout << "На витрине стоят роботы ";
            printVec(vec);
        }
        else if (n == 2)
        {
            if (m >= vec.size() || m < 0)
            {
                std::cout << "Такого индекса нет, введите запрос заново\n";
                i--;
                continue;
            }
            else
                vec = vecOut(vec, m);

            std::cout << "Забрали робота с индексом " << m << "\n";
            std::cout << "На витрине остались роботы ";
            printVec(vec);
        }
        else
        {
            std::cout << "Ошибка! Первое число должно быть 1 или 2, введите запрос заново\n";
            i--;
        }
    }
}