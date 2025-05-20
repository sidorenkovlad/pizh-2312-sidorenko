#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Базовый абстрактный класс Person
class Person {
private:
    static int countObjects; // счетчик всех созданных объектов
public:
    Person() {
        countObjects++;
    }
    virtual ~Person() {
        countObjects--;
    }

    // Статический метод для получения количества созданных объектов
    static int getCountObjects() {
        return countObjects;
    }

    virtual void print() const = 0; // чисто виртуальный метод
};

// Инициализация статической переменной
int Person::countObjects = 0;

// Класс Kontakt (из лабораторной №3)
class Kontakt : public Person {
private:
    string name;
    string phone;
public:
    Kontakt(const string& n = "", const string& p = "") : name(n), phone(p) {}
    void print() const override {
        cout << "Kontakt: " << name << ", Phone: " << phone << endl;
    }
};

// Другие классы-наследники (пример)
class Employee : public Person {
private:
    string name;
    double salary;
public:
    Employee(const string& n = "", double s = 0.0) : name(n), salary(s) {}
    void print() const override {
        cout << "Employee: " << name << ", Salary: " << salary << endl;
    }
};

class Customer : public Person {
private:
    string name;
    int orderNumber;
public:
    Customer(const string& n = "", int oN = 0) : name(n), orderNumber(oN) {}
    void print() const override {
        cout << "Customer: " << name << ", Order Number: " << orderNumber << endl;
    }
};

// Основной класс с внутренним массивом
class MainClass {
private:
    static int countInArray; // счетчик объектов в массиве
    vector<Person*> persons; // внутренний массив указателей на объекты Person

public:
    MainClass() {}
    
    ~MainClass() {
        // Освобождение памяти
        for (auto p : persons) {
            delete p;
        }
        persons.clear();
        countInArray = 0; // при уничтожении объекта сбрасываем счетчик массива
    }

    // Метод для добавления объекта в массив
    void addPerson(Person* p) {
        persons.push_back(p);
        countInArray++;
    }

    // Статический метод для получения количества объектов в массиве
    static int getCountInArray() {
        return countInArray;
    }

    // Вывод информации о всех объектах массива
    void displayAll() const {
        for (auto p : persons) {
            p->print();
        }
    }
};

// Инициализация статической переменной
int MainClass::countInArray = 0;

int main() {
    // Вывод количества созданных объектов до создания любых объектов
    cout << "Количество созданных объектов до создания: " << Person::getCountObjects() << endl;

    MainClass mainObj;

    // Создаем объекты-наследники и добавляем их во внутренний массив
    mainObj.addPerson(new Kontakt("Ivan Ivanov", "+7-123-456"));
    mainObj.addPerson(new Employee("Petrov Petr", 50000));
    mainObj.addPerson(new Customer("Sidorov Sidor", 12345));

    // Выводим текущие значения счетчиков
    cout << "Общее количество созданных объектов: " << Person::getCountObjects() << endl;
    
   cout << "Количество объектов во внутреннем массиве: " << MainClass::getCountInArray() << endl;

   // Вывод информации о всех объектах внутри массива
   mainObj.displayAll();

   return 0;
}