#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Класс Контакт
class Kontakt {
private:
    string name;
    string phone;
    string address;

public:
    Kontakt(const string& n, const string& p, const string& a)
        : name(n), phone(p), address(a) {}

    void display() const {
        cout << "Имя: " << name << endl;
        cout << "Телефон: " << phone << endl;
        cout << "Адрес: " << address << endl;
        cout << "------------------------" << endl;
    }

    // Геттеры (по необходимости)
    string getName() const { return name; }
};

// Класс Справочник
class Spravochnik {
private:
    string title;
    string ownerName;
    vector<Kontakt> contacts;

public:
    Spravochnik(const string& t, const string& owner)
        : title(t), ownerName(owner) {}

    void addContact(const Kontakt& contact) {
        contacts.push_back(contact);
    }

    void display() const {
        cout << "Название справочника: " << title << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Контакты:" << endl;
        for (const auto& contact : contacts) {
            contact.display();
        }
    }
};

int main() {
    // Создаем справочник
    Spravochnik myDirectory("Мой телефонный справочник", "Иван Иванов");

    // Добавляем контакты
    myDirectory.addContact(Kontakt("Петр Петров", "+7 912 345 67 89", "г. Москва, ул. Ленина, д.1"));
    myDirectory.addContact(Kontakt("Мария Смирнова", "+7 923 456 78 90", "г. Санкт-Петербург, Невский пр., д.10"));

    // Отображаем справочник
    myDirectory.display();

    return 0;
}