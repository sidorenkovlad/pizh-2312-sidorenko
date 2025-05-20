#include <iostream>
#include <string>
#include <stdexcept>

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

// Функция, вызывающая исключения разных типов
void generateExceptions(int choice) {
    switch (choice) {
        case 1:
            throw 42; // исключение типа int
        case 2:
            throw std::string("Ошибка строки"); // исключение типа string
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
            // Генерируем случайное исключение для демонстрации catch(...)
            throw 0.0; // исключение типа double (необработанное выше)
    }
}

// Функция с локальной обработкой исключений
void processWithLocalCatch(int choice) {
    try {
        generateExceptions(choice);
    } catch (const int& e) {
        std::cout << "Локально поймано исключение типа int: " << e << std::endl;
    } catch (const std::string& e) {
        std::cout << "Локально поймано исключение типа string: " << e << std::endl;
    } catch (const MyLogicError& e) {
        std::cout << "Локально поймано собственное логическое исключение: " << e.what() << std::endl;
    } catch (const MyRuntimeError& e) {
        std::cout << "Локально поймано собственное ошибочное исключение: " << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Локально поймано invalid_argument: " << e.what() << std::endl;
    } catch (const std::length_error& e) {
        std::cout << "Локально поймано length_error: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Локально поймано out_of_range: " << e.what() << std::endl;
    } catch (...) { // перехват всех остальных
        std::cout << "Локально поймано неизвестное исключение." << std::endl;
    }
}

// Основная функция - верхний уровень обработки
int main() {
    for (int i = 1; i <= 8; ++i) {
        try {
            // Вызов функции, которая может выбросить разные типы исключений
            processWithLocalCatch(i);
        }
        catch (const int& e) {
            std::cout << "Верхнеуровне перехвачено исключение типа int: " << e << "\n";
        }
        catch (const std::string& e) {
            std::cout << "Верхнеуровне перехвачено исключение типа string: " << e << "\n";
        }
        catch (const MyLogicError& e) {
            std::cout << "Верхнеуровне перехвачено собственное логическое исключение: " << e.what() << "\n";
        }
        catch (const MyRuntimeError& e) {
            std::cout << "Верхнеуровне перехвачено собственное ошибочное исключение: " << e.what() << "\n";
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Верхнеуровне перехвачено invalid_argument: " << e.what() << "\n";
        }
        catch (const std::length_error& e) {
            std::cout << "Верхнеуровне перехвачено length_error: " << e.what() << "\n";
        }
        catch (const std::out_of_range& e) {
           	std :: cout<< “Верхнеуровне перехвачено out_of_range:”<<e.what()<<“\n”;
		}
		catch (...) { // Перехват всех остальных типов
			std :: cout<< “Верхнеуровне перехвачено неизвестное исключение.”<<“\n”;
		}
		std :: cout<< “------------------------------”<<“\n”;
	}
	return 0;
}