#include "movingcar.h"
#include <iostream>
#include <algorithm> // std::min
#include <cmath>
using namespace std;

const float pi=3.1415926;


MovingCar::MovingCar(int currentLaneCount)
{
    cout << "car constructor called w/lanecount" << endl;
    _currentDir=(rand()%4);
    _currentCarLane=rand()%currentLaneCount;
    _isTurning=0;

    //use these to test
    //_currentDir=RIGHT;
    //_currentCarLane=2;

    vel = 1.0*((rand()%7) + 3);
    //vel=10;
    // create the first car...
    Car c;

    switch(_currentDir)
    {
    //sets the car in the far right...
    //this car is starting to move toward the left direction
    case LEFT:
        c.setSize(sf::Vector2f(CAR_LENGTH, CAR_WIDTH));
        c.setOrigin(sf::Vector2f(CAR_LENGTH/2, CAR_WIDTH/2));
        c.setPosition(WIDTH-(CAR_LENGTH/2), (HEIGHT/2)-((CAR_WIDTH/2+2)+(16*_currentCarLane)));
        c.setFillColor(sf::Color::Magenta);
        break;
        //sets the car in the far bottom...
        //this car is starting to move in the upper direction
    case UP:
        c.setSize(sf::Vector2f(CAR_WIDTH,CAR_LENGTH));
        c.setOrigin(sf::Vector2f(CAR_WIDTH/2,CAR_LENGTH/2));
        c.setPosition((WIDTH/2)+((CAR_WIDTH/2)+2)+(16*_currentCarLane), HEIGHT-(CAR_LENGTH/2));
        c.setFillColor(sf::Color::Blue);
        break;
        //sets the car in the far left...
        //this car is starting to move toward the right direction
    case RIGHT:
        c.setSize(sf::Vector2f(CAR_LENGTH, CAR_WIDTH));
        c.setOrigin(sf::Vector2f(CAR_LENGTH/2, CAR_WIDTH/2));
        c.setPosition(0+(CAR_LENGTH/2), (HEIGHT/2)+((CAR_WIDTH/2+2)+(16*_currentCarLane)));
        c.setFillColor(sf::Color::Red);
        break;
        //sets the car at the top...
        //this car is tarting to move in the bottom direction
    case DOWN:
        c.setSize(sf::Vector2f(CAR_WIDTH,CAR_LENGTH));
        c.setOrigin(sf::Vector2f(CAR_WIDTH/2,CAR_LENGTH/2));
        c.setPosition((WIDTH/2)-(((CAR_WIDTH/2)+2)+(16*_currentCarLane)), 0+(CAR_LENGTH/2));
        c.setFillColor(sf::Color::Cyan);
        break;
    }
    projections.push_back(c);
    init_projections();
}

void MovingCar::init_projections()
{
    for(unsigned int i=0; i<5; i++)
    {
        projections.push_back(addProjection());
    }
}


Car MovingCar::addProjection()
{
    Car last = projections.back();
    switch(_currentDir)
    {
    case LEFT:
        last.move(-1*vel,0);
        break;
    case UP:
        last.move(0,-1*vel);
        break;
    case RIGHT:
        last.move(vel,0);
        break;
    case DOWN:
        last.move(0,vel);
        break;
    }
    return last;
}

// check if 2 moving cars will intersect at any time.
int MovingCar::intersects(const MovingCar &other)
{
    int pos_to_check = std::min(projections.size(), other.projections.size());
    for(int i = 0; i < pos_to_check; i++)
    {
        sf::FloatRect box = projections[i].getGlobalBounds();
        if(box.intersects(other.projections[i].getGlobalBounds()))
            return i;
    }
    return -1;
}

// check if 2 moving cars will intersect each other at a given time pos.
bool MovingCar::intersects(const MovingCar &other, unsigned int pos)
{
    if(pos <= projections.size() && pos <= other.projections.size())
    {
        sf::FloatRect box = projections[pos].getGlobalBounds();
        if(box.intersects(other.projections[pos].getGlobalBounds()))
        {
            return true;
        }
    }
    return false;
}

void MovingCar::moveCarStraight()
{
    projections.push_back(addProjection());

}

void MovingCar::moveCarRight()
{
    projections.pop_front();
}


void MovingCar::getRightProjections(){
    Car temp=projections[0];
    projections.clear();
    projections.push_back(temp);
    int pix=0;
    for(int i=0;i<5; i++){

        pix+=10;
        projections.push_back(CarTurnRight(3, pix));

    }
}
void MovingCar::moveCar(){
    projections.pop_front();
}

