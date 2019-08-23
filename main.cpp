#include "Car.cpp"

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