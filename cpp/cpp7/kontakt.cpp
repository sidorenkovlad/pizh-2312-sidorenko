class Kontakt : public Person {
private:
    std::string name;
public:
    Kontakt(const std::string& n = "") : name(n) {}
    
    void print() const override {
        std::cout << "Kontakt: " << name << std::endl;
    }

    bool operator<(const Person& other) const override {
        const Kontakt* pOther = dynamic_cast<const Kontakt*>(&other);
        if (pOther)
            return name < pOther->name;
        else
            return false; // или бросить исключение
    }

    bool operator>(const Person& other) const override {
        const Kontakt* pOther = dynamic_cast<const Kontakt*>(&other);
        if (pOther)
            return name > pOther->name;
        else
            return false;
    }
};