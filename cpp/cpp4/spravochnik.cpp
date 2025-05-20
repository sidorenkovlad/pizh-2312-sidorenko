class Spravochnik {
private:
    std::string title;
    std::vector<Person*> contacts; // ��������� �� ������� �����
public:
    Spravochnik(const std::string& t = "") : title(t) {}
    
    ~Spravochnik() {
        for (auto p : contacts) {
            delete p; // ������������ ������
        }
        contacts.clear();
        std::cout << "���������� Spravochnik\n";
    }

    void addContact(Person* p) {
        contacts.push_back(p);
    }

    void displayAll() const {
        std::cout << "����������: " << title << "\n";
        for (const auto& p : contacts) {
            p->print(); // ����� ����������� �������
            std::cout << "-------------------\n";
        }
    }
};