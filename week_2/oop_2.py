class Worker:
    def __init__(self, name, position, experience):
        self.name = name
        self.position = position
        self.experience = experience

    def print_info(self):
        # Определяем правильное окончание для слова "год"
        if self.experience % 10 == 1 and self.experience % 100 != 11:
            year_word = "год"
        elif 2 <= self.experience % 10 <= 4 and not (12 <= self.experience % 100 <= 14):
            year_word = "года"
        else:
            year_word = "лет"

        # Выводим информацию о сотруднике
        print(f"Имя: {self.name}")
        print(f"Должность: {self.position}")
        print(f"Стаж: {self.experience} {year_word}")


# Создаем экземпляры класса Worker и выводим информацию
worker1 = Worker("Алексей", "Программист", 17)
worker1.print_info()
print()

worker2 = Worker("Анна", "Маркетолог", 2)
worker2.print_info()
print()

worker3 = Worker("Дмитрий", "Аналитик", 1)
worker3.print_info()
print()
