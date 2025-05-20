#include <iostream>
#include <vector>
#include <algorithm> // для std::remove_if
#include "Person.h" // ваш класс Person

int main() {
    // Создаем контейнер
    std::vector<Person> people;

    // Заполняем контейнер данными
    people.emplace_back("Ivan Ivanov", 30);
    people.emplace_back("Maria Petrova", 25);
    people.emplace_back("Alexey Smirnov", 40);
    people.emplace_back("Olga Kuznetsova", 35);

    // Просмотр содержимого контейнера
    std::cout << "Исходный контейнер:\n";
    for (const auto& person : people) {
        std::cout << person << std::endl;
    }