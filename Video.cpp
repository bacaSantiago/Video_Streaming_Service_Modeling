#include "Video.h"

// Default constructor
Video::Video()
{
    ID = "n/a";
    name = "n/a";
    length = 0;
    genre = "n/a";
    rating = 0.0;
    voters = 0;
    type = "n/a";
}

// Parametrized constructor
Video::Video(string _ID, string _name, int _length, string _genre, double _rating, int _voters, string _type)
{
    ID = _ID;
    name = _name;
    length = _length;
    genre = _genre;
    rating = _rating;
    voters = _voters;
    type = _type;
}

string Video::getID() {
    return ID;
}

string Video::getName(){
    return name;
}

string Video::getGenre(){
    return genre;
}

double Video::getRating(){
    return rating;
}

string Video::getType(){
    return type;
}

void Video::setRating(double _rating){
    int newVoters = voters + 1;
    // Multiply the actual video rating (which is an average) by the number of voters and sum the given rating
    rating = (rating * voters + _rating) / newVoters;
    voters = newVoters;
}
