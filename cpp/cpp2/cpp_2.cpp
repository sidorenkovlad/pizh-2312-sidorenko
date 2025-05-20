#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Класс Контакт
class Kontakt {
private:
    string name;
    string phone;
    string address;

public:
    // Конструктор без параметров
    Kontakt() {
        cout << "Вызван конструктор Kontakt() (без параметров)" << endl;
        name = "";
        phone = "";
        address = "";
    }

    // Конструктор с параметрами
    Kontakt(const string& n, const string& p, const string& a)
        : name(n), phone(p), address(a) {
        cout << "Вызван конструктор Kontakt(с параметрами)" << endl;
    }

    // Конструктор копирования
    Kontakt(const Kontakt& other)
        : name(other.name), phone(other.phone), address(other.address) {
        cout << "Вызван конструктор копирования Kontakt" << endl;
    }

    // Деструктор
    ~Kontakt() {
        cout << "Деструктор Kontakt для " << name << endl;
    }

    void display() const {
        cout << "Имя: " << name << endl;
        cout << "Телефон: " << phone << endl;
        cout << "Адрес: " << address << endl;
        cout << "------------------------" << endl;
    }

    // Геттеры (по необходимости)
    string getName() const { return name; }
};

// Класс Справочник
class Spravochnik {
private:
    string title;
    string ownerName;
    vector<Kontakt> contacts;

public:
    // Конструктор без параметров
    Spravochnik() {
        cout << "Вызван конструктор Spravochnik() (без параметров)" << endl;
        title = "";
        ownerName = "";
    }

    // Конструктор с параметрами
    Spravochnik(const string& t, const string& owner)
        : title(t), ownerName(owner) {
        cout << "Вызван конструктор Spravochnik(с параметрами)" << endl;
    }

    // Конструктор копирования
    Spravochnik(const Spravochnik& other)
        : title(other.title), ownerName(other.ownerName), contacts(other.contacts) {
        cout << "Вызван конструктор копирования Spravochnik" << endl;
    }

    // Деструктор
    ~Spravochnik() {
        cout << "Деструктор Spravochnik" << endl;
    }

    void addContact(const Kontakt& contact) {
        contacts.push_back(contact);
    }

    void display() const {
        cout << "\n--- Справочник ---" << endl;
        cout << "Название: " << title << endl;
        cout << "Владелец: " << ownerName << endl;
        for (const auto& contact : contacts) {
            contact.display();
        }
        cout << "--- Конец справочника ---\n" << endl;
    }
};

// Основной класс или функции для демонстрации
class Demo {
public:
    
    // Метод для создания объекта с помощью конструктора с параметрами и добавления в массив
	static void createWithParams(vector<Kontakt>& arr, const string& n, const string& p, const string& a) {
		cout << "\nСоздание контакта с помощью конструктора с параметрами..."<<endl;
		Kontakt k(n,p,a);
		arr.push_back(k);
	}

	// Метод для создания нескольких копий объекта через ссылку и количество
	static void createCopies(const Kontakt& original, vector<Kontakt>& arr, int count) {
		cout<< "\nСоздание "<<count<<" копий контакта через конструктор копирования..."<<endl;
		for(int i=0; i<count; ++i){
			Kontakt copy(original);
			arr.push_back(copy);
		}
	}
};

int main() {

	cout<<"=== Демонстрация использования всех конструкторов ==="<<endl;

	vector<Kontakt> contacts;

	// 1. Создаем объект без параметров
	cout<<"\nСоздаем контакт без параметров:"<<endl;
	Kontakt c1;

	// 2. Создаем объект с параметрами
	cout<<"\nСоздаем контакт с параметрами:"<<endl;
	Kонтакт c2("Иван Иванов", "+7 912 345 67 89", "г. Москва");
	
	// 3. Создаем копию существующего объекта
	cout<<"\nСоздаем копию контакта c2:"<<endl;
	Kontakt c3(c2);

	// Добавляем контакты в список
	contacts.push_back(c1);
	contacts.push_back(c2);
	contacts.push_back(c3);

	// Создаем справочник и добавляем контакты
	Spravochnik directory("Мой телефонный справочник", "Алексей");
	for (const auto& cont : contacts) {
	    directory.addContact(cont);
	}

	directory.display();

	// Демонстрация методов из класса Demo

	cout<<"\n=== Использование методов класса Demo ==="<<endl;

	vector<Kontakt> additionalContacts;

	// Создать контакт с помощью метода createWithParams и добавить в массив
	Demo::createWithParams(additionalContacts, "Петр Петров", "+7 923 456 78 90", "г. Санкт-Петербург");

	// Создать несколько копий существующего объекта через ссылку и количество
	if (!additionalContacts.empty()) {
	    Kontakt originalContact = additionalContacts[0];
	    Demo::createCopies(originalContact, additionalContacts, 3);
	}

	cout<<"\nДобавляем дополнительные контакты в справочник..."<<endl;

	for (const auto& cont : additionalContacts) {
	    directory.addContact(cont);
	}

	directory.display();

	return 0;	
}