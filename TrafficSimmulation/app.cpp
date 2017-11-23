#include "app.h"
#include <time.h>
#include <cstdlib>
#include <iostream>


using namespace std;


App::App()
{
}

App::App(int laneCount):inter()
{
    _road.init(laneCount);
    itc.init(laneCount);
    srand(time(NULL));
    window.setFramerateLimit(20);
    Spawn();
}

void App::Spawn()
{
    MovingCar newMovingCar(3);
    for(list<MovingCar>::iterator it=unmanagedCars.begin();it!=unmanagedCars.end();++it)
    {
        if(newMovingCar.intersects((*it)) > -1)
        {
            cout << "CAN'T SPAWN!!!!" << endl;
            return;
        }
    }
    unmanagedCars.push_back(newMovingCar);
}

void App::Draw()
{
    // background
    window.clear(sf::Color::Green);

    //===============THIS DRAWS THE ROAD=============================
    for(int i=0; i<_road._totalLaneCount; i++){
        window.draw(_road._horizontalRoad_A[i]);
        window.draw(_road._horizontalRoad_C[i]);
        window.draw(_road._verticalRoad_B[i]);
        window.draw(_road._verticalRoad_D[i]);
    }

    window.draw(_road._intersectionPlatform);
    //this is so that the middle doesnt show a bunch of crosses...
    //if you dont understand, comment it out to see what happens if its not there


    //================ENDS DRAWING THE ROAD==========================

    for(list<MovingCar>::iterator it=unmanagedCars.begin();it!=unmanagedCars.end();++it)
    {
        window.draw((*it).projections.front());
    }

    //    for(int i=0; i<4; i++){
    //        window.draw(inter.controlled_perimeter[i]);
    //    }

    window.display();
}

void App::Step()
{
    // move
    for(list<MovingCar>::iterator it=unmanagedCars.begin();it!=unmanagedCars.end();++it)
    {

        int latest = (*it).projections.size()-1;

        if(!(*it).isTheCarTurning()){
            (*it).moveCarStraight();
        }




        if(((*it)._currentCarLane==2)&&(*it).hasCrossedIntersection(inter)
                &&(*it)._isTurning==0){
            //cout<<"how many times are we calling this"<<endl;
            (*it).getRightProjections();
            (*it)._isTurning++;

        }


        (*it).moveCar();

        (*it).hasTheCarFinishedTurning();

        for(list<MovingCar>::iterator b=unmanagedCars.begin(); b!=unmanagedCars.end();++b)
        {
            if(it != b)
            {
                int intersect_time = (*it).intersects(*b);
                if(intersect_time > -1)
                {
                    Car new_latest_pos = (*it).projections[intersect_time-1];
                    //cout << "we intersect @ time:" << intersect_time << endl;

                    (*it).ReduceSpeedInSameLane(*b);

                    for(int i = latest; i >= intersect_time; --i)
                    {
                        (*it).projections[i] = new_latest_pos;
                    }
                }
                /*
                if((*it).intersects(*b, latest))
                {
                    (*it).projections.pop_back();
                    (*it).projections.pop_back();
                    (*it).projections.push_back((*it).projections.back());
                    (*it).projections.push_back((*it).projections.back());
                }
                */
            }
        }





    }


    // checks
    for(list<MovingCar>::iterator it=unmanagedCars.begin();it!=unmanagedCars.end();++it)
    {
        // if car leaves screen, delete it
        sf::Vector2f pos = (*it).projections[0].getPosition();
        if(pos.x < 0 || pos.x > 800 || pos.y < 0 || pos.y > 600)
        {
            it = unmanagedCars.erase(it);
        }
    }
}

void App::Run()
{
    window.create(sf::VideoMode( 800, 600 ), "Window" );
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
                //                else if(event.key.code == sf::Keyboard::Return){
                //                    Spawn();
                //                }
                //                else if(event.key.code == sf::Keyboard::Space)
                //                {
                //                    Step();
                //                }
            }
        }
        if(unmanagedCars.size()<20){

            Spawn();

        }
        Step();
        Draw();
    }
}
