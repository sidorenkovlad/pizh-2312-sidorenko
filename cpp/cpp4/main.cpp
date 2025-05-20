int main() {
    // ������� ������ ���������� �� ������� �����
    const int size = 3;
    Person* array[size];

    // ������������� �������� ������ �������
    array[0] = new Kontakt("���� ������", "+7-900-123-45-67", "�. ������");
    array[1] = new Employee("���� ������", 50000);
    array[2] = new Customer("��� �������", 12345);

    // ����� ������ print ��� ������� ������� ����� ������� ���������
    for (int i = 0; i < size; ++i) {
        array[i]->print();
        std::cout << "-------------------\n";
    }

   // ������������ ������
   for (int i = 0; i < size; ++i) {
       delete array[i];
   }

   // ������������� ������ Spravochnik
   Spravochnik spr("��� ����������");
   spr.addContact(new Kontakt("������� ��������", "+7-911-222-33-44", "�. �����-���������"));
   spr.addContact(new Employee("����� �������", 60000));
   spr.addContact(new Customer("��� �����", 67890));

   spr.displayAll();

   return 0;
}