#ifndef InterTrafficCntrlr_h
#define InterTrafficCntrlr_h
#include "movingcar.h"
#include "road.h"
#include <vector>
#include <list>

class InterTrafficCntrlr
{
    public:
    InterTrafficCntrlr(){};
    InterTrafficCntrlr(int laneCount)
    {
        init(laneCount);
    }
    void init(int laneCount)
    {
        ManagedZone.setFillColor(sf::Color::Transparent);
        ManagedZone.setSize(sf::Vector2f(16*(laneCount*2), 16*(laneCount*2)));
        ManagedZone.setPosition((WIDTH/2)-(16*laneCount),(HEIGHT/2)-(16*(laneCount)));
        ManagedZone.setOutlineColor(sf::Color::White);
        ManagedZone.setOutlineThickness(3);
    }
    void step()
    {
    }
    void move()
    {
    }
    void check()
    {
    }
    sf::RectangleShape ManagedZone;
    std::vector<sf::Drawable> drawables;

    std::list<MovingCar> projected_to_stop;
    std::list<MovingCar> row_list;
    std::list<MovingCar> post_inter;
    std::list<MovingCar> stopped_queue;
};

#endif