Car MovingCar::CarTurnRight(int totalLaneCount,float pix )
{
    int currentCarPosx,currentCarPosy;
    int futureCarPosx,futureCarPosy;
    int circlePosx,circlePosy,radius;
    float rotatePosx,rotatePosy,rotateangle;
    Car temp=projections[0];


    if(_currentDir==UP)//current direction is UP
    {
        currentCarPosx=(WIDTH/2)+(ROAD_SIZE*(totalLaneCount-1))+3+5;//3 is (lane size-car width size)/2 ; 5 is half width size of car
        currentCarPosy=(HEIGHT/2)+(ROAD_SIZE*(totalLaneCount))+16+8;//16 is the distance between cross_street and the place car stop ;8 is half height size of car
        futureCarPosx=(WIDTH/2)+(ROAD_SIZE*(totalLaneCount))+16+8;
        futureCarPosy=(HEIGHT/2)+(ROAD_SIZE*(totalLaneCount-1))+3+5;
        circlePosx=futureCarPosx;
        circlePosy=currentCarPosy;
        radius=circlePosy-futureCarPosy;
        rotateangle=90/(2*radius*pi/4)*pix;
        rotatePosx=circlePosx-(cos(rotateangle*pi/180)*radius);
        rotatePosy=circlePosy-(sin(rotateangle*pi/180)*radius);

        temp.setPosition(rotatePosx,rotatePosy);
        temp.setRotation(rotateangle);

        //_currentDir='C';
    }
    else if(_currentDir==DOWN)//current direction is DOWN
    {
        currentCarPosx=(WIDTH/2)-(ROAD_SIZE*(totalLaneCount-1))-3-5;
        currentCarPosy=(HEIGHT/2)-(ROAD_SIZE*(totalLaneCount))-16-8;
        futureCarPosx=(WIDTH/2)-(ROAD_SIZE*(totalLaneCount))-16-8;
        futureCarPosy=(HEIGHT/2)-(ROAD_SIZE*(totalLaneCount-1))-3-5;
        circlePosx=futureCarPosx;
        circlePosy=currentCarPosy;
        radius=futureCarPosy-circlePosy;
        rotateangle=90/(2*radius*pi/4)*pix;
        rotatePosx=circlePosx+(cos(rotateangle*pi/180)*radius);
        rotatePosy=circlePosy+(sin(rotateangle*pi/180)*radius);

        temp.setPosition(rotatePosx,rotatePosy);
        temp.setRotation(rotateangle);
        //_currentDir='A';

    }
    else if(_currentDir==LEFT)//cuurent direction is LEFT
    {
        futureCarPosx=(WIDTH/2)+(ROAD_SIZE*(totalLaneCount-1))+3+5;
        futureCarPosy=(HEIGHT/2)-(ROAD_SIZE*(totalLaneCount))-16-8;
        currentCarPosx=(WIDTH/2)+(ROAD_SIZE*(totalLaneCount))+16+8;
        currentCarPosy=(HEIGHT/2)-(ROAD_SIZE*(totalLaneCount-1))-3-5;
        circlePosx=currentCarPosx;
        circlePosy=futureCarPosy;
        radius=circlePosx-futureCarPosx;
        rotateangle=90/(2*radius*pi/4)*pix;
        rotatePosx=circlePosx-(sin(rotateangle*pi/180)*radius);
        rotatePosy=circlePosy+(cos(rotateangle*pi/180)*radius);
        temp.setPosition(rotatePosx,rotatePosy);
        temp.setRotation(rotateangle);

        //_currentDir='B';
    }
    else if(_currentDir==RIGHT)//current direction is RIGHT
    {
        futureCarPosx=(WIDTH/2)-(ROAD_SIZE*(totalLaneCount-1))-3-5;
        futureCarPosy=(HEIGHT/2)+(ROAD_SIZE*(totalLaneCount))+16+8;
        currentCarPosx=(WIDTH/2)-(ROAD_SIZE*(totalLaneCount))-16-8;
        currentCarPosy=(HEIGHT/2)+(ROAD_SIZE*(totalLaneCount-1))+3+5;
        circlePosx=currentCarPosx;
        circlePosy=futureCarPosy;
        radius=futureCarPosx-circlePosx;
        rotateangle=90/(2*radius*pi/4)*pix;
        rotatePosx=circlePosx+(sin(rotateangle*pi/180)*radius);
        rotatePosy=circlePosy-(cos(rotateangle*pi/180)*radius);
        temp.setPosition(rotatePosx,rotatePosy);
        temp.setRotation(rotateangle);
        // _currentDir='D';

    }

    return temp;

}
bool MovingCar::isTheCarTurning(){
    return _isTurning==1;
}

void MovingCar::hasTheCarFinishedTurning(){
    if((_isTurning==1)&&projections.size()==1){
        switch(_currentCarLane){
        case 2:
            switch(_currentDir){
            case UP:
                _currentDir=RIGHT;
                break;
            case LEFT:
                _currentDir=UP;
                break;
            case RIGHT:
                _currentDir=DOWN;
                break;
            case DOWN:
                _currentDir=LEFT;
                break;

            }


            break;
        }
        for(int i=0; i<2; i++){
            projections.push_back(addProjection());
        }
        _isTurning=0;
    }
}
void MovingCar::ReduceSpeedInSameLane(MovingCar &other){
    if((_currentCarLane==other._currentCarLane)&&(_currentDir==other._currentDir)){
        if(vel>other.vel){
            vel=(other.vel);
        }
        else{
            other.vel=(vel);
        }
    }
}

bool MovingCar::hasCrossedIntersection(Intersection &inter){
    for(int i=0; i<4; i++){
        if(projections[0].getGlobalBounds().intersects(inter.controlled_perimeter[i].getGlobalBounds())){
            return true;
        }
    }
    return false;
}
