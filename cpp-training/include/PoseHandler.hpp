#pragma once
#include "executor.hpp"
enum Cartype
{
    Car=0,
    SportsCar=1,
    Bus=2
};

class PoseHandler final
{
    public:
    PoseHandler();
    PoseHandler(const Pose& pose,Cartype& type);
    PoseHandler(const PoseHandler&)=delete;
    PoseHandler& operator=(const PoseHandler&)= delete;

    public:
    Pose Query() const ;
     void TurnLeft() ;
     void TurnRight() ;
     void Move() ;
     void Backward();
     void Fast();
     void Back();
    bool IsFast() const;
    bool IsBack()const;
    Cartype QueryType() const;
    private:
    Pose pose;
    Cartype type;
    bool fast{false};
    bool back{false};
    char turnSequence[8]={'S',0,'W','S',0,'E','N','W'};
};