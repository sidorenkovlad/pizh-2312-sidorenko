#include <iostream>
#include <vector>
#include <string>

class Person {
public:
    virtual ~Person() {} // ����������� ����������
    virtual void print() const = 0; // ����� ����������� �������
};