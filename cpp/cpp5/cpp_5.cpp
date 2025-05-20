#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ������� ����������� ����� Person
class Person {
private:
    static int countObjects; // ������� ���� ��������� ��������
public:
    Person() {
        countObjects++;
    }
    virtual ~Person() {
        countObjects--;
    }

    // ����������� ����� ��� ��������� ���������� ��������� ��������
    static int getCountObjects() {
        return countObjects;
    }

    virtual void print() const = 0; // ����� ����������� �����
};

// ������������� ����������� ����������
int Person::countObjects = 0;

// ����� Kontakt (�� ������������ �3)
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

// ������ ������-���������� (������)
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

// �������� ����� � ���������� ��������
class MainClass {
private:
    static int countInArray; // ������� �������� � �������
    vector<Person*> persons; // ���������� ������ ���������� �� ������� Person

public:
    MainClass() {}
    
    ~MainClass() {
        // ������������ ������
        for (auto p : persons) {
            delete p;
        }
        persons.clear();
        countInArray = 0; // ��� ����������� ������� ���������� ������� �������
    }

    // ����� ��� ���������� ������� � ������
    void addPerson(Person* p) {
        persons.push_back(p);
        countInArray++;
    }

    // ����������� ����� ��� ��������� ���������� �������� � �������
    static int getCountInArray() {
        return countInArray;
    }

    // ����� ���������� � ���� �������� �������
    void displayAll() const {
        for (auto p : persons) {
            p->print();
        }
    }
};

// ������������� ����������� ����������
int MainClass::countInArray = 0;

int main() {
    // ����� ���������� ��������� �������� �� �������� ����� ��������
    cout << "���������� ��������� �������� �� ��������: " << Person::getCountObjects() << endl;

    MainClass mainObj;

    // ������� �������-���������� � ��������� �� �� ���������� ������
    mainObj.addPerson(new Kontakt("Ivan Ivanov", "+7-123-456"));
    mainObj.addPerson(new Employee("Petrov Petr", 50000));
    mainObj.addPerson(new Customer("Sidorov Sidor", 12345));

    // ������� ������� �������� ���������
    cout << "����� ���������� ��������� ��������: " << Person::getCountObjects() << endl;
    
   cout << "���������� �������� �� ���������� �������: " << MainClass::getCountInArray() << endl;

   // ����� ���������� � ���� �������� ������ �������
   mainObj.displayAll();

   return 0;
}