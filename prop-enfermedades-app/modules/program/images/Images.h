#ifndef IMAGES_H
#define IMAGES_H

#include <string>
#include <iostream>


using namespace std;


class Images
{
    public:
        Images();

        void GenerateBasicPlot(string DataRoute, string filename);
        void GeneratePanelesPlot(string DataRoute, string filename);
};


#endif