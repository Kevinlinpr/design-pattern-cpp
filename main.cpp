#include "CarFactory.cpp"

int main(){
    CarBuilderFactory carBuilderFactory;
    carBuilderFactory.createNewCar(CarBuilderFactory::carBuilderType::MITSUBISHI);
    carBuilderFactory.introduceCarProducts();

    carBuilderFactory.createNewCar(CarBuilderFactory::carBuilderType::NISSAN);
    carBuilderFactory.introduceCarProducts();

    carBuilderFactory.createNewCar(CarBuilderFactory::carBuilderType::TOYOTA);
    carBuilderFactory.introduceCarProducts();
}