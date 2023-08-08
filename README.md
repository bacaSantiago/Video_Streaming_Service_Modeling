# C++ Video Streaming Service Modeling

## Introduction
This C++ program models a video modeling for a streaming service. The catalog contains two types of videos: movies and series. Each video has an ID, a name, a length, a genre, and a rating. Movies have an additional attribute called "format," while series have episodes, each with a title, season, and episode rating.

## Class Description

1. **Video**:
   - Base class for movies and series.
   - Attributes:
     - ID: string
     - name: string
     - length: int
     - genre: string
     - rating: double
     - voters: int
     - type: string (movie or series)
   - Methods:
     - Constructors: Default and Parameterized
     - Setters and Getters for attributes
     - `setRating(double _rating)`: Updates the video rating based on user ratings.

2. **Movie**:
   - Derived class from Video.
   - Attributes:
     - format: string (IMAX, Digital, etc.)
   - Methods:
     - Constructor: Parameterized
     - `display()`: Displays movie details, including format.

3. **Episode**:
   - Class representing an episode in a series.
   - Attributes:
     - title: string
     - episode: int
     - season: int
     - episodeRating: double
     - episodeVoters: int
   - Methods:
     - Constructors: Default and Parameterized
     - Setters and Getters for attributes
     - `display()`: Displays episode details.

4. **Series**:
   - Derived class from Video.
   - Attributes:
     - episodes: vector of Episode pointers
   - Methods:
     - Constructor: Parameterized
     - `operator+= (Episode* episode)`: Overloaded operator to add an episode to the series.
     - `getEpisodes()`: Returns the list of episodes.
     - `display()`: Displays series details and episodes.

5. **Catalog**:
   - Class to manage the collection of videos.
   - Attributes:
     - videos: vector of Video pointers
   - Methods:
     - Constructor: Default
     - `rateVideo()`: Asks users to rate a video and updates its rating.
     - `videosByRatingRange()`: Displays videos in a specific rating range.
     - `videosByGenre()`: Displays videos of a specific genre.
     - `episodesByRating()`: Displays episodes of a series in a specific rating range.
     - `moviesByRating()`: Displays movies in a specific rating range.
     - `loadDatabase(string filename)`: Loads video data from a CSV file.

## Usage

1. Create a new instance of the `Catalog` class to manage the video collection.
2. Load video information from a CSV file using the `loadDatabase()` method.
3. Use the following menu options to interact with the system:
   - **1:** Display videos (movies and series) within a specific rating range.
   - **2:** Show all videos (movies and series) from a specific genre.
   - **3:** Show episodes of a specific series within a rating range.
   - **4:** Show movies within a specific rating range.
   - **5:** Rate a video by providing its ID and your rating.
   - **0:** Exit the application.

## How to Run the Program

1. Make sure you have a C++ compiler installed on your system.
2. Compile the source code using the C++ compiler. For example:
   ```
   g++ main.cpp -o VSSM
   ```
3. Run the application:
   ```
   ./VSSM
   ```
   
## Object-Oriented Programming Concepts Used
1. **Class and Object:** The program utilizes classes to model different types of videos, episodes, and the catalog. Objects of these classes are created to represent specific instances of videos and their related information.

2. **Inheritance:** The classes `Movie` and `Series` inherit from the base class `Video`. This allows them to inherit common attributes and methods from the base class, promoting code reusability.

3. **Composition:** The class `Series` is an example of composition, where it contains a vector of `Episode` pointers to represent the episodes within a series.

4. **Encapsulation:** Private member variables are used within classes to encapsulate data and control access. Public methods are provided to interact with and manipulate these variables in a controlled manner.

5. **Polymorphism:** The base class `Video` defines an abstract method `display()`, which is overridden by the derived classes `Movie` and `Series`. This allows different video types to display their information in a customized way.

6. **Operator Overloading:** The `Series` class overloads the `+=` operator to add episodes to a series. This provides a convenient way to add episodes to a series object.

7. **Exception Handling:** The program uses exception handling to catch and handle errors. For example, when reading user inputs for ratings and IDs, the program uses try-catch blocks to validate and handle invalid inputs.

## Note
- The video information should be provided in a CSV file named "MoviesAndSeries.csv".
- The CSV file must have the following columns: ID, Name, Length, Genre, Rating, Voters, Type, and Format (for movies) or Episode, Title, Season, EpisodeRating, and EpisodeVoters (for series).
- The video ratings in the CSV file should be on a scale of 1 to 10 (where 10 is the best) to be converted to the scale of 1 to 5 internally in the application.
