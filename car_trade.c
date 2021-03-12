#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char maker[10];
    int price;
} Car;

typedef struct
{
    char name[10];
    int deposite;
    Car *car;
} Citizen;

void buy_car(Citizen *owner);
void discard_car(Citizen *owner);
void sell_car(Citizen *owner1, Citizen *other);

void buy_car(Citizen *owner)
{
    if (owner->car != NULL)
    {
        //still have an old car, discard it
        discard_car(owner);
    }

    //create an object
    Car *car = (Car *)malloc(sizeof(Car));
    strcpy(car->maker, "Ford");
    car->price = 10;

    //store the object
    owner->car = car;
    owner->deposite -= car->price;
    printf("%s bought a %s car. His deposit is %d \n", owner->name, owner->car->maker, owner->deposite);
}

void discard_car(Citizen *owner)
{
    if (owner->car != NULL)
    {
        char maker[10];
        strcpy(maker, owner->car->maker);

        free(owner->car);
        owner->car = NULL;

        printf("%s discard his %s car. now he has a  %s car. His deposit is %d \n", owner->name, maker, owner->car->maker, owner->deposite);
    }
    else
    {
        printf("Error! %s don't have a car currently!\n", owner->name);
    }
}

void sell_car(Citizen *owner1, Citizen *other)
{
    Car *car = owner1->car;

    car->price *= 0.5;
    other->car = car;

    other->deposite -= car->price;
    owner1->deposite += car->price;
    owner1->car = NULL; //cannot use free(owner1->car) because the memory is till using by other

    printf("%s sold his %s car to %s with $%d. \n", owner1->name, other->car->maker, other->name, car->price);
}

int main(void)
{
    Citizen Mike = {"Mike", 100, NULL};
    Citizen Bob = {"Bob", 90, NULL};

    buy_car(&Mike);

    sell_car(&Mike, &Bob);
    buy_car(&Bob);

    discard_car(&Mike);

    return 0;
}