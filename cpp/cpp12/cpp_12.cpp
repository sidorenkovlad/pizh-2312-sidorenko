#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// ����� Product
class Product {
private:
    std::string name;
    double price;
    int quantity;

public:
    // ������������
    Product() : name(""), price(0.0), quantity(0) {}
    Product(const std::string& n, double p, int q) : name(n), price(p), quantity(q) {}

    // �������
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    // �������
    void setName(const std::string& n) { name = n; }
    void setPrice(double p) { price = p; }
    void setQuantity(int q) { quantity = q; }

    // ����� ���������� � ������
    void display() const {
        std::cout << "Name: " << name
                  << ", Price: " << price
                  << ", Quantity: " << quantity << std::endl;
    }
};

// ������� ��� ����������� ���� ������� � ����������
void displayProducts(const std::vector<Product>& products) {
    for (const auto& p : products) {
        p.display();
    }
}

int main() {
    // ������� �������� ��������� � ��������
    std::vector<Product> products = {
        Product("Apple", 30.5, 50),
        Product("Banana", 20.0, 100),
        Product("Orange", 25.0, 80),
        Product("Grapes", 60.0, 40),
        Product("Watermelon", 45.0, 20)
    };

    std::cout << "�������� ���������:\n";
    displayProducts(products);

    // 1. ���������� �� �������� ���� � ������� ������-�������
    std::sort(products.begin(), products.end(),
              [](const Product& a, const Product& b) {
                  return a.getPrice() > b.getPrice();
              });

    std::cout << "\n����� ���������� �� �������� ����:\n";
    displayProducts(products);

    // 2. ����� ������ � ����� ���� ��������� �������� (��������, ���� 50)
    double priceThreshold = 50.0;
    
    auto it = std::find_if(products.begin(), products.end(),
                           [priceThreshold](const Product& p) {
                               return p.getPrice() < priceThreshold;
                           });
    
    if (it != products.end()) {
        std::cout << "\n������ ����� � ����� ���� " << priceThreshold << ":\n";
        it->display();
    } else {
        std::cout << "\n������ � ����� ���� " << priceThreshold << " �� �������.\n";
    }

    // 3. ����������� ���������, ��������������� ������� (��������, ���� < 50), � ������ ���������
    std::vector<Product> filteredProducts;

    // ���������� copy_if � ������-�������� ��� ����������� ���������� ���������
    std::copy_if(products.begin(), products.end(), std::back_inserter(filteredProducts),
                 [](const Product& p){ return p.getPrice() < 50; });

    // ������� ��� �������� �� ��������� ���������� (���������� remove_if � erase)
    auto new_end = std::remove_if(products.begin(), products.end(),
                                  [](const Product& p){ return p.getPrice() < 50; });
    products.erase(new_end, products.end());

    // ������ �������� ��������� �������� ������ � ����� >=50,
    // � filteredProducts � ������ � ����� <50

    // 4. �������� ������� ����������
    std::cout << "\n������ ��������� (������ � ����� <50):\n";
    displayProducts(filteredProducts);

    // 5. ������������� ��� ���������� �� ����������� ���� � ������� ������-�������
   auto sortByPriceAsc = [](std::vector<Product>& cont){
       std::sort(cont.begin(), cont.end(),
                 [](const Product& a, const Product& b){
                     return a.getPrice() < b.getPrice();
                 });
   };

   sortByPriceAsc(products);
   sortByPriceAsc(filteredProducts);

   // ����� ��������������� �����������
   std::cout << "\n������ ��������� ����� ���������� �� ����������� ����:\n";
   displayProducts(products);

   std::cout << "\n������ ��������� ����� ���������� �� ����������� ����:\n";
   displayProducts(filteredProducts);

   return 0;
}