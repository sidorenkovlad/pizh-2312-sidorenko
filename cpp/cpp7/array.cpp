#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> // ��� std::min_element, std::max_element

// ��������������� ���������� �������� ������ ��� ������������� � �������
class Person; // ���������� ��� �����������, ��� ��� ����� ������ ��� ����������

// ��������� ����� Array
template <typename T>
class Array {
private:
    T* data;          // ��������� �� ������ ���������
    size_t size;      // ���������� ���������
    size_t capacity;  // ������� ������� ������� (����� ��������� ��� �������������)

public:
    // �����������: ������� ������ �� n ���������
    Array(size_t n) : size(n), capacity(n) {
        data = new T[capacity];
    }

    // ����������
    ~Array() {
        delete[] data;
    }

    // ����� ���������� �������� � ������ (�� �������)
    void setElement(size_t index, const T& value) {
        if (index >= size) {
            std::cerr << "������ ��� ���������." << std::endl;
            return;
        }
        data[index] = value;
    }

    // ����� ��������� �������� �� �������
    T getElement(size_t index) const {
        if (index >= size) {
            std::cerr << "������ ��� ���������." << std::endl;
            return T(); // ���������� �������� �� ���������
        }
        return data[index];
    }

    // ��������� ������� �������
    size_t getSize() const {
        return size;
    }

    // ������� min: ���������� ����������� ������� �������
    T min() const {
        if (size == 0) {
            throw std::runtime_error("������ ����");
        }
        return *std::min_element(data, data + size);
    }

    // ������� max: ���������� ������������ ������� �������
    T max() const {
        if (size == 0) {
            throw std::runtime_error("������ ����");
        }
        return *std::max_element(data, data + size);
    }
};