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
     void Backward();
     void Fast();
     void Back();
    bool IsFast() const;
    bool IsBack()const;
    private:
    Pose pose;
    bool fast{false};
    bool back{false};
    char turnSequence[8]={'S',0,'W','S',0,'E','N','W'};
};