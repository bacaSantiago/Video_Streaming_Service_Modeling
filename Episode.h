#pragma once
#ifndef EPISODE_H
#define EPISODE_H

#include <string>
#include <iostream>
using namespace std;

class Episode
{
private:
    string title;
    int episode;
    int season; 
    double episodeRating;
    int episodeVoters;

public:
    // Constructors
    Episode();
    Episode(string _title, int _episode, int _season, double _episodeRating, int _episodeVoters);

    // Setters and Getters
    string getTitle();
    int getSeason();
    double getEpisodeRating();
    int getEpisodeVoters();

    // Methods
    void display();
    
};

#endif