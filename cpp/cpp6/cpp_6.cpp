#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ������� ����� Person
class Person {
protected:
    static int countObjects; // ������� ���� ��������� ��������
public:
    Person() { ++countObjects; }
    virtual ~Person() { --countObjects; }
    static int getCountObjects() { return countObjects; }
    virtual void print() const = 0;
};

int Person::countObjects = 0;

// ����� Kontakt
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

// ����� Employee
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

// ����� Customer
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

// �������� ����� � ���������� �������� � �����������
class MainClass {
private:
    vector<Person*> persons; // ���������� ������ ���������� �� ������� Person
public:
    static int countInArray; // ������� �������� � �������

    // ����������� � ����������
    MainClass() {}
    
    ~MainClass() {
        for (auto p : persons)
            delete p;
        persons.clear();
        countInArray = 0;
    }

    // �������� + ��� ���������� ������� � ������ (�� ���������)
    MainClass& operator+(Person* p) {
        persons.push_back(p);
        ++countInArray;
        return *this;
    }

    // ���������� ++ (��������� ������ �� ���������)
    MainClass& operator++() {
        // ����� ������� ��� �� ���������, �������� Kontakt
        persons.push_back(new Kontakt());
        ++countInArray;
        return *this;
    }

    // ����������� ++ (����� ��������� ������ �� ���������)
    MainClass operator++(int) {
        MainClass temp = *this; // ����� �������� ���������
        ++(*this); // �������� ����������++
        return temp; // ���������� ������ ���������
    }

    // �������� [] ��� ������� �� �������
    Person* operator[](size_t index) const {
        if (index >= persons.size()) {
            throw out_of_range("������ ��� ���������");
        }
        return persons[index];
    }

    // ����� ��� ����������� ���� ��������� �������
    void displayAll() const {
        for (size_t i = 0; i < persons.size(); ++i) {
            cout << "[" << i << "] ";
            persons[i]->print();
        }
    }

    static int getCountInArray() { return countInArray; }
};

int MainClass::countInArray = 0;

// ���������� �������� ������ <<
ostream& operator<<(ostream& os, const MainClass& mc) {
    os << "���������� �������:\n";
    for (size_t i = 0; i < mc.persons.size(); ++i) {
        os << "[" << i << "] ";
        mc.persons[i]->print();
    }
    return os;
}

// ������������ ���������� ���� ���������� � main()
int main() {
    MainClass mc;

   // ���������� �������� + ��� ���������� �������� ������ �����
   mc + new Kontakt("Alice", "123456789") 
      + new Employee("Bob", 50000)
      + new Customer("Charlie", 101);

   cout << "����� ���������� ���� ��������:\n";
   mc.displayAll();

   cout << "\n����� ����� ��������� ��������: " << Person::getCountObjects() << endl;
   cout << "����� ����� �������� � �������: " << MainClass::getCountInArray() << endl;

   // ���������� ���������� ++ ��� ���������� ������� �� ��������� (Kontakt)
   ++mc;

   cout << "\n����� ����������� ++:\n";
   mc.displayAll();

   // ���������� ����������� ++ ��� ���������� ������� �� ��������� (Kontakt)
   mc++;
   
   cout << "\n����� ������������ ++:\n";
   mc.displayAll();

   // ���������� �������� [] ��� ������� � �������� � ������ print()
   try {
       Person* p = mc[2];
       cout << "\n������ � �������� � �������� 2:\n";
       p->print();
   } catch (const out_of_range& e) {
       cout << e.what() << endl;
   }

   // ���������� �������� ������ <<
   cout << "\n����� ����� ����������� ����� ��������<<:\n" 
        << mc;

   return 0;
}