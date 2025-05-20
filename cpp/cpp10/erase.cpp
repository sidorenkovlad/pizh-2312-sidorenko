// ������� ���� ����� ������ 30 ���
    people.erase(
        std::remove_if(people.begin(), people.end(),
            [](const Person& p) { return p.getAge() < 30; }),
        people.end()
    );

    // �������� ������: ��������, ����������� ������� ���� ���������� �� 1 ���
    for (auto& person : people) {
        person.setAge(person.getAge() + 1);
    }

    // �������� ����� ���������
    std::cout << "\n��������� ����� �������� � ���������:\n";
    for (const auto& person : people) {
        std::cout << person << std::endl;
    }