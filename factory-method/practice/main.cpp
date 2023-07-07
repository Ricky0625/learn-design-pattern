#include <iostream>

using std::cout;

/**
 * Product
*/
class Order {
public:
    virtual void createOrder() = 0;
};

/**
 * ConcreteProducts
*/
class PizzaOrder: public Order {
public:
    void createOrder() override {
        cout << "[Cart]: One Pepperoni Pizza with extra cheese\n";        
    }
};
class BurgerOrder: public Order {
public:
    void createOrder() override {
        cout << "[Cart]: One LA Burger with chessy fries\n";
    }
};
class SushiOrder: public Order {
public:
    void createOrder() override {
        cout << "[Cart]: One Salmon Sushi with extra salmon\n";
    }
};

/**
 * Creator
*/
class OrderCreator {
public:
    virtual ~OrderCreator() {}
    virtual Order* createOrder() const = 0;

    void showOrder() const {
        Order* order = this->createOrder();
        order->createOrder();
    }
};

/**
 * ConcreteCreators
*/
class PizzaOrderCreator: public OrderCreator {
public:
    Order* createOrder() const override {
        return new PizzaOrder();
    }
};
class BurgerOrderCreator: public OrderCreator {
public:
    Order* createOrder() const override {
        return new BurgerOrder();
    }
};
class SushiOrderCreator: public OrderCreator {
public:
    Order* createOrder() const override {
        return new SushiOrder();
    }
};

/**
 * Client
*/
void takeInOrder(const OrderCreator& creator) {
    creator.showOrder();
}

int main() {
    {
        cout << "CLIENT 1" << "\n";
        cout << "I want to order a pizza\n";
        PizzaOrderCreator creator;
        takeInOrder(creator);
    }
    {
        cout << "CLIENT 2" << "\n";
        cout << "I want to order a burger and a sushi\n";
        BurgerOrderCreator creator1;
        SushiOrderCreator creator2;
        takeInOrder(creator1);
        takeInOrder(creator2);
    }
    {
        cout << "CLIENT 3" << "\n";
        cout << "I WANT EVERYTHING!" << "\n";
        PizzaOrderCreator creator1;
        BurgerOrderCreator creator2;
        SushiOrderCreator creator3;
        takeInOrder(creator1);
        takeInOrder(creator2);
        takeInOrder(creator3);
    }
}
