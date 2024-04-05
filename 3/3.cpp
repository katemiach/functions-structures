#include <iostream>
#include <cstring>
#include <vector>

// Структура для представлення особи
struct Person {
    char* name;
    int age;
};

// Функція для створення структури Person
Person makePerson() {
    int Age;
    char Name[20];
    std::cout << "Name: ";
    std::cin >> Name;
    std::cout << "Age: ";
    std::cin >> Age;

    Person p;
    p.name = new char[strlen(Name) + 1];
    strcpy_s(p.name, strlen(Name) + 1, Name);
    p.age = Age;
    return p;
}

// Функція для виведення структури Person
void printPerson(const Person& p) {
    std::cout << "\tName: " << p.name << "\tAge: " << p.age << std::endl;
}

// Функція для виділення пам'яті та заповнення динамічного масиву структур Person
std::vector<Person> fillArray(int n) {
    std::vector<Person> persons;
    for (int i = 0; i < n; ++i) {
        persons.push_back(makePerson());
    }
    return persons;
}

// Функція для виведення динамічного масиву структур Person
void printArray(const std::vector<Person>& persons) {
    std::cout << "\nOutputting an array of persons: \n";
    for (const auto& person : persons) {
        printPerson(person);
    }
}

// Функція для пошуку та формування нового масиву осіб за заданою умовою (вік більше 25)
std::vector<Person> findPersonsAbove25(const std::vector<Person>& persons) {
    std::vector<Person> result;
    for (const auto& person : persons) {
        if (person.age > 25) {
            result.push_back(person);
        }
    }
    return result;
}

// Функція для видалення першого рядка з динамічного масиву рядків
void deleteFirstRow(std::vector<std::string>& rows) {
    if (!rows.empty()) {
        rows.erase(rows.begin());
    }
    else {
        std::cout << "Error: array is empty!" << std::endl;
    }
}

// Функція для виведення динамічного масиву рядків
void printStringArray(const std::vector<std::string>& strings) {
    std::cout << "\nPrint an array of strings:\n";
    for (const auto& str : strings) {
        std::cout << str << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of people: ";
    std::cin >> n;

    // Заповнення та виведення масиву осіб
    std::vector<Person> persons = fillArray(n);
    printArray(persons);

    // Пошук осіб за умовою (вік більше 25)
    std::vector<Person> personsAbove25 = findPersonsAbove25(persons);
    if (personsAbove25.empty()) {
        std::cout << "\nNo persons over the age of 25 were found." << std::endl;
    }
    else {
        std::cout << "\nPersons over the age of 25:\n";
        printArray(personsAbove25);
    }

    // Формування та виведення масиву рядків
    std::vector<std::string> strings = { "One", "Two", "Three", "Four" };
    printStringArray(strings);

    // Видалення першого рядка з масиву рядків
    deleteFirstRow(strings);
    std::cout << "\nAn array of strings after deleting the first string:\n";
    printStringArray(strings);

    return 0;
}