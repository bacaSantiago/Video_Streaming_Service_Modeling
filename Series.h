#pragma once
#ifndef SERIES_H
#define SERIES_H

#include "Video.h"
#include "Episode.h"
#include <vector>
using namespace std;

class Series : public Video
{
private:
    vector<Episode*> episodes;

public:
    // Constructors
    Series();
    Series(string _ID, string _name, int _length, string _genre, double _rating, int _voters, string _type);

    // Sobrecarga del operador '+='
	void operator += (Episode* episode) 
	{
        episodes.push_back(episode); 
	}

    // Setters and Getters
    vector<Episode*> getEpisodes();

    // Methods
    void display();
    void displayEpisodes();

};

#endif