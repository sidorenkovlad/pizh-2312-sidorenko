int main() {
    // ������� ������� �������� � ����������� �������
    Kontact baseContact;
    
    // ������ �������� ������
    baseContact.input();
    
    // ������ ���������� Email
    EmailKontakt emailContact("������ ����", "+7 123 456", "�. ������", "ivan@example.com");
    
    // ������ ���������� Business
   BusinessKontakt businessContact("������ ����", "+7 987 654", "�. �����-���������", "��� ���� � ������");
   
   // ����� ��������
   cout << "\n--- ����� �������� �������� ---\n";
   baseContact.display();

   cout << "\n--- ����� �������� � email ---\n";
   emailContact.display();

   cout << "\n--- ����� ������-�������� ---\n";
   businessContact.display();

   // ������ ���������� �� ������� �����
   vector<Kontakt*> contacts;
   contacts.push_back(&baseContact);
   contacts.push_back(&emailContact);
   contacts.push_back(&businessContact);

   // �������� �� ������� � �������� display()
   cout << "\n=== ����� ���� ��������� ����� ������ ���������� ===\n";
   for (auto ptr : contacts) {
       ptr->display();
       cout << endl;
   }

   // ������ �������� ������ �� ����������� (��������, Emailkontakt)
   vector<Email kontaktEmails = { 
       Email("Alice", "+7 111 222", "�. �����������", "alice@example.com"),
       Email("Bob", "+7 333 444", "�. ������������", "bob@example.com")
   };

   for (const auto& e : kontaktEmails) {
       e.display();
       cout<<endl;
   }

   return 0;
}