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
    // ����������� ��� ����������
    Kontakt() {
        cout << "������ ����������� Kontakt() (��� ����������)" << endl;
        name = "";
        phone = "";
        address = "";
    }

    // ����������� � �����������
    Kontakt(const string& n, const string& p, const string& a)
        : name(n), phone(p), address(a) {
        cout << "������ ����������� Kontakt(� �����������)" << endl;
    }

    // ����������� �����������
    Kontakt(const Kontakt& other)
        : name(other.name), phone(other.phone), address(other.address) {
        cout << "������ ����������� ����������� Kontakt" << endl;
    }

    // ����������
    ~Kontakt() {
        cout << "���������� Kontakt ��� " << name << endl;
    }

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
    // ����������� ��� ����������
    Spravochnik() {
        cout << "������ ����������� Spravochnik() (��� ����������)" << endl;
        title = "";
        ownerName = "";
    }

    // ����������� � �����������
    Spravochnik(const string& t, const string& owner)
        : title(t), ownerName(owner) {
        cout << "������ ����������� Spravochnik(� �����������)" << endl;
    }

    // ����������� �����������
    Spravochnik(const Spravochnik& other)
        : title(other.title), ownerName(other.ownerName), contacts(other.contacts) {
        cout << "������ ����������� ����������� Spravochnik" << endl;
    }

    // ����������
    ~Spravochnik() {
        cout << "���������� Spravochnik" << endl;
    }

    void addContact(const Kontakt& contact) {
        contacts.push_back(contact);
    }

    void display() const {
        cout << "\n--- ���������� ---" << endl;
        cout << "��������: " << title << endl;
        cout << "��������: " << ownerName << endl;
        for (const auto& contact : contacts) {
            contact.display();
        }
        cout << "--- ����� ����������� ---\n" << endl;
    }
};

// �������� ����� ��� ������� ��� ������������
class Demo {
public:
    
    // ����� ��� �������� ������� � ������� ������������ � ����������� � ���������� � ������
	static void createWithParams(vector<Kontakt>& arr, const string& n, const string& p, const string& a) {
		cout << "\n�������� �������� � ������� ������������ � �����������..."<<endl;
		Kontakt k(n,p,a);
		arr.push_back(k);
	}

	// ����� ��� �������� ���������� ����� ������� ����� ������ � ����������
	static void createCopies(const Kontakt& original, vector<Kontakt>& arr, int count) {
		cout<< "\n�������� "<<count<<" ����� �������� ����� ����������� �����������..."<<endl;
		for(int i=0; i<count; ++i){
			Kontakt copy(original);
			arr.push_back(copy);
		}
	}
};

int main() {

	cout<<"=== ������������ ������������� ���� ������������� ==="<<endl;

	vector<Kontakt> contacts;

	// 1. ������� ������ ��� ����������
	cout<<"\n������� ������� ��� ����������:"<<endl;
	Kontakt c1;

	// 2. ������� ������ � �����������
	cout<<"\n������� ������� � �����������:"<<endl;
	K������ c2("���� ������", "+7 912 345 67 89", "�. ������");
	
	// 3. ������� ����� ������������� �������
	cout<<"\n������� ����� �������� c2:"<<endl;
	Kontakt c3(c2);

	// ��������� �������� � ������
	contacts.push_back(c1);
	contacts.push_back(c2);
	contacts.push_back(c3);

	// ������� ���������� � ��������� ��������
	Spravochnik directory("��� ���������� ����������", "�������");
	for (const auto& cont : contacts) {
	    directory.addContact(cont);
	}

	directory.display();

	// ������������ ������� �� ������ Demo

	cout<<"\n=== ������������� ������� ������ Demo ==="<<endl;

	vector<Kontakt> additionalContacts;

	// ������� ������� � ������� ������ createWithParams � �������� � ������
	Demo::createWithParams(additionalContacts, "���� ������", "+7 923 456 78 90", "�. �����-���������");

	// ������� ��������� ����� ������������� ������� ����� ������ � ����������
	if (!additionalContacts.empty()) {
	    Kontakt originalContact = additionalContacts[0];
	    Demo::createCopies(originalContact, additionalContacts, 3);
	}

	cout<<"\n��������� �������������� �������� � ����������..."<<endl;

	for (const auto& cont : additionalContacts) {
	    directory.addContact(cont);
	}

	directory.display();

	return 0;	
}