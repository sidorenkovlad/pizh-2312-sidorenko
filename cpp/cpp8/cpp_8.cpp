#include <iostream>
#include <string>
#include <stdexcept>

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

// �������, ���������� ���������� ������ �����
void generateExceptions(int choice) {
    switch (choice) {
        case 1:
            throw 42; // ���������� ���� int
        case 2:
            throw std::string("������ ������"); // ���������� ���� string
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
            // ���������� ��������� ���������� ��� ������������ catch(...)
            throw 0.0; // ���������� ���� double (�������������� ����)
    }
}

// ������� � ��������� ���������� ����������
void processWithLocalCatch(int choice) {
    try {
        generateExceptions(choice);
    } catch (const int& e) {
        std::cout << "�������� ������� ���������� ���� int: " << e << std::endl;
    } catch (const std::string& e) {
        std::cout << "�������� ������� ���������� ���� string: " << e << std::endl;
    } catch (const MyLogicError& e) {
        std::cout << "�������� ������� ����������� ���������� ����������: " << e.what() << std::endl;
    } catch (const MyRuntimeError& e) {
        std::cout << "�������� ������� ����������� ��������� ����������: " << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "�������� ������� invalid_argument: " << e.what() << std::endl;
    } catch (const std::length_error& e) {
        std::cout << "�������� ������� length_error: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "�������� ������� out_of_range: " << e.what() << std::endl;
    } catch (...) { // �������� ���� ���������
        std::cout << "�������� ������� ����������� ����������." << std::endl;
    }
}

// �������� ������� - ������� ������� ���������
int main() {
    for (int i = 1; i <= 8; ++i) {
        try {
            // ����� �������, ������� ����� ��������� ������ ���� ����������
            processWithLocalCatch(i);
        }
        catch (const int& e) {
            std::cout << "������������ ����������� ���������� ���� int: " << e << "\n";
        }
        catch (const std::string& e) {
            std::cout << "������������ ����������� ���������� ���� string: " << e << "\n";
        }
        catch (const MyLogicError& e) {
            std::cout << "������������ ����������� ����������� ���������� ����������: " << e.what() << "\n";
        }
        catch (const MyRuntimeError& e) {
            std::cout << "������������ ����������� ����������� ��������� ����������: " << e.what() << "\n";
        }
        catch (const std::invalid_argument& e) {
            std::cout << "������������ ����������� invalid_argument: " << e.what() << "\n";
        }
        catch (const std::length_error& e) {
            std::cout << "������������ ����������� length_error: " << e.what() << "\n";
        }
        catch (const std::out_of_range& e) {
           	std :: cout<< ������������� ����������� out_of_range:�<<e.what()<<�\n�;
		}
		catch (...) { // �������� ���� ��������� �����
			std :: cout<< ������������� ����������� ����������� ����������.�<<�\n�;
		}
		std :: cout<< �------------------------------�<<�\n�;
	}
	return 0;
}