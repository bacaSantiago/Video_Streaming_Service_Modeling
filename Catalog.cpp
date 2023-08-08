#include "Catalog.h"

Catalog::Catalog()
{

}

void Catalog::rateVideo(){
    int answerI;
    double answerD;

    // Display all the videos and movies
    cout << "These are the titles that you can rate: " << endl << endl;
    for (vector<Video*>::iterator it = videos.begin(); it != videos.end(); ++it) {
        (*it) -> display();
        cout << endl << endl;
    }

    // Ask for the ID of the video
    do
    {
        cout << "Please, enter the ID of the video: "; cin >> answerI;
        try {
            if (answerI <= 0 || answerI > videos.size()) throw "INVALID ID";
        } catch (...) {
            cout << "Invalid ID. Please try again" << endl;
        }
    } while (answerI <= 0 || answerI > videos.size());

    // Ask for the rating
    cout << "Now, enter your rating for that video. This rating is in the scale from 1 to 5." << endl;
    do
    {
        cout << "\n\t" << videos[answerI - 1] -> getName() << "\nRating: "; 
        cin >> answerD; 
        try {
            if (answerD < 1.0 || answerD > 5.00) throw "INVALID RATING";
        } catch (...) {
            cout << "Invalid rating, it must be from 1 to 5. Try again" << endl;
        }
    } while (answerD < 1.0 || answerD > 5.00);
    
    // Set that rating by multiplying the actual rating by the number of votes, suming it, sum 1 to 'voters', and divide again by voters, finally set it and display
    videos[answerI - 1] -> setRating(answerD);

    cout << "\nGreat! Thanks for your rating." << endl << endl;
}

void Catalog::videosByRatingRange(){
    double maxRating, minRating;

    // Ask for the range of the rating
    cout << "Fine, first enter the minimum and maximum rating of the videos you want to see. This rating is in the scale from 1 to 5." << endl;
    do
    {
        cout << "Minimum rating: "; cin >> minRating;
        cout << "Maximum rating: "; cin >> maxRating;
        try {
            if (minRating < 1.0 || minRating > 5.00 || maxRating < 1.0 || maxRating > 5.00) throw "INVALID RANGE";
        } catch (...) {
            cout << "Invalid range, it must be from 1 to 5. Try again" << endl;
        }
    } while (minRating < 1.0 || minRating > 5.00 || maxRating < 1.0 || maxRating > 5.00);

    bool searchFound = false; // Bool for no coindicences
    // Display the videos in the selected rating range
    cout << "Alright! These are the videos found in a rating from " << minRating << " to " << maxRating << ":" << endl << endl;
    for (vector<Video*>::iterator it = videos.begin(); it != videos.end(); ++it) {
        double videoRating = (*it) -> getRating(); 
        if (videoRating >= minRating && videoRating <= maxRating){
            (*it) -> display();
            cout << endl;
            searchFound = true; // A coincidence was found
        }        
    }

    // Case were not a single coincidence was found
    if (searchFound == false)
    {
        cout << "We're sorry, the search did not match any video in our database. Please try again." << endl << endl;
    }
}

void Catalog::videosByGenre(){
    string answerS;

    // Collect unique genres
    set<string> genres; // Use a 'set' list so that no genres are repeated
    for (vector<Video*>::iterator it = videos.begin(); it != videos.end(); ++it) {
        genres.insert((*it) -> getGenre());
    }

    // Display available genres
    cout << "These are the available genres in our data base: " << endl;
    for (set<string>::iterator it = genres.begin(); it != genres.end(); ++it) {
        cout << " - " << (*it) << endl;
    }

    // Ask user for genre selection
    cout << "\nChoose one of the genres shown above. Please, type it as shown: "; cin >> answerS; 
    answerS[0] = toupper(answerS[0]); // Convert first letter to capital to avoid errors ('Sci-Fi' error is not handled since it's more complex to do)

    // Display videos of the selected genre
    bool searchFound = false; // Bool for no coindicences
    cout << "Videos in the genre '" << answerS << ":" << endl;
    for (vector<Video*>::const_iterator it = videos.begin(); it != videos.end(); ++it) {
        if ((*it) -> getGenre() == answerS) {
            cout << endl;
            (*it) -> display();
            searchFound = true;
        }
    }

    // Case were not a single coincidence was found
    if (searchFound == false)
    {
        cout << "We're sorry, the search did not match any video in our database. Please try again." << endl << endl;
    }

    cout << endl << endl;
}

