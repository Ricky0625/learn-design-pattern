/**
 * Factory Method (Virtual Constructor)
 * 
 * Structure:
 * 1. Product - defines the interface of objects the factory method creates
 * 2. ConcreteProduct - implements the Product interface
 * 3. Creator - declares the factory method, which returns an object of type Product. Creator may also define a default implementation of the factory method that returns a default ConcreteProduct object
 * 4. ConcreteCreator - overrides the factory method to return an instance of a ConcreteProduct
*/

/**
 * Product - Serves as an interface that defines the operations that all ConcreteProduct must implement
 * 
 * NOTE: In C++, this is called as an Abstract class. It's comprised of pure virtual functions.
*/

class Product {
public:
    virtual ~Product() {}
    virtual void operation() = 0;
};

/**
 * ConcreteProduct - Implements the Product interface
*/
class ConcreteProduct : public Product {
public:
    void operation() override {
        // Implementation here
        // Like: "this produce cow milk"
    }
};
class ConcreteProduct2: public Product {
public:
    void operation() override {
        // Implementation here
        // Like: "this produce goat milk"
    }
};

/**
 * Creator
 * 
 * Declares the factory method that returns an object of type Product.
 * The Creator's subclasses usually provide the implementation of this method.
 * Some Creator may also provide some default implementation of the factory method.
*/

class Creator {
public:
    virtual ~Creator() {}
    virtual Product* factoryMethod() const = 0;
    
    /**
     * Creator's primary responsiblility is not creating products.
     * Usually, it contains some core business logic that relies on Product objects,
     * returned by the factory method. Subclasses can indirectly change that business logic
     * by overrding the factory method and returning a different type of product from it.
    */

    // this is where the business logic resides
    void someOperation() const {
        // Call the factory method to create a Product object
        Product* product = this->factoryMethod();
        // Now, use the product
        product->operation();
    }
};

/**
 * ConcreteCreators
 * 
 * Override the factory method to change the resulting product's type.
*/
class ConcreteCreator : public Creator {
public:
    Product* factoryMethod() const override {
        return new ConcreteProduct();
    }
};
class ConcreteCreator2 : public Creator {
public:
    Product* factoryMethod() const override {
        return new ConcreteProduct2();
    }
};
