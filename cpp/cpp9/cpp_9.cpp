#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

// ������� �����
class Person {
protected:
    std::string name;
    int age;

public:
    Person() : name(""), age(0) {}
    Person(const std::string& n, int a) : name(n), age(a) {}

    // ���������� ���������
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    friend std::istream& operator>>(std::istream& is, Person& p);

    // ������ ��� ����������/������ �� �����
    void saveToFile(const std::string& filename) const {
        std::ofstream ofs(filename);
        if (!ofs) {
            throw std::runtime_error("�� ������� ������� ���� ��� ������");
        }
        ofs << name << '\n' << age << '\n';
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream ifs(filename);
        if (!ifs) {
            throw std::runtime_error("�� ������� ������� ���� ��� ������");
        }
        getline(ifs, name);
        ifs >> age;
        // ������� ������ ����� ������ �����
        ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};

// ���������� �������� ������
std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "���: " << p.name << ", �������: " << p.age;
    return os;
}

// ���������� �������� �����
std::istream& operator>>(std::istream& is, Person& p) {
    std::cout << "������� ���: ";
    getline(is, p.name);
    std::cout << "������� �������: ";
    is >> p.age;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return is;
}

// ����� ���� ��� ������������ ��� � ������������ � ����������

// ����������� ����� ������, ����������� �� std::logic_error
class MyLogicError : public std::logic_error {
public:
    explicit MyLogicError(const std::string& message)
        : std::logic_error("MyLogicError: " + message) {}
};

// ��� ���� ����������� ����� ������, ����������� �� std::runtime_error
class MyRuntimeError : public std::runtime_error {
public:
    explicit MyRuntimeError(const std::string& message)
        : std::runtime_error("MyRuntimeError: " + message) {}
};

// ������� ��������� ���������� (��������� ��� ���������)
void generateExceptions(int choice) {
    switch (choice) {
        case 1:
            throw 42; // ���������� ���� int
        case 2:
            throw std::string("������ ������");
        case 3:
            throw std::invalid_argument("������������ ��������");
        case 4:
            throw std::length_error("����� ���������");
        case 5:
            throw std::out_of_range("����� �� �������");
        case 6:
            throw MyLogicError("���������� ������");
        case 7:
            throw MyRuntimeError("������ ����������");
        default:
            throw 0.0; // ����������� ����������
    }
}

// ������� ��������� � ��������� ���������� (��������� ��� ���������)
void processWithLocalCatch(int choice) {
    try {
        generateExceptions(choice);
    } catch (const int& e) {
        std::cout << "�������� ������� ���������� ���� int: " << e << "\n";
    } catch (const std::string& e) {
        std::cout << "�������� ������� ���������� ���� string: " << e << "\n";
    } catch (const MyLogicError& e) {
        std::cout << "�������� ������� ����������� ���������� ����������: " << e.what() << "\n";
    } catch (const MyRuntimeError& e) {
        std::cout << "�������� ������� ����������� ��������� ����������: " << e.what() << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "�������� ������� invalid_argument: " << e.what() << "\n";
    } catch (const std::length_error& e) {
        std::cout << "�������� ������� length_error: " << e.what() << "\n";
    } catch (const std::out_of_range& e) {
       	std :: cout<< ��������� ������� out_of_range:�<<e.what()<<�\n�;
	}
	catch (...) { 
		std :: cout<< ��������� ������� ����������� ����������.�<<�\n�;
	}
}

// �������� ������� � ���������� � ������������� ����������/������ �������
int main() {
    
    // ������� ������ Person
    Person person;

    // ���� ������ ������������
    try {
        std :: cin>>person;
        
        // ��������� � ����
        person.saveToFile("person.txt");
        
        // ������� �� �����
        std :: cout<<"������ �������� � ����.\n";

        // ��������� �� ����� � ����� ������ ��� ��������
        Person personFromFile;
        personFromFile.loadFromFile("person.txt");
        
        // ������� ����������� ������
        std :: cout<<"����������� �� ����� ������:\n"<<personFromFile<<"\n";

        
    } catch(const std :: exception &e){
    	std :: cerr<<"������ ��� ������ � ������ ��� �����: "<<e.what()<<"\n";
	}

    
	// ������������ ��������� ���������� ��� ������
	for (int i = 1; i <= 8; ++i) {
		try {
			processWithLocalCatch(i);
		}
		catch (const int& e) {
			std :: cout<<������������� ����������� ���������� ���� int:�<<e<<"\n�;
		}
		catch (const std :: string &e){
			std :: cout<<������������� ����������� ���������� ���� string:�<<e<<"\n�;
		}
		catch (const MyLogicError &e){
			std :: cout<<������������� ����������� ����������� ���������� ����������:�<<e.what()<<�\n�;
		}
		catch (const MyRuntimeError &e){
			std :: cout<<������������� ����������� ����������� ��������� ����������:�<<e.what()<<�\n�;
		}
		catch(const std :: invalid_argument &e){
			std :: cout<<"������������ ����������� invalid_argument:"<<e.what()<<"\n";
		}
		catch(const std :: length_error &e){
			std :: cout<<"������������ ����������� length_error:"<<e.what()<<"\n";
		}
		catch(const std :: out_of_range &e){
			std :: cout<<"������������ ����������� out_of_range:"<<e.what()<<"\n";
		}
		
		catch (...) { 
			std :: cout<<"������������ ����������� ����������� ����������.\n";
		}
		
	   	std :: cout<<"------------------------------\n";
		
	
}

	return 0;
}