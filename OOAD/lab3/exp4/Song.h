

#include <string>

class Song {
private:
    std::string title;
    std::string artist;
    double duration;

public:
    // Constructor
    Song(const std::string& title, const std::string& artist, double duration);

    void displayDetails() const;

    // Getter for title
    const std::string& getTitle() const;
};




