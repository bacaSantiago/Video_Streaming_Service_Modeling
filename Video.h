#pragma once
#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class Video
{
protected:
    string ID;
    string name;
    int length; // int because it would be in minutes
    string genre;
    double rating;
    int voters;
    string type;

public:
    // Constructors
    Video();
    Video(string _ID, string _name, int _length, string _genre, double _rating, int _voters, string _type);

    // Setters and Getters
    string getID();
    string getName();
    string getGenre();
    double getRating();
    string getType();
    void setRating(double _rating);

    // Methods
    virtual void display() = 0;
};

#endif