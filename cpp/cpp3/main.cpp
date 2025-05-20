int main() {
    // Создаем объекты базового и наследуемых классов
    Kontact baseContact;
    
    // Объект базового класса
    baseContact.input();
    
    // Объект наследника Email
    EmailKontakt emailContact("Иванов Иван", "+7 123 456", "г. Москва", "ivan@example.com");
    
    // Объект наследника Business
   BusinessKontakt businessContact("Петров Петр", "+7 987 654", "г. Санкт-Петербург", "ООО Рога и Копыта");
   
   // Вывод объектов
   cout << "\n--- Вывод базового контакта ---\n";
   baseContact.display();

   cout << "\n--- Вывод контакта с email ---\n";
   emailContact.display();

   cout << "\n--- Вывод бизнес-контакта ---\n";
   businessContact.display();

   // Массив указателей на базовый класс
   vector<Kontakt*> contacts;
   contacts.push_back(&baseContact);
   contacts.push_back(&emailContact);
   contacts.push_back(&businessContact);

   // Проходим по массиву и вызываем display()
   cout << "\n=== Вывод всех контактов через массив указателей ===\n";
   for (auto ptr : contacts) {
       ptr->display();
       cout << endl;
   }

   // Массив объектов одного из наследников (например, Emailkontakt)
   vector<Email kontaktEmails = { 
       Email("Alice", "+7 111 222", "г. Новосибирск", "alice@example.com"),
       Email("Bob", "+7 333 444", "г. Екатеринбург", "bob@example.com")
   };

   for (const auto& e : kontaktEmails) {
       e.display();
       cout<<endl;
   }

   return 0;
}