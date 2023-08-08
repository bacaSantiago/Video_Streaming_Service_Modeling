#include "Movie.h"

Movie::Movie(string _ID, string _name, int _length, string _genre, double _rating, int _voters, string _type, string _format) : Video(_ID, _name, _length, _genre, _rating, _voters, _type)
{
    format = _format;
}

void Movie::display()
{
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Length: " << length << " minutes" << endl;
    cout << "Genre: " << genre << endl;
    cout << "Rating: " << rating << endl;
    cout << "Voters: " << voters << endl;
    cout << "Type: " << type << endl;
    cout << "Format: " << format << endl;
}