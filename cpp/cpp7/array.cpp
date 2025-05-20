#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> // для std::min_element, std::max_element

// Предварительное объявление базового класса для использования в шаблоне
class Person; // объявление без определения, так как нужен только для указателей

// Шаблонный класс Array
template <typename T>
class Array {
private:
    T* data;          // указатель на массив элементов
    size_t size;      // количество элементов
    size_t capacity;  // текущая емкость массива (можно расширять при необходимости)

public:
    // Конструктор: создает массив из n элементов
    Array(size_t n) : size(n), capacity(n) {
        data = new T[capacity];
    }

    // Деструктор
    ~Array() {
        delete[] data;
    }

    // Метод добавления элемента в массив (по индексу)
    void setElement(size_t index, const T& value) {
        if (index >= size) {
            std::cerr << "Индекс вне диапазона." << std::endl;
            return;
        }
        data[index] = value;
    }

    // Метод получения элемента по индексу
    T getElement(size_t index) const {
        if (index >= size) {
            std::cerr << "Индекс вне диапазона." << std::endl;
            return T(); // возвращает значение по умолчанию
        }
        return data[index];
    }

    // Получение размера массива
    size_t getSize() const {
        return size;
    }

    // Функция min: возвращает минимальный элемент массива
    T min() const {
        if (size == 0) {
            throw std::runtime_error("Массив пуст");
        }
        return *std::min_element(data, data + size);
    }

    // Функция max: возвращает максимальный элемент массива
    T max() const {
        if (size == 0) {
            throw std::runtime_error("Массив пуст");
        }
        return *std::max_element(data, data + size);
    }
};