void Catalog::episodesByRating(){
    int answerI;
    double maxRating, minRating;

    // Display available sries
    cout << "Good! These are all the available series in the data base:" << endl << endl;
    for (vector<Video*>::iterator it = videos.begin(); it != videos.end(); ++it) {
        if ((*it) -> getType() == "Series"){
            (*it) -> display();
            cout << endl << endl;
        }
    }

    bool seriesCheck; // bool for checking if the ID corresponds to a series
    // Ask for the ID of the video
    do
    {
        seriesCheck = true; // starts at true every loop
        cout << "Please, enter the ID of the series: "; cin >> answerI;
        try {
            if (answerI <= 0 || answerI > videos.size()) throw "INVALID ID";
            else {
                if (videos[answerI - 1] -> getType() != "Series"){
                    seriesCheck = false;
                    throw "INVALID ID";
                }
            }
        } catch (...) {
            cout << "Invalid ID. Please try again" << endl;
        }
    } while (seriesCheck == false || answerI <= 0 || answerI > videos.size());

    // Ask for the range of the rating
    cout << "\nFine, now enter the minimum and maximum rating of the videos you want to see. This rating is in the scale from 1 to 5." << endl;
    do
    {
        cout << "Minimum rating: "; cin >> minRating;
        cout << "Maximum rating: "; cin >> maxRating;
        try {
            if (minRating < 1.0 || minRating > 5.00 || maxRating < 1.0 || maxRating > 5.00) throw "INVALID RANGE";
        } catch (...) {
            cout << "Invalid range, it must be from 1 to 5. Try again" << endl;
        }
    } while (minRating < 1.0 || minRating > 5.00 || maxRating < 1.0 || maxRating > 5.00);

    
    bool searchFound = false; // Bool for no coindicences

    // Get the current series and its episodes
    Series* currentSeries = dynamic_cast<Series*>(videos[answerI - 1]); // A conditional to check if it doesn't return a null pointer isn't used since we are making sure of it previously by the ID
    vector<Episode*> episodes = currentSeries -> getEpisodes();

    // Display the episodes in the selected rating range
    cout << "\nAlright! These are the episodes of the " << videos[answerI - 1] -> getName() << " series found in a rating from " << minRating << " to " << maxRating << ":" << endl << endl;
    for (vector<Episode*>::iterator it = episodes.begin(); it != episodes.end(); ++it) {
        double episodeRating = (*it) -> getEpisodeRating(); 
        if (episodeRating >= minRating && episodeRating <= maxRating) {
            (*it) -> display();
            cout << endl;
            searchFound = true; // A coincidence was found
        }        
    }

    // Case were not a single coincidence was found
    if (searchFound == false)
    {
        cout << "We're sorry, the search did not match any video in our database. Please try again." << endl << endl;
    }
}

