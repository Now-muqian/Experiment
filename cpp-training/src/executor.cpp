#include"executor.h"
#include<iostream>

    Executor::Executor():x(0),y(0),heading('N'){}
    Executor::Executor(int x,int y,char heading):x(x),y(y),heading(heading){}

    void Executor::Execute(char command)
    {
        switch (command)
        {
        case 'M':
        Move();
        break;
            
        case 'L':
        TurnLeft();
        break;
        
        case 'R':
        {
        TurnRight();  
        break;
        }
        default:
            break;
        }
        return;
    }
    void Executor::ExecuteCommands(std::string commands)
    {
        for(char command : commands)
        {
            Execute(command);
        }

        return;
    }
    std::string Executor::GetStatus() const 
{
     std::string status ='('+ std::to_string(x)+',' + std::to_string(y) +','+ heading+')';
    return status;
}

    
    void Executor::Move()
    {
        switch(heading)
        {
            case 'N':
            {
                y+=1;
                break;
            }
            case 'S':
            {
                y-=1;
                break;
            }
            case 'W':
            {
                x-=1;
                break;
            }
            case 'E':
            {
                x+=1;
                break;
            }
            default:
            break;
        }
        return;
    }
    void Executor::TurnLeft()
    {
        turnSequence[4]='E';
        heading=turnSequence[(heading+1)%8];
        return ;
    }
    void Executor::TurnRight()
    {
        turnSequence[4]='S';
        heading=turnSequence[(heading-1)%8];
        return ;
    }
