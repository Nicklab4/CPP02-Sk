// Задание 3. Роботы и коррупция*
// Улучшите электронную очередь для роботов. К нам приходят роботы разного социального
// статуса. Каждый робот вводит не только свой уникальный номер, но и свое место в
// очереди. Например, пусть в нашей очереди 10 роботов и к нам приходит 11-й. Сначала
// он вводит свой номер, как и раньше, а затем свое место в очереди - например, 5. В
// этом случае он должен оказаться в очереди пятым, а все остальные, начиная со старого
// пятого - подвинуться дальше в конец очереди.

// Реализуйте функцию:
// std::vector<int> add_to_position(std::vector vec, int val, int position)

#include <iostream>
#include <vector>

std::vector<int> add_to_position(std::vector<int> vec, int val, int position)
{
    std::vector<int> newVec(vec.size() + 1);

    for (int i = 0; i < position - 1; i++)
        newVec[i] = vec[i];

    newVec[position - 1] = val;

    for (int i = position; i < vec.size() + 1; i++)
    {
        newVec[i] = vec[i - 1];
    }

    return newVec;
}

int main()
{
    std::vector<int> vec = {3, 4, 35, 19, 1};

    int num;
    int pos;

    while (true)
    {
        std::cout << "Please, enter your number and position: ";
        std::cin >> num >> pos;

        if (num < 0 || pos <= 0)
            break;

        vec = add_to_position(vec, num, pos);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n";
}