#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Класс Product
class Product {
private:
    std::string name;
    double price;
    int quantity;

public:
    // Конструкторы
    Product() : name(""), price(0.0), quantity(0) {}
    Product(const std::string& n, double p, int q) : name(n), price(p), quantity(q) {}

    // Геттеры
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    // Сеттеры
    void setName(const std::string& n) { name = n; }
    void setPrice(double p) { price = p; }
    void setQuantity(int q) { quantity = q; }

    // Вывод информации о товаре
    void display() const {
        std::cout << "Name: " << name
                  << ", Price: " << price
                  << ", Quantity: " << quantity << std::endl;
    }
};

// Функция для отображения всех товаров в контейнере
void displayProducts(const std::vector<Product>& products) {
    for (const auto& p : products) {
        p.display();
    }
}

int main() {
    // Создаем исходный контейнер с товарами
    std::vector<Product> products = {
        Product("Apple", 30.5, 50),
        Product("Banana", 20.0, 100),
        Product("Orange", 25.0, 80),
        Product("Grapes", 60.0, 40),
        Product("Watermelon", 45.0, 20)
    };

    std::cout << "Исходный контейнер:\n";
    displayProducts(products);

    // 1. Сортировка по убыванию цены с помощью лямбда-функции
    std::sort(products.begin(), products.end(),
              [](const Product& a, const Product& b) {
                  return a.getPrice() > b.getPrice();
              });

    std::cout << "\nПосле сортировки по убыванию цены:\n";
    displayProducts(products);

    // 2. Поиск товара с ценой ниже заданного значения (например, ниже 50)
    double priceThreshold = 50.0;
    
    auto it = std::find_if(products.begin(), products.end(),
                           [priceThreshold](const Product& p) {
                               return p.getPrice() < priceThreshold;
                           });
    
    if (it != products.end()) {
        std::cout << "\nНайден товар с ценой ниже " << priceThreshold << ":\n";
        it->display();
    } else {
        std::cout << "\nТовары с ценой ниже " << priceThreshold << " не найдены.\n";
    }

    // 3. Перемещение элементов, удовлетворяющих условию (например, цена < 50), в другой контейнер
    std::vector<Product> filteredProducts;

    // Используем copy_if с лямбда-функцией для копирования подходящих элементов
    std::copy_if(products.begin(), products.end(), std::back_inserter(filteredProducts),
                 [](const Product& p){ return p.getPrice() < 50; });

    // Удаляем эти элементы из исходного контейнера (используем remove_if и erase)
    auto new_end = std::remove_if(products.begin(), products.end(),
                                  [](const Product& p){ return p.getPrice() < 50; });
    products.erase(new_end, products.end());

    // Теперь исходный контейнер содержит товары с ценой >=50,
    // а filteredProducts — товары с ценой <50

    // 4. Просмотр второго контейнера
    std::cout << "\nВторой контейнер (товары с ценой <50):\n";
    displayProducts(filteredProducts);

    // 5. Отсортировать оба контейнера по возрастанию цены с помощью лямбда-функции
   auto sortByPriceAsc = [](std::vector<Product>& cont){
       std::sort(cont.begin(), cont.end(),
                 [](const Product& a, const Product& b){
                     return a.getPrice() < b.getPrice();
                 });
   };

   sortByPriceAsc(products);
   sortByPriceAsc(filteredProducts);

   // Вывод отсортированных контейнеров
   std::cout << "\nПервый контейнер после сортировки по возрастанию цены:\n";
   displayProducts(products);

   std::cout << "\nВторой контейнер после сортировки по возрастанию цены:\n";
   displayProducts(filteredProducts);

   return 0;
}