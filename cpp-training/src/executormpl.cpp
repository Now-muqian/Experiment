#include"executormpl.h"
#include<iostream>
#include<memory>

    Executormpl::Executormpl(){pose={0,0,'N'};}
    
    Executormpl::Executormpl(const Pose& pose):pose(pose){}

    void Executormpl::ExecuteOnce(char& command)
    {
        std::unique_ptr<ICommand> cmder;
        switch (command)
        {
        case 'M':
        {
       cmder=std::make_unique<MoveCommand>();
         break;
        }

        case 'L':
        {
       cmder=std::make_unique<TurnLeftCommand>();
        break; 
        }
        case 'R':
        {
        cmder=std::make_unique<TurnRightCommand>();
        break;
        }
        default:
            break;
       }
       if(cmder)
       {
        cmder->DoOperate(*this);
       }
        return;
    }
    void Executormpl::Execute(const std::string& commands)
    {
        for(char command : commands)
        {
            ExecuteOnce(command);
        }

        return;
    }
    Pose Executormpl::GetStatus() const 
  {
     
    return pose;
}

    
    void Executormpl::Move()
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
    void Executormpl::TurnLeft()
    {
        turnSequence[4]='E';
        pose.heading=turnSequence[(pose.heading+1)%8];
        return ;
    }
    void Executormpl::TurnRight()
    {
        turnSequence[4]='S';
        pose.heading=turnSequence[(pose.heading-1)%8];
        return ;
    }
    void Executormpl::Fast()
    {
        isFast=1-isFast;
    }