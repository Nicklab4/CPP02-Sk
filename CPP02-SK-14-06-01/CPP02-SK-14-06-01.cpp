// Задание 1. Банкетный стол

// По поводу успешного прохождения двумерных массивов собирается банкет, организуется
// стол на 12 персон. Есть два VIP-места, они рядом во главе стола. Стол протяжён в
// длину, места расположены в два ряда. Каждый пришедший должен быть «упакован»
// соответствующим образом. Во-первых, столовые приборы: по три на каждого человека
// (вилка, ложка, нож) и одна маленькая дополнительная ложечка для VIP-персон (для
// десерта). Во-вторых, тарелки: каждому по две (для первого и второго блюда) и ещё
// одна тарелка для VIP-персон (для десерта). В-третьих, стулья: минимум один для
// каждого гостя. Заведите соответствующие двумерные массивы для количества приборов,
// посуды и стульев и проинициализируйте их.

// Но это ещё не всё. На банкете после инициализации происходят некоторые события.
// Пришедшая на пятое место первого ряда дама привела с собой ребёнка, и поэтому на
// данное место был приставлен ещё один стул. С третьего места во втором ряду в
// неизвестном направлении была украдена ложка. Одна из VIP-персон (любая) поделилась
// своей ложкой с тем, кто остался без ложки, и стала есть суп десертной. За
// ненадобностью официант забрал у VIP-гостя одну десертную тарелку, ведь есть десерт
// ложкой, которая уже побывала уже в супе, неприлично. Больше без происшествий, однако
// эти события на банкете надо отразить в инициализированных ранее массивах.

// Советы и рекомендации
// Все действия в задаче оформляются в виде выражений внутри исходного кода. Текстовый
// интерфейс для задачи делать необязательно.
// Необходимо объявить несколько двумерных массивов (по типам приборов).
// Массивы очень удобно инициализировать сразу при объявлении так:
// int packages[2][3] = {{2, 1, 7},{3, 5, 31}}
// Проще будет сначала записать в массивы значения из задания, а потом отнимать или
// прибавлять нужные элементы, следуя за сценарием событий:
// // packages[0][0] хранит в себе цифру 2, и мы прибавляем к этому значению 1 — += 1.
// packages[0][0] +=1;

// Что оценивается
// Все действия внутри массива соответствуют условию.

#include <iostream>
#include <vector>

void print(std::vector<std::vector<std::vector<std::string>>> seats){
    for (int i = 0; i < seats.size(); i++)
    {
        for (int j = 0; j < seats[i].size(); j++)
        {
            std::cout << "Row-" << j + 1 << ", seat-" << i + 1 << ": ";
            for (int k = 0; k < seats[i][j].size(); k++)
            {
                std::cout << seats[i][j][k] << ", ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    std::cout << "**********************************************************\n";
}

int main()
{

    std::string chair = "chair";    // стул
    std::string fork = "fork";      // вилка
    std::string spoon = "spoon";    // ложка
    std::string knife = "knife";    // нож
    std::string dessertSpoon = "dessert spoon"; // десертная ложка

    std::string plate = "plate";    // тарелка
    std::string soupPlate = "soup plate";       // суповая тарелка
    std::string dessertPlate = "dessert plate"; // десертная тарелка

    std::vector<std::string> person{chair, fork, spoon, knife,
                                    plate, soupPlate};
    std::vector<std::string> vipPerson{chair, fork, spoon, knife, dessertSpoon,
                                       plate, soupPlate, dessertPlate};

    std::vector<std::vector<std::vector<std::string>>> seats{{person, person},
                                                             {person, person},
                                                             {person, person},
                                                             {person, person},
                                                             {person, person},
                                                             {vipPerson, vipPerson}};

    // на пятое место первого ряда был приставлен ещё один стул
    seats[4][0].push_back(chair);

    // С третьего места во втором ряду в неизвестном направлении была украдена ложка
    int temp;
    for (int i = 0; i < seats[2][1].size(); i++)
    {
        if (seats[2][1][i] == "spoon")
        {
            seats[2][1][i].erase();
            temp = i;
            break;
        }
    }

    print(seats);

    // Одна из VIP-персон (любая) поделилась своей ложкой с тем, кто остался без ложки
    for (int i = 0; i < seats[5][0].size(); i++)
    {
        if (seats[5][0][i] == "spoon")
        {
            seats[5][0][i].swap(seats[2][1][temp]);
            break;
        }
    }

    // за ненадобностью официант забрал у VIP-гостя одну десертную тарелку
    seats[5][0].pop_back();

    print(seats);
}

/*

Row-1, seat-1: chair, fork, spoon, knife, plate, soup plate, 
Row-2, seat-1: chair, fork, spoon, knife, plate, soup plate,

Row-1, seat-2: chair, fork, spoon, knife, plate, soup plate, 
Row-2, seat-2: chair, fork, spoon, knife, plate, soup plate,

Row-1, seat-3: chair, fork, spoon, knife, plate, soup plate,
Row-2, seat-3: chair, fork, , knife, plate, soup plate,

Row-1, seat-4: chair, fork, spoon, knife, plate, soup plate, 
Row-2, seat-4: chair, fork, spoon, knife, plate, soup plate,

Row-1, seat-5: chair, fork, spoon, knife, plate, soup plate, chair,
Row-2, seat-5: chair, fork, spoon, knife, plate, soup plate,

Row-1, seat-6: chair, fork, spoon, knife, dessert spoon, plate, soup plate, dessert plate, 
Row-2, seat-6: chair, fork, spoon, knife, dessert spoon, plate, soup plate, dessert plate,

**********************************************************
Row-1, seat-1: chair, fork, spoon, knife, plate, soup plate,
Row-2, seat-1: chair, fork, spoon, knife, plate, soup plate,

Row-1, seat-2: chair, fork, spoon, knife, plate, soup plate, 
Row-2, seat-2: chair, fork, spoon, knife, plate, soup plate,

Row-1, seat-3: chair, fork, spoon, knife, plate, soup plate,
Row-2, seat-3: chair, fork, spoon, knife, plate, soup plate,

Row-1, seat-4: chair, fork, spoon, knife, plate, soup plate, 
Row-2, seat-4: chair, fork, spoon, knife, plate, soup plate,

Row-1, seat-5: chair, fork, spoon, knife, plate, soup plate, chair,
Row-2, seat-5: chair, fork, spoon, knife, plate, soup plate, 

Row-1, seat-6: chair, fork, , knife, dessert spoon, plate, soup plate,
Row-2, seat-6: chair, fork, spoon, knife, dessert spoon, plate, soup plate, dessert plate,

**********************************************************

*/