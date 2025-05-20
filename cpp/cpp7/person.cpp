class Person {
protected:
    static int countObjects; // ������� ��������

public:
    Person() { ++countObjects; }
    virtual ~Person() { --countObjects; }

    static int getCountObjects() { return countObjects; }

    virtual void print() const = 0;

    // ���������� ���������� ��������� �� ���� 'name' (��������)
    virtual bool operator<(const Person& other) const = 0;
    virtual bool operator>(const Person& other) const = 0;
};

// ������������� ������������ ��������
int Person::countObjects = 0;

// � ����������� ��������� ��������� ��������� �� ������ �����.