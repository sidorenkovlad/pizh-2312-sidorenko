# pizza_order.py

from abc import ABC, abstractmethod

# Определение классов пиццы
class Pizza(ABC):
    def __init__(self, name, dough, sauce, toppings, price):
        self.name = name
        self.dough = dough
        self.sauce = sauce
        self.toppings = toppings
        self.price = price

    def __str__(self):
        return f"{self.name} (${self.price})"

    @abstractmethod
    def prepare(self):
        pass

class PepperoniPizza(Pizza):
    def __init__(self):
        super().__init__(
            name="Pepperoni Pizza",
            dough="Thin",
            sauce="Tomato",
            toppings=["Pepperoni", "Cheese"],
            price=12
        )

    def prepare(self):
        print(f"Preparing {self.name} with {', '.join(self.toppings)}...")

class BBQPizza(Pizza):
    def __init__(self):
        super().__init__(
            name="BBQ Pizza",
            dough="Thick",
            sauce="Barbecue",
            toppings=["Chicken", "Onions"],
            price=15
        )

    def prepare(self):
        print(f"Preparing {self.name} with {', '.join(self.toppings)}...")

# Класс заказа
class Order:
    def __init__(self):
        self.pizzas = []

    def add_pizza(self, pizza):
        self.pizzas.append(pizza)

    def get_total_price(self):
        return sum(pizza.price for pizza in self.pizzas)

    def show_order(self):
        if not self.pizzas:
            print("Your order is empty.")
        else:
            print("Your order contains:")
            for idx, pizza in enumerate(self.pizzas, start=1):
                print(f"{idx}. {pizza}")

# Функция отображения меню
def show_menu():
    print("\nMenu:")
    print("1. Pepperoni Pizza")
    print("2. BBQ Pizza")
    print("q. Quit\n")

def main():
    order = None

    while True:
        show_menu()
        choice = input("Select a pizza by number or 'q' to quit: ").strip()

        if choice.lower() == 'q':
            # Завершение заказа и вывод итоговой суммы
            if order and order.pizzas:
                order.show_order()
                total = order.get_total_price()
                print(f"\nTotal price: ${total}")
                print("Thank you for your order!")
            else:
                print("No pizzas ordered. Goodbye!")
            break

        elif choice in ('1', '2'):
            # Создание выбранной пиццы и добавление в заказ
            if choice == '1':
                pizza = PepperoniPizza()
            elif choice == '2':
                pizza = BBQPizza()

            if order is None:
                order = Order()

            pizza.prepare()
            order.add_pizza(pizza)
            print(f"{pizza.name} added to your order.\n")
        else:
            print("Invalid choice. Please try again.\n")

if __name__ == "__main__":
    main()