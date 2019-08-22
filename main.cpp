#include "Builder.cpp"

int main(){
    Cook cook{};
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    cook.createPizza(&hawaiianPizzaBuilder);
    cook.openPizza();

    SpicyPizzaBuilder spicyPizzaBuilder;
    cook.createPizza(&spicyPizzaBuilder);
    cook.openPizza();
}