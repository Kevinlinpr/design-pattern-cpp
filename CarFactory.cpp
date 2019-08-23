//
// Created by Kevinlinpr on 2019-08-23.
//
#include "Car.cpp"
//now I want to decide which car Builder will be created at run time
class CarBuilderFactory{
public:
    enum carBuilderType{
        MITSUBISHI,
        NISSAN,
        TOYOTA
    };
    CarBuilderFactory(){
        worker = new Worker;
    }
    ~CarBuilderFactory(){
        delete worker;
        worker = nullptr;
    }
    std::unique_ptr<CarBuilder> chooseCarBuilder(carBuilderType builderType){
        switch (builderType){
            case MITSUBISHI:
                return std::make_unique<MitsubishiCarBuilder>();
            case NISSAN:
                return std::make_unique<NissanCarBuilder>();
            case TOYOTA:
                return std::make_unique<ToyotaCarBuilder>();
            default:
                return nullptr;
        }
    }
    Worker* worker;
};