void Catalog::moviesByRating(){
    double maxRating, minRating;

    // Ask for the range of the rating
    cout << "OK, first enter the minimum and maximum rating of the videos you want to see. This rating is in the scale from 1 to 5." << endl;
    do
    {
        cout << "Minimum rating: "; cin >> minRating;
        cout << "Maximum rating: "; cin >> maxRating;
        try {
            if (minRating < 1.0 || minRating > 5.00 || maxRating < 1.0 || maxRating > 5.00) throw "INVALID RANGE";
        } catch (...) {
            cout << "Invalid range, it must be from 1 to 5. Try again" << endl;
        }
    } while (minRating < 1.0 || minRating > 5.00 || maxRating < 1.0 || maxRating > 5.00);

    bool searchFound = false; // Bool for no coindicences
    // Display the movies in the selected rating range
    cout << "Alright! These are the movies found in a rating from " << minRating << " to " << maxRating << ":" << endl << endl;
    for (vector<Video*>::iterator it = videos.begin(); it != videos.end(); ++it) {
        double videoRating = (*it) -> getRating(); 
        if (videoRating >= minRating && videoRating <= maxRating && (*it) -> getType() == "Movie"){
            (*it) -> display();
            cout << endl;
            searchFound = true; // A coincidence was found
        }        
    }

    // Case were not a single coincidence was found
    if (searchFound == false)
    {
        cout << "We're sorry, the search did not match any video in our database. Please try again." << endl << endl;
    }
}

void Catalog::loadDatabase(string filename) {
    ifstream file(filename); // Data base with the info
    string line;

    // Skip the first line (headers)
    getline(file, line);

    // Loop to read each line from the CSV file
    while (getline(file, line)) {
        // Parse the CSV line by each comma ',' into a vector 'row' of type string that represents every column as an index
        vector<string> row;
        string item;
        istringstream lineStream(line); // treat the line as a collection of chars for stream extraction: parsing

        // Parse realized here when a ',' is reached and stored in 'item' for adding individually
        while (getline(lineStream, item, ',')) { 
            row.push_back(item); 
        }

        // Extract data from CSV row and transform it into desired type
        string ID = row[1]; // 1,2,3...
        string name = row[2]; // Title of the video
        int length = stoi(row[3]); // Duration in minutes
        string genre = row[4]; // Drama, action, comedy, etc.
        double rating = stod(row[5]) / 2; // Critic from 1 to 5
        int voters = stoi(row[6]); // Amount of critics
        string type = row[7]; // Movie or Series

        // Create appropriate video object based on the video type
        if (type == "Movie") {
            // Create a new Movie object and add it to the videos vector
            string format = row[8]; // IMAX, Digital
            videos.push_back(new Movie(ID, name, length, genre, rating, voters, type, format));
        } else if (type == "Series") {
            Series* currentSeries = nullptr;

            // Check if a Series with the same ID already exists in our collection of videos
            for (vector<Video*>::iterator it = videos.begin(); it != videos.end(); ++it) {
                Video* currentVideo = *it;
                // Check if the current video is a Series object using dynamic_cast, when true returns the pointer to it, when false returns a null pointer 'nullptr'
                currentSeries = dynamic_cast<Series*>(currentVideo);

                // When the current video can be cast to a Series object (is not a null pointer) and it`s ID is already ocupied it breaks the for loop
                if (currentSeries && currentSeries -> getID() == ID) { 
                    // Series with the same ID already exists
                    break;
                } else {
                    // Set current Series to nullptr to indicate that no existing series with the same ID was found.
                    currentSeries = nullptr;
                }
            }

            // If it is a null pointer, which means it has not yet been created, it is created and added to the videos vector
            if (!currentSeries) { 
                currentSeries = new Series(ID, name, length, genre, rating, voters, type);
                videos.push_back(currentSeries);
            }
            // When it is not a null pointer, which means it exists, then it keeps adding episodes to it

            // Extract episode attributes from the CSV line
            int episode = stoi(row[9]); // 1,2,3...
            string title = row[10]; // Title of the episode
            int season = stoi(row[11]); // 1,2,3...
            double episodeRating = stod(row[12]) / 2; // Critic from 1 to 5
            int episodeVoters = stoi(row[13]); // Amount of critics

            // Create a new Episode object
            Episode* episodeObj = new Episode(title, episode, season, episodeRating, episodeVoters);

            // Add the episode to the Series object
            *currentSeries += episodeObj;
            // We use the pointer to the object '*currentSeries' because without it should be: 'currentSeries -> operator+=(episodeObj);'
        }
    }

    file.close();
}