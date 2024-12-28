#include "PoseHandler.hpp"
PoseHandler::PoseHandler(){pose={0,0,'N'};}
PoseHandler::PoseHandler(const Pose&pose):pose(pose){}
Pose PoseHandler::Query()const
{
    return pose;
}
void PoseHandler::Move()
{
            switch(pose.heading)
        {
            case 'N':
            {
                pose.y+=1;
                break;
            }
            case 'S':
            {
                pose.y-=1;
                break;
            }
            case 'W':
            {
                pose.x-=1;
                break;
            }
            case 'E':
            {
                pose.x+=1;
                break;
            }
            default:
            break;
        }
        return;
}
void PoseHandler::Backward()
{
     switch(pose.heading)
        {
            case 'N':
            {
                pose.y-=1;
                break;
            }
            case 'S':
            {
                pose.y+=1;
                break;
            }
            case 'W':
            {
                pose.x+=1;
                break;
            }
            case 'E':
            {
                pose.x-=1;
                break;
            }
            default:
            break;
        }
        return;
}
    void PoseHandler::TurnLeft()
    {
        turnSequence[4]='E';
        pose.heading=turnSequence[(pose.heading+1)%8];
        return ;
    }
    void PoseHandler::TurnRight()
    {
        turnSequence[4]='S';
        pose.heading=turnSequence[(pose.heading-1)%8];
        return ;
    }
    void PoseHandler::Fast()
    {
        fast=!fast;
    }
     void PoseHandler::Back()
    {
        back=!back;
    }
    bool PoseHandler::IsFast () const
    {
        return fast;
    }
    bool PoseHandler::IsBack()const
    {
        return back;
    }