#include <iostream>
#include <vector>
#include <algorithm> // ��� std::remove_if
#include "Person.h" // ��� ����� Person

int main() {
    // ������� ���������
    std::vector<Person> people;

    // ��������� ��������� �������
    people.emplace_back("Ivan Ivanov", 30);
    people.emplace_back("Maria Petrova", 25);
    people.emplace_back("Alexey Smirnov", 40);
    people.emplace_back("Olga Kuznetsova", 35);

    // �������� ����������� ����������
    std::cout << "�������� ���������:\n";
    for (const auto& person : people) {
        std::cout << person << std::endl;
    }