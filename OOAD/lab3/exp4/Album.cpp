// Album.cpp
// Album.cpp
#include "Album.h"
#include <bits/stdc++.h>

// Constructor
Album::Album(const std::string& title, int size) : title(title), songs(size, Song("", "", 0.0)) {}



void Album::addSong(const Song& song) {
    songs.push_back(song);
}

void Album::removeSong(const std::string& title) {
    auto it = std::remove_if(songs.begin(), songs.end(), [title](const Song& song) {
        return song.getTitle() == title;
    });
    songs.erase(it, songs.end());
}

void Album::displayDetails() const {
    std::cout << "Album Title: " << title << std::endl;
    std::cout << "Songs in the Album:" << std::endl;
    for (const auto& song : songs) {
        song.displayDetails();
    }
}

const std::string& Album::getTitle() const {
    return title;
}
