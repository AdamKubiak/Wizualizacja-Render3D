#ifndef OBJECTORIENTATION_H
#define OBJECTORIENTATION_H

#define MAX_POSITION 18
#define MIN_POSITION 0

class ObjectOrientation
{
    int xRot;
    int yRot;
    int zRot;
    int xTran;
    int yTran;
    int zTran;
public:
    ObjectOrientation(){xRot = yRot = zRot = 0;}

    void  set_xRot(double _xRot) {xRot = _xRot;}
    void  set_yRot(double _yRot) {yRot = _yRot;}
    void  set_zRot(double _zRot) {zRot = _zRot;}

    void  set_xTran(double _xTran);
    void  set_yTran(double _yTran);
    void  set_zTran(double _zTran);


    double  get_xRot() {return xRot;}
    double  get_yRot() {return yRot;}
    double  get_zRot() {return zRot;}

    double  get_xTran() {return xTran;}
    double  get_yTran() {return yTran;}
    double  get_zTran() {return zTran;}

};
extern ObjectOrientation Transform;
#endif // OBJECTORIENTATION_H
