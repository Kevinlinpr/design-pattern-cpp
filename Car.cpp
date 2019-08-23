//
// Created by Kevinlinpr on 2019-08-23.
//
#include <string>
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

