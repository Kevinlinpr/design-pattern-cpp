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
        m_worker = new Worker;
    }
    ~CarBuilderFactory(){
        delete m_worker;
        m_worker = nullptr;
    }
    void introduceCarProducts(){
        m_worker->introduceNewCar();
    }
    void createNewCar(carBuilderType builderType){
        switch (builderType){
            case MITSUBISHI:
                m_worker->createNewCar(std::make_unique<MitsubishiCarBuilder>().release());
                break;
            case NISSAN:
                m_worker->createNewCar(std::make_unique<NissanCarBuilder>().release());
                break;
            case TOYOTA:
                m_worker->createNewCar(std::make_unique<ToyotaCarBuilder>().release());
                break;
            default:
                break;
        }
    }
private:
    Worker* m_worker;
};
