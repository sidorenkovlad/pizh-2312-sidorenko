class Kontakt : public Person {
private:
    std::string name;
    std::string phone;
    std::string address;
public:
    Kontakt() : name(""), phone(""), address("") {
        std::cout << "Конструктор Kontakt по умолчанию\n";
    }
    Kontakt(const std::string& n, const std::string& p, const std::string& a)
        : name(n), phone(p), address(a) {
        std::cout << "Конструктор Kontakt с параметрами\n";
    }
    Kontakt(const Kontakt& other)
        : name(other.name), phone(other.phone), address(other.address) {
        std::cout << "Конструктор копии Kontakt\n";
    }
    ~Kontakt() {
        std::cout << "Деструктор Kontakt\n";
    }

    void input() {
        std::cout << "Введите имя: ";
        std::getline(std::cin, name);
        std::cout << "Введите телефон: ";
        std::getline(std::cin, phone);
        std::cout << "Введите адрес: ";
        std::getline(std::cin, address);
    }

    void display() const {
        std::cout << "Имя: " << name << "\nТелефон: " << phone
                  << "\nАдрес: " << address << "\n";
    }

    void print() const override {
        display();
    }
};