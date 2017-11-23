#include "road.h"

Road::Road()
{
}

Road::Road(int laneCount)
{
    init(laneCount);
}


//intitializes the road
void Road::init(int laneCount){
    _totalLaneCount=laneCount;

    _horizontalRoad_A=new sf::RectangleShape[_totalLaneCount];
    _horizontalRoad_C=new sf::RectangleShape[_totalLaneCount];
    _verticalRoad_B=new sf::RectangleShape[_totalLaneCount];
    _verticalRoad_D=new sf::RectangleShape[_totalLaneCount];



    //this is for the middle block..
    //makes it so that there arent a bunch of lines crossing in the intercetion
    _intersectionPlatform.setSize(sf::Vector2f(16*(laneCount*2), 16*(laneCount*2)));
    _intersectionPlatform.setPosition((WIDTH/2)-(16*laneCount),(HEIGHT/2)-(16*(laneCount)));
    _intersectionPlatform.setFillColor(sf::Color::Black);
    _intersectionPlatform.setOutlineColor(sf::Color::White);
    _intersectionPlatform.setOutlineThickness(3);

    for(int i=0; i<_totalLaneCount; i++){
        _horizontalRoad_A[i].setFillColor(sf::Color::Black);
        _horizontalRoad_A[i].setOutlineColor(sf::Color::Yellow);
        _horizontalRoad_A[i].setSize(sf::Vector2f(WIDTH,16));
        _horizontalRoad_A[i].setPosition(0, (HEIGHT/2)-((16)*(i+1)));
        _horizontalRoad_A[i].setOutlineThickness(1);


        _horizontalRoad_C[i].setFillColor(sf::Color::Black);
        _horizontalRoad_C[i].setOutlineColor(sf::Color::Yellow);
        _horizontalRoad_C[i].setSize(sf::Vector2f(WIDTH,16));
        _horizontalRoad_C[i].setPosition(0, (HEIGHT/2)+((16)*(i)));
        _horizontalRoad_C[i].setOutlineThickness(1);


        _verticalRoad_B[i].setFillColor(sf::Color::Black);
        _verticalRoad_B[i].setOutlineColor(sf::Color::Yellow);
        _verticalRoad_B[i].setSize(sf::Vector2f(16, HEIGHT));
        _verticalRoad_B[i].setPosition((WIDTH/2)+((16)*(i)), 0);
        _verticalRoad_B[i].setOutlineThickness(1);


        _verticalRoad_D[i].setFillColor(sf::Color::Black);
        _verticalRoad_D[i].setOutlineColor(sf::Color::Yellow);
        _verticalRoad_D[i].setSize(sf::Vector2f(16, HEIGHT));
        _verticalRoad_D[i].setPosition((WIDTH/2)-((16)*(i+1)), 0);
        _verticalRoad_D[i].setOutlineThickness(1);
    }
}

Road::~Road(){
    delete[] _horizontalRoad_A;
    delete[] _horizontalRoad_C;
    delete[] _verticalRoad_B;
    delete[] _verticalRoad_D;
}
