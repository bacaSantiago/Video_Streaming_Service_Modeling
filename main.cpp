// Coder: Alejandro Santiago Baca Eyssautier

#include "Catalog.h"

Catalog* myCatalog;

void displayMenu(){
    int menuOption;

    cout << "\nWelcome dear cinephile. This program allows you to obtain information about your favorite movies and series!!" << endl;
    do{
        cout << "What do you want to do? \n\t1) Display the videos, either movie or series, in a specific rating range. \n\t2) See all the videos, either movie or series, from a specific genre \n\t3) Show the episodes of a certain series in a specific rating range. \n\t4) Exhibit all the movies in the database with a specific rating range. \n\t5) Rate a movie or series. \n\t0) Exit \n\nPlease, enter only the number of the option: ";
        cin >> menuOption; cout << endl;
        switch(menuOption){
            case 1: {
                myCatalog -> videosByRatingRange();
                break;
            }
            case 2: {
                myCatalog -> videosByGenre();
                break;
            }
            case 3: {
                myCatalog -> episodesByRating();
                break;
            }
            case 4: {
                myCatalog -> moviesByRating();
                break;
            }
            case 5: {
                myCatalog -> rateVideo();
                break;
            }
            case 0: {
                cout << "Thank you for using our services. Come back soon :)" << endl;
                break;
            }
            default: {
                cout << "Invalid input. Try again" << endl;
                break;
            }
        }
    }
    while (menuOption!=0);
}

int main() {
    // Create an instance of Catalog
    myCatalog = new Catalog();

    // Load the data base of the videos
    myCatalog -> loadDatabase("MoviesAndSeries.csv");
    
    displayMenu();
    return 0;
}