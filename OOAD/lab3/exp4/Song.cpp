// Song.cpp
#include "Song.h"
#include <iostream>

// Constructor
Song::Song(const std::string& title, const std::string& artist, double duration)
    : title(title), artist(artist), duration(duration) {}

void Song::displayDetails() const {
    std::cout << "Title: " << title << ", Artist: " << artist << ", Duration: " << duration << " minutes" << std::endl;
}

const std::string& Song::getTitle() const {
    return title;
}
