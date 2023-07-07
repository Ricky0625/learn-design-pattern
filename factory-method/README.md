# Factory Method

Resource: https://refactoring.guru/design-patterns/factory-method

> Factory method is also known as Virtual Constructor.

## Practice

I asked ChatGPT to create a real life scenario where Factory Method can be used. This is the scenario it came up with:

**Online Food Ordering System**

Imagine you are developing an online food ordering system that allows users to order food from various restaurants. As part of the system, you need to implement a feature for creating order objects based on the type of food selected by the user.

In this scenario, you can apply the Factory Method design pattern to handle the creation of order objects. The Factory Method pattern allows you to encapsulate the object creation logic in a separate factory class, which is responsible for creating instances of different order types based on user inputs or other conditions.

Consider the following factors when designing your solution:

- The online food ordering system should support different types of food items, such as pizza, burger, sushi, etc.
- Each food type may have its own specific order class that implements the common order interface.
- The order creation logic should be abstracted away from the client code to make it flexible and easy to extend in the future.

My solution is in the `practice` folder.

### Breakdown

1. Let's say the types of food items that can be ordered are limited to just pizza, burger and sushi for now. Of course, once the system is up and running, more food items can be added. But for now, let's just focus on these three.
2. I need an abstract class (interface) that will be implemented by the three food items. This is the `Order` class.
3. By using the `Order` interface, I can then create three concrete classes that represents the three food items. These are the `PizzaOrder`, `BurgerOrder` and `SushiOrder` classes. Each of them should have their own implementation of the common methods.
4. I need a factory class that will be responsible for creating instances of the three food items. This is the `OrderCreator` class.
5. The `OrderCreator` interface will then create concrete factory classes that will be responsible for creating instances of the three food items. These are the `PizzaOrderCreator`, `BurgerOrderCreator` and `SushiOrderCreator` classes.
6. In the client code, I can then create instances of the three food items by using the `OrderCreator` interface.
