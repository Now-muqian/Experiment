#pragma once
#include "executor.hpp"

class PoseHandler final
{
    public:
    PoseHandler();
    PoseHandler(const Pose& pose);
    PoseHandler(const PoseHandler&)=delete;
    PoseHandler& operator=(const PoseHandler&)= delete;

    public:
    Pose Query() const ;
     void TurnLeft() ;
     void TurnRight() ;
     void Move() ;
     void Fast();
     void Back();
    bool IsFast() const;

    private:
    Pose pose;
    bool fast{false};
    char turnSequence[8]={'S',0,'W','S',0,'E','N','W'};
};