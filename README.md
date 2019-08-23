# design-pattern-cpp
## Builder
```C++
//example about the car
#include <iostream>
#include <memory>

class Car{
public:
    void setHeadLightBrand(const std::string& brand){
        m_headlight_brand = brand;
    }
    void setBumperBrand(const std::string& brand){
        m_bumper_brand = brand;
    }
    void setTireBrand(const std::string& brand){
        m_tire_brand = brand;
    }
    void setHoodBrand(const std::string& brand){
        m_hood_brand = brand;
    }
    void setWindShieldBrand(const std::string& brand){
        m_wind_shield = brand;
    }
    void manual() const {
        std::cout<<"=== The Car's Brand Manual ==="<<std::endl;
        std::cout<<"Head Light: "<<m_headlight_brand<<std::endl;
        std::cout<<"Bumper: "<<m_bumper_brand<<std::endl;
        std::cout<<"Tire: "<<m_tire_brand<<std::endl;
        std::cout<<"Hood: "<<m_hood_brand<<std::endl;
        std::cout<<"Wind Shield: "<<m_wind_shield<<std::endl;
        std::cout<<"=============================="<<std::endl;
    }
private:
    std::string m_headlight_brand,m_bumper_brand,m_tire_brand,m_hood_brand,m_wind_shield;
};

class CarBuilder{
public:
    virtual ~CarBuilder() = default;
    virtual void buildHeadLight()=0;
    virtual void buildBumper()=0;
    virtual void buildTire()=0;
    virtual void buildHood()=0;
    virtual void buildWindShield()=0;
    void createNewCar(){
        m_car = std::make_unique<Car>();
    }
    Car* getCar(){
        return m_car.release();
    }

protected:
    std::unique_ptr<Car> m_car;
};

class MitsubishiCarBuilder:public CarBuilder{
public:
    MitsubishiCarBuilder():brand("Mitsubishi"){};
    ~MitsubishiCarBuilder() override = default;
    void buildHeadLight() override {
        m_car->setHeadLightBrand(brand);
    }
    void buildBumper() override {
        m_car->setBumperBrand(brand);
    }
    void buildTire() override {
        m_car->setTireBrand(brand);
    }
    void buildHood() override {
        m_car->setHoodBrand(brand);
    }
    void buildWindShield() override {
        m_car->setWindShieldBrand(brand);
    }
    std::string brand;
};

class NissanCarBuilder:public CarBuilder{
public:
    NissanCarBuilder():brand("Nissan"){};
    ~NissanCarBuilder() override = default;
    void buildHeadLight() override {
        m_car->setHeadLightBrand(brand);
    }
    void buildBumper() override {
        m_car->setBumperBrand(brand);
    }
    void buildTire() override {
        m_car->setTireBrand(brand);
    }
    void buildHood() override {
        m_car->setHoodBrand(brand);
    }
    void buildWindShield() override {
        m_car->setWindShieldBrand(brand);
    }
    std::string brand;
};

class ToyotaCarBuilder:public CarBuilder{
public:
    ToyotaCarBuilder():brand("Toyota"){};
    ~ToyotaCarBuilder() override = default;
    void buildHeadLight() override {
        m_car->setHeadLightBrand(brand);
    }
    void buildBumper() override {
        m_car->setBumperBrand(brand);
    }
    void buildTire() override {
        m_car->setTireBrand(brand);
    }
    void buildHood() override {
        m_car->setHoodBrand(brand);
    }
    void buildWindShield() override {
        m_car->setWindShieldBrand(brand);
    }
    std::string brand;
};

class Worker{
public:
    void introduceNewCar() const {
        carBuilder->getCar()->manual();
    }
    void createNewCar(CarBuilder* builder){
        carBuilder = builder;
        carBuilder->createNewCar();
        carBuilder->buildHeadLight();
        carBuilder->buildBumper();
        carBuilder->buildTire();
        carBuilder->buildHood();
        carBuilder->buildWindShield();
    }
private:
    CarBuilder* carBuilder;
};

int main(){
    Worker worker{};
    MitsubishiCarBuilder mitsubishiCarBuilder;
    worker.createNewCar(&mitsubishiCarBuilder);
    worker.introduceNewCar();

    NissanCarBuilder nissanCarBuilder;
    worker.createNewCar(&nissanCarBuilder);
    worker.introduceNewCar();

    ToyotaCarBuilder toyotaCarBuilder;
    worker.createNewCar(&toyotaCarBuilder);
    worker.introduceNewCar();
}

//console output
=== The Car's Brand Manual ===
Head Light: Mitsubishi
Bumper: Mitsubishi
Tire: Mitsubishi
Hood: Mitsubishi
Wind Shield: Mitsubishi
==============================
=== The Car's Brand Manual ===
Head Light: Nissan
Bumper: Nissan
Tire: Nissan
Hood: Nissan
Wind Shield: Nissan
==============================
=== The Car's Brand Manual ===
Head Light: Toyota
Bumper: Toyota
Tire: Toyota
Hood: Toyota
Wind Shield: Toyota
==============================
```
Another example from WIKIBOOKS,I have edited it into [latest c++ 17 standard](https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns)
```C++
//C++ 17 standard

#include <iostream>
#include <memory>

class Pizza{
public:
    void setDough(const std::string& dough){
        m_dough = dough;
    }
    void setSauce(const std::string& sauce){
        m_sauce = sauce;
    }
    void setTopping(const std::string& topping){
        m_topping = topping;
    }
    void open() const {
        std::cout<<"The Pizza have "<<
        m_dough<<" dough, "<<
        m_sauce<<" sauce, "<<
        m_topping<<" topping."<<
        std::endl;
    }
private:
    std::string m_dough;
    std::string m_sauce;
    std::string m_topping;
};

class PizzaBuilder{
public:
    virtual ~PizzaBuilder() = default;
    void createNewPizza(){
        m_pizza = std::make_unique<Pizza>();
    }
    Pizza* getPizza() {
        return m_pizza.release();
    }
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
protected:
    std::unique_ptr<Pizza> m_pizza;
};

class HawaiianPizzaBuilder:public PizzaBuilder{
public:
    ~HawaiianPizzaBuilder() override = default;
    void buildDough() override {
        m_pizza->setDough("Hawaiian dough");
    }
    void buildSauce() override {
        m_pizza->setSauce("Hawaiian sauce");
    }
    void buildTopping() override {
        m_pizza->setTopping("Hawaiian topping");
    }
};

class SpicyPizzaBuilder:public PizzaBuilder{
public:
    ~SpicyPizzaBuilder() override = default;
    void buildDough() override {
        m_pizza->setDough("Spicy dough");
    }
    void buildSauce() override {
        m_pizza->setSauce("Spicy sauce");
    }
    void buildTopping() override {
        m_pizza->setTopping("Spicy topping");
    }
};

class Cook{
public:
    void openPizza() const {
        m_pizzaBuilder->getPizza()->open();
    }
    void createPizza(PizzaBuilder* pizzaBuilder){
        m_pizzaBuilder = pizzaBuilder;
        m_pizzaBuilder->createNewPizza();
        m_pizzaBuilder->buildDough();
        m_pizzaBuilder->buildSauce();
        m_pizzaBuilder->buildTopping();
    }
private:
    PizzaBuilder* m_pizzaBuilder;
};

int main(){
    Cook cook{};
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    cook.createPizza(&hawaiianPizzaBuilder);
    cook.openPizza();

    SpicyPizzaBuilder spicyPizzaBuilder;
    cook.createPizza(&spicyPizzaBuilder);
    cook.openPizza();
}

//console output
//The Pizza have Hawaiian dough dough, Hawaiian sauce sauce, Hawaiian topping topping.
//The Pizza have Spicy dough dough, Spicy sauce sauce, Spicy topping topping.
```
