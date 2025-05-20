#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Базовый класс Kontakt
class Kontakt {
protected:
    string name;
    string phone;
    string address;
public:
    Kontakt() {
        cout << "Вызван конструктор Kontakt (по умолчанию)\n";
    }
    Kontakt(const string& n, const string& p, const string& a)
        : name(n), phone(p), address(a) {
        cout << "Вызван конструктор Kontakt (с параметрами)\n";
    }
    Kontakt(const Kontakt& other)
        : name(other.name), phone(other.phone), address(other.address) {
        cout << "Вызван конструктор копирования Kontakt\n";
    }
    virtual ~Kontakt() {
        cout << "Деструктор Kontakt\n";
    }

    virtual void input() {
        cout << "Введите имя: ";
        getline(cin, name);
        cout << "Введите телефон: ";
        getline(cin, phone);
        cout << "Введите адрес: ";
        getline(cin, address);
    }

    virtual void display() const {
        cout << "Имя: " << name << "\n"
             << "Телефон: " << phone << "\n"
             << "Адрес: " << address << "\n";
    }
};

// Класс-наследник EmailKontakt
class EmailKontakt : public Kontakt {
private:
    string email;
public:
    EmailKontakt() : Kontakt() {
        cout << "Вызван конструктор EmailKontakt (по умолчанию)\n";
    }
    EmailKontakt(const string& n, const string& p, const string& a, const string& e)
        : Kontakt(n,p,a), email(e) {
        cout << "Вызван конструктор EmailKontakt (с параметрами)\n";
    }
    EmailKontakt(const EmailKontakt& other)
        : Kontakt(other), email(other.email) {
        cout << "Вызван конструктор копирования EmailKontakt\n";
    }
    ~EmailKontakt() override {
        cout << "Деструктор EmailKontakt\n";
    }

    void input() override {
        Kontakt::input();
        cout << "Введите email: ";
        getline(cin, email);
    }

    void display() const override {
        Kontakt::display();
        cout << "Email: " << email << "\n";
    }
};

// Класс-наследник BusinessKontakt
class BusinessKontakt : public Kontakt {
private:
    string companyName;
public:
    BusinessKontakt() : Kontakt() {
        cout << "Вызван конструктор BusinessKontakt (по умолчанию)\n";
    }
    BusinessKontakt(const string& n, const string& p, const string& a, const string& company)
        : Kontakt(n,p,a), companyName(company) {
        cout << "Вызван конструктор BusinessKontakt (с параметрами)\n";
    }
    BusinessKontakt(const BusinessKontakt& other)
        : Kontakt(other), companyName(other.companyName) {
        cout << "Вызван конструктор копирования BusinessKontakt\n";
    }
    ~BusinessKontakt() override {
        cout << "Деструктор BusinessKontakt\n";
    }

    void input() override {
        Kontakt::input();
        cout << "Введите название компании: ";
        getline(cin, companyName);
    }

    void display() const override {
        Kontakt::display();
        cout << "Компания: " << companyName << "\n";
    }
};