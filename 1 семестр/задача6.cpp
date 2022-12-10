#include <iostream>
#include <vector>

class zoo {
private:
    std::string name;
public:
    zoo(std::string Name) {
        name = Name;
    }
};

int main()
{
    std::vector<std::string> animals;

    //Первый пункт
    animals.push_back("cat"); //добавляет элемент в конец
    animals.push_back("dog");
    animals.push_back("zebra");
    animals.push_back("bear");
    animals.push_back("parrot");
    animals.push_back("peacock");
    animals.push_back("fox");
    animals.push_back("hamster");
    for (std::string n: animals)
        std::cout << n << ' ';
    std::cout << std::endl;

    animals.erase(animals.begin()); //удаляет первый элемент
    animals.erase(animals.begin() +3); //удаляет третий элемент
    animals.erase(animals.begin() + 3, animals.begin() + 4); //удаляет с 3-го по 5-й элемент
    animals.erase(animals.end()-1); //удаляет последний элемент

    for (std::string n: animals)
        std::cout << n << ' ';
    std::cout << std::endl;

    animals.insert(animals.begin() + 2, "seal"); //добавляет элемент на второе место
    animals.insert(animals.begin() + 3, 3, "penguin"); //добавляет 3 элемента, начиная с 3-его места

    for (std::string n: animals)
        std::cout << n << ' ';
    std::cout << std::endl;

    //Второй пункт
    zoo Z("rabbit");
    std::vector<zoo> newanimals;
    newanimals.emplace_back(Z); //добавляет "сложные"(напр. класс) элементы в массив

    //Третий пункт
    animals.resize(12); //меняет длину массива
    animals.reserve(20); //выделяет объём памяти для массива
    std::cout << animals.size() << ' ' << animals.capacity() << std::endl;
    animals.shrink_to_fit(); //сокращает объём до размера массива
    std::cout << animals.size() << ' ' << animals.capacity() << std::endl; //capacity возвращает объём массива

    //Четвертый пункт
    animals.clear(); //удаляет все элементы массива

    //Пятый пункт
    animals.resize(5);
    animals[0] = "dog"; //присваивает элементу с индексом 0 значение "dog"
    animals[3] = "cat";

    std::vector<std::string> animals3 = {"пусто"};
    animals3 = animals; //приравнивает один массив к другому

    for (std::string n: animals)
        std::cout << n << ", ";
    std::cout << std::endl;

    for (std::string n: animals3)
        std::cout << n << ", ";
    std::cout << std::endl;

    return 0;
}