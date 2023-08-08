#include "Episode.h"

Episode::Episode()
{
    title = "n/a";
    episode = 0;
    season = 0;
    episodeRating = 0.0;
    episodeVoters = 0;
}

Episode::Episode(string _title, int _episode, int _season, double _episodeRating, int _episodeVoters)
{
    title = _title;
    episode = _episode;
    season = _season;
    episodeRating = _episodeRating;
    episodeVoters = _episodeVoters;
}

string Episode::getTitle() {
    return title;
}

int Episode::getSeason() {
    return season;
}

double Episode::getEpisodeRating() {
    return episodeRating;
}

int Episode::getEpisodeVoters() {
    return episodeVoters;
}

void Episode::display() 
{
    cout << "Title: " << title << endl;
    cout << "Episode: " << episode << endl;
    cout << "Season: " << season << endl;
    cout << "Rating: " << episodeRating << endl;
    cout << "Voters: " << episodeVoters << endl;
}
