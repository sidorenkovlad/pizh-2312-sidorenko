#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ����� �������
class Kontakt {
private:
    string name;
    string phone;
    string address;

public:
    Kontakt(const string& n, const string& p, const string& a)
        : name(n), phone(p), address(a) {}

    void display() const {
        cout << "���: " << name << endl;
        cout << "�������: " << phone << endl;
        cout << "�����: " << address << endl;
        cout << "------------------------" << endl;
    }

    // ������� (�� �������������)
    string getName() const { return name; }
};

// ����� ����������
class Spravochnik {
private:
    string title;
    string ownerName;
    vector<Kontakt> contacts;

public:
    Spravochnik(const string& t, const string& owner)
        : title(t), ownerName(owner) {}

    void addContact(const Kontakt& contact) {
        contacts.push_back(contact);
    }

    void display() const {
        cout << "�������� �����������: " << title << endl;
        cout << "��������: " << ownerName << endl;
        cout << "��������:" << endl;
        for (const auto& contact : contacts) {
            contact.display();
        }
    }
};

int main() {
    // ������� ����������
    Spravochnik myDirectory("��� ���������� ����������", "���� ������");

    // ��������� ��������
    myDirectory.addContact(Kontakt("���� ������", "+7 912 345 67 89", "�. ������, ��. ������, �.1"));
    myDirectory.addContact(Kontakt("����� ��������", "+7 923 456 78 90", "�. �����-���������, ������� ��., �.10"));

    // ���������� ����������
    myDirectory.display();

    return 0;
}