// main.cpp
// Library.cpp
#include "Library.h"
#include <bits/stdc++.h>

// Constructor
Library::Library(const std::string& name, int size) : name(name), albums(size, Album("", 0)) {}


void Library::addAlbum(const Album& album) {
    albums.push_back(album);
}

void Library::removeAlbum(const std::string& title) {
    auto it = std::remove_if(albums.begin(), albums.end(), [title](const Album& album) {
        return album.getTitle() == title;
    });
    albums.erase(it, albums.end());
}

void Library::displayDetails() const {
    std::cout << "Library Name: " << name << std::endl;
    std::cout << "Albums in the Library:" << std::endl;
    for (const auto& album : albums) {
        album.displayDetails();
    }
}

const std::string& Library::getName() const {
    return name;
}

