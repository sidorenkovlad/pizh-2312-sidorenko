    // Использование итераторов для обхода контейнера
    std::cout << "\nОбход с помощью итераторов:\n";
    for (auto it = people.begin(); it != people.end(); ++it) {
        std::cout << *it << std::endl;
        // Можно также изменять элементы через итератор:
        // it->setAge(it->getAge() + 2);
    }