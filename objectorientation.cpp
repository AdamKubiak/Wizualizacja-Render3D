#include "objectorientation.h"

ObjectOrientation Transform;

void  ObjectOrientation::set_xTran(double _xTran)
{
    int current = xTran;
    if(_xTran>= MIN_POSITION && _xTran<=MAX_POSITION )
    {
        xTran = _xTran;
    }
    else
    {
        xTran = current;
    }
}


void  ObjectOrientation::set_yTran(double _yTran)
{
    int current = yTran;
    if(_yTran>= -10 && _yTran<=10 )
    {
        yTran = _yTran;
    }
    else
    {
        yTran = current;
    }

}

void  ObjectOrientation::set_zTran(double _zTran)
{
    int current = zTran;
    if(_zTran>= MIN_POSITION && _zTran<=MAX_POSITION )
    {
        zTran = _zTran;
    }
    else
    {
        zTran = current;
    }
}
