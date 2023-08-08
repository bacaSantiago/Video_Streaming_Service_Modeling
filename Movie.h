#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include "Video.h"
#include <iostream>
using namespace std;

class Movie : public Video
{
private:
    string format;

public:
    // Constructors
    Movie(string _ID, string _name, int _length, string _genre, double _rating, int _voters, string _type, string _format);

    // Methods
    void display();
};

#endif