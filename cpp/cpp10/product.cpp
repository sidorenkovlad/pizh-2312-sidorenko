#include "Product.h" // ваш класс Product

int main() {
    std::vector<Product> products;

    // Заполнение данными
    products.emplace_back("Laptop", 1500);
    products.emplace_back("Smartphone", 800);
    
    // Просмотр
    for (const auto& product : products) {
        std::cout << product << std::endl;
    }

    // Изменение: например, увеличить цену на 10%
    for (auto& product : products) {
        product.setPrice(product.getPrice() * 1.10);
    }

    // Удаление товаров по условию (например, цена ниже определенной)
    products.erase(
        std::remove_if(products.begin(), products.end(),
            [](const Product& p) { return p.getPrice() < 900; }),
        products.end()
    );

    // Просмотр с помощью итераторов
    std::cout << "\nОбновленный список продуктов:\n";
    for (auto it = products.begin(); it != products.end(); ++it) {
        std::cout << *it << std::endl;
        // Можно изменять через итератор
        // it->setPrice(it->getPrice() * 1.05);
    }
}