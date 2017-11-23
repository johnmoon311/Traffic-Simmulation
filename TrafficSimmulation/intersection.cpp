#include "intersection.h"
#include <iostream>
#include "movingcar.h"

using namespace std;
Intersection::Intersection()
{
    cross_street.setSize(sf::Vector2f(16,16));
    cross_street.setFillColor(sf::Color::Yellow);
    cross_street.setPosition(100,100);





    controlled_perimeter[UP].setSize(sf::Vector2f(136,.5));
    controlled_perimeter[UP].setOrigin(sf::Vector2f(68,.25));
    controlled_perimeter[UP].setFillColor(sf::Color::Transparent);
    controlled_perimeter[UP].setOutlineColor(sf::Color::Blue);
    controlled_perimeter[UP].setOutlineThickness(1);
    controlled_perimeter[UP].setPosition(400,240);

    controlled_perimeter[DOWN].setSize(sf::Vector2f(136,.5));
    controlled_perimeter[DOWN].setOrigin(sf::Vector2f(68,.25));
    controlled_perimeter[DOWN].setFillColor(sf::Color::Transparent);
    controlled_perimeter[DOWN].setOutlineColor(sf::Color::Blue);
    controlled_perimeter[DOWN].setOutlineThickness(1);
    controlled_perimeter[DOWN].setPosition(400,360);

    controlled_perimeter[RIGHT].setSize(sf::Vector2f(.5,136));
    controlled_perimeter[RIGHT].setOrigin(sf::Vector2f(.25,68));
    controlled_perimeter[RIGHT].setFillColor(sf::Color::Transparent);
    controlled_perimeter[RIGHT].setOutlineColor(sf::Color::Blue);
    controlled_perimeter[RIGHT].setOutlineThickness(1);
    controlled_perimeter[RIGHT].setPosition(460,300);

    controlled_perimeter[LEFT].setSize(sf::Vector2f(.5,136));
    controlled_perimeter[LEFT].setOrigin(sf::Vector2f(.25,68));
    controlled_perimeter[LEFT].setFillColor(sf::Color::Transparent);
    controlled_perimeter[LEFT].setOutlineColor(sf::Color::Blue);
    controlled_perimeter[LEFT].setOutlineThickness(1);
    controlled_perimeter[LEFT].setPosition(340,300);

    cout<<"I am intersection constructor"<<endl;


}


//void Intersection::enQuene(Car& insertThis)
//{
//    carQueue.push_back(insertThis);

//}
//void Intersection::deQuene()
//{
//    carQueue.pop_front();
//}
