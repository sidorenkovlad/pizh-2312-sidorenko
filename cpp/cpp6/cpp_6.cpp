#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Базовый класс Person
class Person {
protected:
    static int countObjects; // счетчик всех созданных объектов
public:
    Person() { ++countObjects; }
    virtual ~Person() { --countObjects; }
    static int getCountObjects() { return countObjects; }
    virtual void print() const = 0;
};

int Person::countObjects = 0;

// Класс Kontakt
class Kontakt : public Person {
private:
    string name;
    string phone;
public:
    Kontakt(const string& n, const string& p) : name(n), phone(p) {}
    Kontakt() : name("Default Name"), phone("0000000000") {}
    void print() const override {
        cout << "Kontakt: " << name << ", Phone: " << phone << endl;
    }
};

// Класс Employee
class Employee : public Person {
private:
    string name;
    double salary;
public:
    Employee(const string& n, double s) : name(n), salary(s) {}
    Employee() : name("Default Employee"), salary(0.0) {}
    void print() const override {
        cout << "Employee: " << name << ", Salary: " << salary << endl;
    }
};

// Класс Customer
class Customer : public Person {
private:
    string name;
    int orderNumber;
public:
    Customer(const string& n, int o) : name(n), orderNumber(o) {}
    Customer() : name("Default Customer"), orderNumber(0) {}
    void print() const override {
        cout << "Customer: " << name << ", Order Number: " << orderNumber << endl;
    }
};

// Основной класс с внутренним массивом и операторами
class MainClass {
private:
    vector<Person*> persons; // внутренний массив указателей на объекты Person
public:
    static int countInArray; // счетчик объектов в массиве

    // Конструктор и деструктор
    MainClass() {}
    
    ~MainClass() {
        for (auto p : persons)
            delete p;
        persons.clear();
        countInArray = 0;
    }

    // Оператор + для добавления объекта в массив (по указателю)
    MainClass& operator+(Person* p) {
        persons.push_back(p);
        ++countInArray;
        return *this;
    }

    // Префиксный ++ (добавляет объект по умолчанию)
    MainClass& operator++() {
        // Можно выбрать тип по умолчанию, например Kontakt
        persons.push_back(new Kontakt());
        ++countInArray;
        return *this;
    }

    // Постфиксный ++ (также добавляет объект по умолчанию)
    MainClass operator++(int) {
        MainClass temp = *this; // копия текущего состояния
        ++(*this); // вызываем префиксный++
        return temp; // возвращаем старое состояние
    }

    // Оператор [] для доступа по индексу
    Person* operator[](size_t index) const {
        if (index >= persons.size()) {
            throw out_of_range("Индекс вне диапазона");
        }
        return persons[index];
    }

    // Метод для отображения всех элементов массива
    void displayAll() const {
        for (size_t i = 0; i < persons.size(); ++i) {
            cout << "[" << i << "] ";
            persons[i]->print();
        }
    }

    static int getCountInArray() { return countInArray; }
};

int MainClass::countInArray = 0;

// Глобальный оператор вывода <<
ostream& operator<<(ostream& os, const MainClass& mc) {
    os << "Содержимое массива:\n";
    for (size_t i = 0; i < mc.persons.size(); ++i) {
        os << "[" << i << "] ";
        mc.persons[i]->print();
    }
    return os;
}

// Демонстрация применения всех операторов в main()
int main() {
    MainClass mc;

   // Используем оператор + для добавления объектов разных типов
   mc + new Kontakt("Alice", "123456789") 
      + new Employee("Bob", 50000)
      + new Customer("Charlie", 101);

   cout << "После добавления трех объектов:\n";
   mc.displayAll();

   cout << "\nОбщее число созданных объектов: " << Person::getCountObjects() << endl;
   cout << "Общее число объектов в массиве: " << MainClass::getCountInArray() << endl;

   // Используем префиксный ++ для добавления объекта по умолчанию (Kontakt)
   ++mc;

   cout << "\nПосле префиксного ++:\n";
   mc.displayAll();

   // Используем постфиксный ++ для добавления объекта по умолчанию (Kontakt)
   mc++;
   
   cout << "\nПосле постфиксного ++:\n";
   mc.displayAll();

   // Используем оператор [] для доступа к элементу и вызова print()
   try {
       Person* p = mc[2];
       cout << "\nДоступ к элементу с индексом 2:\n";
       p->print();
   } catch (const out_of_range& e) {
       cout << e.what() << endl;
   }

   // Используем оператор вывода <<
   cout << "\nВывод всего содержимого через оператор<<:\n" 
        << mc;

   return 0;
}