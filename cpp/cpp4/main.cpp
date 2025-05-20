int main() {
    // Создаем массив указателей на базовый класс
    const int size = 3;
    Person* array[size];

    // Инициализация объектов разных классов
    array[0] = new Kontakt("Иван Иванов", "+7-900-123-45-67", "г. Москва");
    array[1] = new Employee("Петр Петров", 50000);
    array[2] = new Customer("ООО Ромашка", 12345);

    // Вызов метода print для каждого объекта через базовый указатель
    for (int i = 0; i < size; ++i) {
        array[i]->print();
        std::cout << "-------------------\n";
    }

   // Освобождение памяти
   for (int i = 0; i < size; ++i) {
       delete array[i];
   }

   // Использование класса Spravochnik
   Spravochnik spr("Мой справочник");
   spr.addContact(new Kontakt("Алексей Алексеев", "+7-911-222-33-44", "г. Санкт-Петербург"));
   spr.addContact(new Employee("Ирина Иванова", 60000));
   spr.addContact(new Customer("ЗАО Вишня", 67890));

   spr.displayAll();

   return 0;
}