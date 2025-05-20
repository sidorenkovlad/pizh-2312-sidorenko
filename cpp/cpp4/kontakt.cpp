class Kontakt : public Person {
private:
    std::string name;
    std::string phone;
    std::string address;
public:
    Kontakt() : name(""), phone(""), address("") {
        std::cout << "����������� Kontakt �� ���������\n";
    }
    Kontakt(const std::string& n, const std::string& p, const std::string& a)
        : name(n), phone(p), address(a) {
        std::cout << "����������� Kontakt � �����������\n";
    }
    Kontakt(const Kontakt& other)
        : name(other.name), phone(other.phone), address(other.address) {
        std::cout << "����������� ����� Kontakt\n";
    }
    ~Kontakt() {
        std::cout << "���������� Kontakt\n";
    }

    void input() {
        std::cout << "������� ���: ";
        std::getline(std::cin, name);
        std::cout << "������� �������: ";
        std::getline(std::cin, phone);
        std::cout << "������� �����: ";
        std::getline(std::cin, address);
    }

    void display() const {
        std::cout << "���: " << name << "\n�������: " << phone
                  << "\n�����: " << address << "\n";
    }

    void print() const override {
        display();
    }
};