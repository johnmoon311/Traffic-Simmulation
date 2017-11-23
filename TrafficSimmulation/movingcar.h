#ifndef CAR_H
#define CAR_H
#include <SFML/Graphics.hpp>
#include "road.h"
#include "intersection.h"
#include "car.h"
#include <iostream>
#include <deque>

enum dir {LEFT, UP, RIGHT, DOWN};

class MovingCar
{
public:
    MovingCar(int currentLaneCount);

    void init_projections();
    void moveCarStraight();
    void moveCar();

    Car addProjection();

    int intersects(const MovingCar &other);
    bool intersects(const MovingCar &other, unsigned int pos);

    std::deque<Car> projections;

    void moveCarRight();
    void getRightProjections();
    Car CarTurnRight(int totalLaneCount,float pix );

    bool isTheCarTurning();
    void hasTheCarFinishedTurning();
    bool hasCrossedIntersection(Intersection &inter);

    void ReduceSpeedInSameLane(MovingCar &other);


    float vel;
    int _currentDir;//A:left; C:right; B:up; D:down
    int _currentCarLane;//this is the future direction as well, depending on what lane its in
    int _isTurning;
};

#endif
