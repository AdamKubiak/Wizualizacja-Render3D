#ifndef QUADS_H
#define QUADS_H

#include <vector>
#include "objectorientation.h"



class Quads
{
public:
    Quads();
    void addQuad(ObjectOrientation obiekt);
    std::vector<std::vector<int>> quadVector;
    std::vector<std::vector<int>> colorVector;
    std::vector<int> empty;



    float r,g,b;
    int state;
    int total;
private:


};

#endif // QUADS_H
