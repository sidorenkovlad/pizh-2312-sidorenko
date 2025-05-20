#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ������� ����� Kontakt
class Kontakt {
protected:
    string name;
    string phone;
    string address;
public:
    Kontakt() {
        cout << "������ ����������� Kontakt (�� ���������)\n";
    }
    Kontakt(const string& n, const string& p, const string& a)
        : name(n), phone(p), address(a) {
        cout << "������ ����������� Kontakt (� �����������)\n";
    }
    Kontakt(const Kontakt& other)
        : name(other.name), phone(other.phone), address(other.address) {
        cout << "������ ����������� ����������� Kontakt\n";
    }
    virtual ~Kontakt() {
        cout << "���������� Kontakt\n";
    }

    virtual void input() {
        cout << "������� ���: ";
        getline(cin, name);
        cout << "������� �������: ";
        getline(cin, phone);
        cout << "������� �����: ";
        getline(cin, address);
    }

    virtual void display() const {
        cout << "���: " << name << "\n"
             << "�������: " << phone << "\n"
             << "�����: " << address << "\n";
    }
};

// �����-��������� EmailKontakt
class EmailKontakt : public Kontakt {
private:
    string email;
public:
    EmailKontakt() : Kontakt() {
        cout << "������ ����������� EmailKontakt (�� ���������)\n";
    }
    EmailKontakt(const string& n, const string& p, const string& a, const string& e)
        : Kontakt(n,p,a), email(e) {
        cout << "������ ����������� EmailKontakt (� �����������)\n";
    }
    EmailKontakt(const EmailKontakt& other)
        : Kontakt(other), email(other.email) {
        cout << "������ ����������� ����������� EmailKontakt\n";
    }
    ~EmailKontakt() override {
        cout << "���������� EmailKontakt\n";
    }

    void input() override {
        Kontakt::input();
        cout << "������� email: ";
        getline(cin, email);
    }

    void display() const override {
        Kontakt::display();
        cout << "Email: " << email << "\n";
    }
};

// �����-��������� BusinessKontakt
class BusinessKontakt : public Kontakt {
private:
    string companyName;
public:
    BusinessKontakt() : Kontakt() {
        cout << "������ ����������� BusinessKontakt (�� ���������)\n";
    }
    BusinessKontakt(const string& n, const string& p, const string& a, const string& company)
        : Kontakt(n,p,a), companyName(company) {
        cout << "������ ����������� BusinessKontakt (� �����������)\n";
    }
    BusinessKontakt(const BusinessKontakt& other)
        : Kontakt(other), companyName(other.companyName) {
        cout << "������ ����������� ����������� BusinessKontakt\n";
    }
    ~BusinessKontakt() override {
        cout << "���������� BusinessKontakt\n";
    }

    void input() override {
        Kontakt::input();
        cout << "������� �������� ��������: ";
        getline(cin, companyName);
    }

    void display() const override {
        Kontakt::display();
        cout << "��������: " << companyName << "\n";
    }
};