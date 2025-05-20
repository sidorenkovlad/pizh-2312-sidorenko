// Удаляем всех людей младше 30 лет
    people.erase(
        std::remove_if(people.begin(), people.end(),
            [](const Person& p) { return p.getAge() < 30; }),
        people.end()
    );

    // Изменяем данные: например, увеличиваем возраст всех оставшихся на 1 год
    for (auto& person : people) {
        person.setAge(person.getAge() + 1);
    }

    // Просмотр после изменений
    std::cout << "\nКонтейнер после удаления и изменения:\n";
    for (const auto& person : people) {
        std::cout << person << std::endl;
    }