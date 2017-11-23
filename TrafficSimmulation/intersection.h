#ifndef INTERSECTION_H
#define INTERSECTION_H
#include <SFML/Graphics.hpp>
#include <list>


//enum direction {LEFT, UP, RIGHT, DOWN};

class Intersection
{
public:
    Intersection();
 //   sf::RectangleShape rectangle;
    //std::list<Car> carQueue;

//    void enQuene(Car &insertThis);
//    void deQuene();

    sf::RectangleShape controlled_perimeter[4];
//    sf::RectangleShape controlled_perimeterRIGHT;
//    sf::RectangleShape controlled_perimeterTOP;
    sf::RectangleShape cross_street;




};

#endif // INTERSECTION_H
