#include "Library.h"
// #include "Album.h"
// #include "Song.h"

#include<bits/stdc++.h>


int main() {
    Library myLibrary("My Music Library", 2);

    Album album1("Album 1", 2);
    album1.addSong(Song("Song 1", "Artist 1", 3.5));
    album1.addSong(Song("Song 2", "Artist 2", 4.2));

    Album album2("Album 2", 1);
    album2.addSong(Song("Song 3", "Artist 3", 2.8));

    myLibrary.addAlbum(album1);
    myLibrary.addAlbum(album2);

    myLibrary.displayDetails();

    myLibrary.removeAlbum("Album 1");
    std::cout << "\nAfter removing an album:\n";
    myLibrary.displayDetails();

    return 0;
}
