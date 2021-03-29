#include "quads.h"
#include "objectorientation.h"

Quads::Quads()
{
    this->state = 0;
    this->total = -1;
    this->empty.resize(12);
    //this->r = 1;
    //this->g = 1;
    //this->b = 1;

}

void Quads::addQuad(ObjectOrientation obiekt)
{
    std::vector<int> emptyColor;
    emptyColor.resize(3);

    if(this->state == 0)
    {
        quadVector.push_back(this->empty);
        colorVector.push_back(emptyColor);
    }


    this->state++;
    if(this->state>4){this->state = 1;quadVector.push_back(this->empty);colorVector.push_back(emptyColor);}
    int st = this->state;

    if(st == 1){this->total++;}
    if(st == 1)
    {
        this->quadVector[this->total][0]=(obiekt.get_xTran());
        this->quadVector[this->total][1]=(obiekt.get_yTran());
        this->quadVector[this->total][2]=(obiekt.get_zTran());
    }
    if(st == 1 || st == 2)
    {
        this->quadVector[this->total][3]=(obiekt.get_xTran());
        this->quadVector[this->total][4]=(obiekt.get_yTran());
        this->quadVector[this->total][5]=(obiekt.get_zTran());
    }
    if(st == 1 || st == 2|| st == 3)
    {
        this->quadVector[this->total][6]=(obiekt.get_xTran());
        this->quadVector[this->total][7]=(obiekt.get_yTran());
        this->quadVector[this->total][8]=(obiekt.get_zTran());
    }
    if(st == 1 || st == 2|| st == 3||st==4)
    {
        this->quadVector[this->total][9]=(obiekt.get_xTran());
        this->quadVector[this->total][10]=(obiekt.get_yTran());
        this->quadVector[this->total][11]=(obiekt.get_zTran());
    }

}
