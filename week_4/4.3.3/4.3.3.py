from abc import ABC, abstractmethod


class Deposit(ABC):
    def __init__(self, principal: float, term: int):
        self.principal = principal  # сумма вклада
        self.term = term  # срок вклада в месяцах или годах (зависит от контекста)

    @abstractmethod
    def calculate_profit(self) -> float:
        pass

    def get_final_amount(self) -> float:
        return self.principal + self.calculate_profit()


# Срочный вклад с простыми процентами
class FixedDeposit(Deposit):
    def __init__(self, principal: float, term: int, interest_rate: float):
        super().__init__(principal, term)
        self.interest_rate = interest_rate  # годовая ставка в процентах

    def calculate_profit(self) -> float:
        t = self.term / 12  # если term в месяцах, переводим в годы
        profit = self.principal * self.interest_rate * t / 100
        return profit


# Бонусный вклад с бонусом в конце периода при условии превышения суммы
class BonusDeposit(Deposit):
    def __init__(self, principal: float, term: int, interest_rate: float,
                 bonus_percent: float, bonus_threshold: float):
        super().__init__(principal, term)
        self.interest_rate = interest_rate
        self.bonus_percent = bonus_percent  # % бонуса от прибыли
        self.bonus_threshold = bonus_threshold  # минимальная сумма вклада для бонуса

    def calculate_profit(self) -> float:
        t = self.term / 12  # переводим в годы при необходимости
        profit = self.principal * self.interest_rate * t / 100

        if self.principal >= self.bonus_threshold:
            bonus = profit * self.bonus_percent / 100
            profit += bonus

        return profit


# Вклад с капитализацией процентов (проценты добавляются к основной сумме каждый период)
class CapitalizationDeposit(Deposit):
    def __init__(self, principal: float, term: int, interest_rate: float):
        super().__init__(principal, term)
        self.interest_rate = interest_rate

    def calculate_profit(self) -> float:
        months = self.term
        amount = self.principal
        monthly_rate = self.interest_rate / 12 / 100

        for _ in range(months):
            interest = amount * monthly_rate
            amount += interest

        profit = amount - self.principal
        return profit


def main():
    print("Добро пожаловать! Рассчитаем вклад.\n")

    while True:
        print("Выберите тип вклада:")
        print("1 - Срочный вклад (простые проценты)")
        print("2 - Бонусный вклад")
        print("3 - Вклад с капитализацией процентов")
        print("0 - Выход")

        choice = input("Введите номер варианта: ")

        if choice == '0':
            print("Завершение программы.")
            break

        try:
            principal = float(input("Введите изначальную сумму вклада: "))
            term_months = int(input("Введите срок вклада в месяцах: "))

            if choice == '1':
                interest_rate = float(input("Введите годовую ставку (%): "))
                deposit = FixedDeposit(principal, term_months, interest_rate)

            elif choice == '2':
                interest_rate = float(input("Введите годовую ставку (%): "))
                bonus_percent = float(input("Введите процент бонуса (%): "))
                bonus_threshold = float(input("Введите минимальную сумму для получения бонуса: "))
                deposit = BonusDeposit(principal, term_months, interest_rate,
                                       bonus_percent, bonus_threshold)

            elif choice == '3':
                interest_rate = float(input("Введите годовую ставку (%): "))
                deposit = CapitalizationDeposit(principal, term_months, interest_rate)

            else:
                print("Некорректный выбор. Попробуйте снова.\n")
                continue

            profit = deposit.calculate_profit()
            total_amount = deposit.get_final_amount()

            print(f"\nРезультаты расчета:")
            print(f"Прибыль за период: {profit:.2f}")
            print(f"Итоговая сумма на конец срока: {total_amount:.2f}\n")

        except ValueError:
            print("Ошибка ввода. Пожалуйста, вводите числовые значения.\n")


if __name__ == "__main__":
    main()