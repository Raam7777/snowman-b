#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel{
    
    string hat[4]={" _===_\n","  ___\n .....\n","   _\n  /_\\\n", "  ___\n (_*_)\n"};
    string nose[4]={",",".","_", " "};
    string leftEye[4] ={"(.","(o","(O","(-"};
    string rightEye[4] ={".)","o)","O)","-)"};
    string leftArm[4] ={"<","\\","/"," "};
    string rightArm[4] ={">\n","/\n","\\\n","\n"};
    string torso[4]={"( : )","(] [)","(> <)","(   )"};
    string base[4]={" ( : )"," (\" \")"," (___)"," (   )"};
    bool rightArmUp;
    bool leftArmUp;

    bool checkHand(int numberSnow)
    {
        rightArmUp=false;
        leftArmUp=false;
        //cheking is if hands up.
        if((numberSnow/100)%10==2)
        {
            rightArmUp=true;
        }
        if((numberSnow/1000)%10==2)
        {
            leftArmUp=true;
        }
        return false;
    }
    
    void checkNumber(int numberSnow)
    {
        int checkInput=numberSnow;
        
        //check if the input is valid
        if(checkInput<0)
        {
            throw string ("The number cannot be a minus");
        }
        for(int i=0;i<8;i++)
        {
            if(checkInput%10>4||checkInput%10<1)
            {
                throw string ("The number does not exist");
            }
            checkInput=checkInput/10;
        }
        if(checkInput!=0)
        {
            throw string ("There are more than 8 numbers");
        }
    }

    string snowman(int numberSnow)
    {
        
        checkNumber(numberSnow);
        checkHand(numberSnow);
        
        //build the snowman.
        string s="";
        
        //build the hat.
        s=s+hat[(numberSnow/10000000)-1];
        
        //build the left arm up.
        
        if(leftArmUp)
        {
            s=s+leftArm[1];
        }
        else{
            s=s+" ";
        }
        
        //build the eyes and nose.
        s=s+leftEye[((numberSnow/100000)%10)-1];
        
        s=s+nose[((numberSnow/1000000)%10)-1];
        
        s=s+rightEye[((numberSnow/10000)%10)-1];
        
        //build the right arm up.
        if(rightArmUp)
        {
            s=s+rightArm[1];
        }
        else{
            s=s+"\n";
        }
        
        //build the left arm down.
        if(!leftArmUp)
        {
            s=s+leftArm[((numberSnow/1000)%10)-1];
        }
        else{  //add space before the torso
            s=s+" ";
        }
        
        //build the torso.
        s=s+torso[((numberSnow/10)%10)-1];
        
        //build the right arm down.
        if(!rightArmUp)
        {
            s=s+rightArm[((numberSnow/100)%10)-1];
        }
        else
        {
            s=s+"\n";
        }
        
        //build the base.
        s=s+base[(numberSnow%10)-1];
        
        return s;
    }
}