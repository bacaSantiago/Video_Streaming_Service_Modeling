#include "Series.h"

Series::Series() : Video()
{

}

Series::Series(string _ID, string _name, int _length, string _genre, double _rating, int _voters, string _type) : Video(_ID, _name, _length, _genre, _rating, _voters, _type)
{

}

vector<Episode*> Series::getEpisodes(){
    return episodes;
}

void Series::display()
{
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Length: " << length << " minutes" << endl;
    cout << "Genre: " << genre << endl;
    cout << "Rating: " << rating << endl;
    cout << "Voters: " << voters << endl;
    cout << "Type: " << type << endl;
}

void Series::displayEpisodes(){
    cout << "Episodes:" << endl << endl;
    for (vector<Episode*>::iterator it = episodes.begin(); it != episodes.end(); ++it) {
        cout << endl;
        (*it)->display();
    }
}

