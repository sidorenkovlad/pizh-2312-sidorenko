class Employee : public Person {
private:
    std::string name;
    int salary;
public:
    Employee(const std::string& n = "", int s = 0) : name(n), salary(s) {}
    
    void print() const override {
        std::cout << "Сотрудник: " << name << ", Зарплата: " << salary << "\n";
    }
};

class Customer : public Person {
private:
    std::string name;
    int orderNumber;
public:
    Customer(const std::string& n = "", int oN = 0) : name(n), orderNumber(oN) {}
    
    void print() const override {
        std::cout << "Клиент: " << name << ", Номер заказа: " << orderNumber << "\n";
    }
};