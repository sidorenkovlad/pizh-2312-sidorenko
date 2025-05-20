#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

// Базовый класс
class Person {
protected:
    std::string name;
    int age;

public:
    Person() : name(""), age(0) {}
    Person(const std::string& n, int a) : name(n), age(a) {}

    // Глобальные операторы
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    friend std::istream& operator>>(std::istream& is, Person& p);

    // Методы для сохранения/чтения из файла
    void saveToFile(const std::string& filename) const {
        std::ofstream ofs(filename);
        if (!ofs) {
            throw std::runtime_error("Не удалось открыть файл для записи");
        }
        ofs << name << '\n' << age << '\n';
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream ifs(filename);
        if (!ifs) {
            throw std::runtime_error("Не удалось открыть файл для чтения");
        }
        getline(ifs, name);
        ifs >> age;
        // Очистка буфера после чтения числа
        ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};

// Глобальный оператор вывода
std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "Имя: " << p.name << ", Возраст: " << p.age;
    return os;
}

// Глобальный оператор ввода
std::istream& operator>>(std::istream& is, Person& p) {
    std::cout << "Введите имя: ";
    getline(is, p.name);
    std::cout << "Введите возраст: ";
    is >> p.age;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return is;
}

// Далее идет ваш существующий код с исключениями и обработкой

// Собственный класс ошибки, наследуемый от std::logic_error
class MyLogicError : public std::logic_error {
public:
    explicit MyLogicError(const std::string& message)
        : std::logic_error("MyLogicError: " + message) {}
};

// Еще один собственный класс ошибки, наследуемый от std::runtime_error
class MyRuntimeError : public std::runtime_error {
public:
    explicit MyRuntimeError(const std::string& message)
        : std::runtime_error("MyRuntimeError: " + message) {}
};

// Функция генерации исключений (оставляем без изменений)
void generateExceptions(int choice) {
    switch (choice) {
        case 1:
            throw 42; // исключение типа int
        case 2:
            throw std::string("Ошибка строки");
        case 3:
            throw std::invalid_argument("Некорректный аргумент");
        case 4:
            throw std::length_error("Длина превышена");
        case 5:
            throw std::out_of_range("Выход за границы");
        case 6:
            throw MyLogicError("Логическая ошибка");
        case 7:
            throw MyRuntimeError("Ошибки выполнения");
        default:
            throw 0.0; // неожиданное исключение
    }
}

// Функция обработки с локальным перехватом (оставляем без изменений)
void processWithLocalCatch(int choice) {
    try {
        generateExceptions(choice);
    } catch (const int& e) {
        std::cout << "Локально поймано исключение типа int: " << e << "\n";
    } catch (const std::string& e) {
        std::cout << "Локально поймано исключение типа string: " << e << "\n";
    } catch (const MyLogicError& e) {
        std::cout << "Локально поймано собственное логическое исключение: " << e.what() << "\n";
    } catch (const MyRuntimeError& e) {
        std::cout << "Локально поймано собственное ошибочное исключение: " << e.what() << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Локально поймано invalid_argument: " << e.what() << "\n";
    } catch (const std::length_error& e) {
        std::cout << "Локально поймано length_error: " << e.what() << "\n";
    } catch (const std::out_of_range& e) {
       	std :: cout<< “Локально поймано out_of_range:”<<e.what()<<“\n”;
	}
	catch (...) { 
		std :: cout<< “Локально поймано неизвестное исключение.”<<“\n”;
	}
}

// Основная функция с обработкой и демонстрацией сохранения/чтения объекта
int main() {
    
    // Создаем объект Person
    Person person;

    // Ввод данных пользователя
    try {
        std :: cin>>person;
        
        // Сохраняем в файл
        person.saveToFile("person.txt");
        
        // Выводим на экран
        std :: cout<<"Объект сохранен в файл.\n";

        // Загружаем из файла в новый объект для проверки
        Person personFromFile;
        personFromFile.loadFromFile("person.txt");
        
        // Выводим загруженный объект
        std :: cout<<"Прочитанный из файла объект:\n"<<personFromFile<<"\n";

        
    } catch(const std :: exception &e){
    	std :: cerr<<"Ошибка при работе с файлом или вводе: "<<e.what()<<"\n";
	}

    
	// Демонстрация обработки исключений как раньше
	for (int i = 1; i <= 8; ++i) {
		try {
			processWithLocalCatch(i);
		}
		catch (const int& e) {
			std :: cout<<“Верхнеуровне перехвачено исключение типа int:”<<e<<"\n”;
		}
		catch (const std :: string &e){
			std :: cout<<“Верхнеуровне перехвачено исключение типа string:”<<e<<"\n”;
		}
		catch (const MyLogicError &e){
			std :: cout<<“Верхнеуровне перехвачено собственное логическое исключение:”<<e.what()<<“\n”;
		}
		catch (const MyRuntimeError &e){
			std :: cout<<“Верхнеуровне перехвачено собственное ошибочное исключение:”<<e.what()<<“\n”;
		}
		catch(const std :: invalid_argument &e){
			std :: cout<<"Верхнеуровне перехвачено invalid_argument:"<<e.what()<<"\n";
		}
		catch(const std :: length_error &e){
			std :: cout<<"Верхнеуровне перехвачено length_error:"<<e.what()<<"\n";
		}
		catch(const std :: out_of_range &e){
			std :: cout<<"Верхнеуровне перехвачено out_of_range:"<<e.what()<<"\n";
		}
		
		catch (...) { 
			std :: cout<<"Верхнеуровне перехвачено неизвестное исключение.\n";
		}
		
	   	std :: cout<<"------------------------------\n";
		
	
}

	return 0;
}