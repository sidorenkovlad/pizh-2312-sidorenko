    // ������������� ���������� ��� ������ ����������
    std::cout << "\n����� � ������� ����������:\n";
    for (auto it = people.begin(); it != people.end(); ++it) {
        std::cout << *it << std::endl;
        // ����� ����� �������� �������� ����� ��������:
        // it->setAge(it->getAge() + 2);
    }