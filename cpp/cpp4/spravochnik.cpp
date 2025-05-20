class Spravochnik {
private:
    std::string title;
    std::vector<Person*> contacts; // указатели на базовый класс
public:
    Spravochnik(const std::string& t = "") : title(t) {}
    
    ~Spravochnik() {
        for (auto p : contacts) {
            delete p; // освобождение памяти
        }
        contacts.clear();
        std::cout << "Деструктор Spravochnik\n";
    }

    void addContact(Person* p) {
        contacts.push_back(p);
    }

    void displayAll() const {
        std::cout << "Справочник: " << title << "\n";
        for (const auto& p : contacts) {
            p->print(); // вызов виртуальной функции
            std::cout << "-------------------\n";
        }
    }
};