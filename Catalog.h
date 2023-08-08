#pragma once
#ifndef CATALOG_H
#define CATALOG_H

#include "Movie.h"
#include "Series.h"
#include <fstream>
#include <sstream>
#include <set>
#include <iostream>  

class Catalog
{
private:
    vector<Video*> videos;

public:
    // Constructors
    Catalog();

    // Methods
    void rateVideo();
    void videosByRatingRange();
    void videosByGenre();
    void episodesByRating();
    void moviesByRating();
    void loadDatabase(string filename);
    
};

#endif