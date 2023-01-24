#ifndef IMAGES_H
#define IMAGES_H

#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../../methods/models/Models.h"


using namespace std;


class Images
{
    public:
        Images();

        void GenerateBasicPlot(string DataRoute, string filename);
        void GeneratePanelesPlot(string DataRoute, string filename);
        void GeneratePhasePlot(string DataRoute, string filename);
        void GererateBasicGif(Model * model, string projectRoute, int size, double startTime, double maxTime, double maxPopulation);
        void GereratePhaseGif(Model * model, string projectRoute, int size, double startTime, double maxTime, double maxPopulation);
};


#endif