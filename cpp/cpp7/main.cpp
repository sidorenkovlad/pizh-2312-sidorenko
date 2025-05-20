int main() {
    try {
        // Массив целых чисел
        Array<int> intArray(5);
        for (size_t i=0; i<intArray.getSize(); ++i)
            intArray.setElement(i, i * 10);
        std::cout << "Минимум int: " << intArray.min() << std::endl;
        std::cout << "Максимум int: " << intArray.max() << std::endl;

        // Массив символов
        Array<char> charArray(3);
        charArray.setElement(0, 'a');
        charArray.setElement(1, 'z');
        charArray.setElement(2, 'm');
        std::cout << "Минимум char: " << charArray.min() << std::endl;
        std::cout << "Максимум char: " << charArray.max() << std::endl;

        // Массив указателей на базовый класс Person*
        Array<Person*> personPtrArray(3);
        
        personPtrArray.setElement(0, new Kontakt("Ivan"));
        personPtrArray.setElement(1, new Employee("Petrov", 50000));
        personPtrArray.setElement(2, new Customer("Sidorov", 12345));

        for (size_t i=0; i<personPtrArray.getSize(); ++i)
            personPtrArray.getElement(i)->print();

        // Поиск min/max по указателям (по имени контакта или другим полям)
        
        Person* minPerson = *std::min_element(personPtrArray.getData(), 
                                              personPtrArray.getData() + personPtrArray.getSize(),
                                              [](Person* a, Person* b){ return *a < *b; });
                                              
        Person* maxPerson = *std::max_element(personPtrArray.getData(), 
                                              personPtrArray.getData() + personPtrArray.getSize(),
                                              [](Person* a, Person* b){ return *a > *b; });
                                              
       std::cout << "\nМинимальный объект:\n"; minPerson->print();
       std::cout << "\nМаксимальный объект:\n"; maxPerson->print();

       // Освобождение памяти
       for (size_t i=0; i<personPtrArray.getSize(); ++i)
           delete personPtrArray.getElement(i);

   } catch(const std::exception& e) {
       std::cerr << e.what() << '\n';
   }
   return 0;
}