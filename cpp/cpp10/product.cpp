#include "Product.h" // ��� ����� Product

int main() {
    std::vector<Product> products;

    // ���������� �������
    products.emplace_back("Laptop", 1500);
    products.emplace_back("Smartphone", 800);
    
    // ��������
    for (const auto& product : products) {
        std::cout << product << std::endl;
    }

    // ���������: ��������, ��������� ���� �� 10%
    for (auto& product : products) {
        product.setPrice(product.getPrice() * 1.10);
    }

    // �������� ������� �� ������� (��������, ���� ���� ������������)
    products.erase(
        std::remove_if(products.begin(), products.end(),
            [](const Product& p) { return p.getPrice() < 900; }),
        products.end()
    );

    // �������� � ������� ����������
    std::cout << "\n����������� ������ ���������:\n";
    for (auto it = products.begin(); it != products.end(); ++it) {
        std::cout << *it << std::endl;
        // ����� �������� ����� ��������
        // it->setPrice(it->getPrice() * 1.05);
    }
}