#include "CarFactory.cpp"

int main(){
    CarBuilderFactory carBuilderFactory;
    carBuilderFactory.worker
    ->createNewCar(carBuilderFactory.chooseCarBuilder(
            CarBuilderFactory::carBuilderType::MITSUBISHI).release());
    carBuilderFactory.worker->introduceNewCar();

    carBuilderFactory.worker
    ->createNewCar(carBuilderFactory.chooseCarBuilder(
            CarBuilderFactory::carBuilderType::NISSAN).release());
    carBuilderFactory.worker->introduceNewCar();

    carBuilderFactory.worker
    ->createNewCar(carBuilderFactory.chooseCarBuilder(
            CarBuilderFactory::carBuilderType::TOYOTA).release());
    carBuilderFactory.worker->introduceNewCar();
}