#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string director;
    int duration;

public:
    // Default constructor
    Movie() : title(""), director(""), duration(0) {}

    // Parameterized constructor
    Movie(string t, string d, int dur) : title(t), director(d), duration(dur) {}

    void display() const {
        cout << "Title: " << title << ", Director: " << director 
             << ", Duration: " << duration << " minutes" << endl;
    }
};

class CinemaHall {
private:
    static const int MAX_MOVIES = 10;
    Movie movies[MAX_MOVIES];
    int movieCount;

public:
    CinemaHall() : movieCount(0) {}

    void addMovie(const Movie& movie) {
        if (movieCount < MAX_MOVIES) {
            movies[movieCount] = movie;
            movieCount++;
        } else {
            cout << "Cannot add more movies. Cinema hall is full!" << endl;
        }
    }

    void display() const {
        cout << "Cinema Hall Details:" << endl;
        for (int i = 0; i < movieCount; i++) {
            movies[i].display();
        }
    }
};

int main() {
    CinemaHall hall;

    hall.addMovie(Movie("Inception", "Christopher Nolan", 148));
    hall.addMovie(Movie("The Dark Knight", "Christopher Nolan", 152));
    hall.addMovie(Movie("Interstellar", "Christopher Nolan", 169));

    hall.display();

    return 0;
}
