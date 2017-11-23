#ifndef ROAD_H
#define ROAD_H

#include <SFML/Graphics.hpp>

const int ROAD_SIZE=16;
const int WIDTH=800;
const int HEIGHT=600;

class Road
{
public:
    Road();

    Road(int laneCount);
    void init(int laneCount);

    ~Road();

    sf::RectangleShape* _horizontalRoad_A;//left
    sf::RectangleShape* _horizontalRoad_C;//right

    sf::RectangleShape* _verticalRoad_B;//up
    sf::RectangleShape* _verticalRoad_D;//down

    sf::RectangleShape _intersectionPlatform;
    int _totalLaneCount;

};

#endif // ROAD_H
