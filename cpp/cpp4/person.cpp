#include <iostream>
#include <vector>
#include <string>

class Person {
public:
    virtual ~Person() {} // виртуальный деструктор
    virtual void print() const = 0; // чисто виртуальная функция
};