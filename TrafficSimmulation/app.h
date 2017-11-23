#ifndef App_H
#define App_H
#include <SFML/Graphics.hpp>
#include <list>
#include "InterTrafficCntrlr.h"
#include "movingcar.h"
#include "road.h"
#include "intersection.h"

class App
{
    public:
        App();
        App(int laneCount);
        void Spawn();
        void Draw();
        void Step();
        void Run();

        std::list<MovingCar> unmanagedCars;
        Road _road;
        InterTrafficCntrlr itc;
        Intersection inter;

    private:
        sf::RenderWindow window;
};
#endif // App_H
