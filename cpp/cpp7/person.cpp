class Person {
protected:
    static int countObjects; // счетчик объектов

public:
    Person() { ++countObjects; }
    virtual ~Person() { --countObjects; }

    static int getCountObjects() { return countObjects; }

    virtual void print() const = 0;

    // Перегрузка операторов сравнения по полю 'name' (например)
    virtual bool operator<(const Person& other) const = 0;
    virtual bool operator>(const Person& other) const = 0;
};

// Инициализация статического счетчика
int Person::countObjects = 0;

// В наследниках реализуем операторы сравнения по нужным полям.