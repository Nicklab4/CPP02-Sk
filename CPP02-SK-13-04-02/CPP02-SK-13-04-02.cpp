// Задание 2. Очередь из роботов со значением больше
// Робот приходит в очередь и заставляет уходить из конца очереди всех, чей номер
// меньше, чем у него, а потом становится в очередь сам. Последний робот будет иметь
// номер -1 (и, соответственно, не сможет никого выгнать, так как остальные имеют
// положительные номера). Когда он пришёл, нужно вывести все номера в очереди на экран.

#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> vec, int val)
{
    while (vec.size() != 0 && vec[vec.size() - 1] < val)
        vec.pop_back();

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

        vec = add(vec, num);
    }

    std::cout << "Роботы в очереди: ";
    printVec(vec);
}
