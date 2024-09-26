

#include <string>
#include <vector>
#include "Album.h"

class Library {
private:
    std::string name;
    std::vector<Album> albums;

public:
    // Constructor
    Library(const std::string& name, int size);

    void addAlbum(const Album& album);
    void removeAlbum(const std::string& title);
    void displayDetails() const;

    const std::string& getName() const;
};

