
#include <string>
#include <vector>
#include "Song.h"

class Album {
private:
    std::string title;
    std::vector<Song> songs;

public:
    // Constructor
    Album(const std::string& title, int size);

    void addSong(const Song& song);
    void removeSong(const std::string& title);
    void displayDetails() const;

    const std::string& getTitle() const;
};

