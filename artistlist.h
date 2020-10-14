#pragma once

#include <cstring>
#include <iostream>
#include <fstream>

#include "artist.h"

using namespace std;

class ArtistList{
	public:
//Constructor and desctructor
	ArtistList();
	~ArtistList();

//Accessor for head node
	Artist* get_artist();

//Init functions to read in file data
	void artist_init(ifstream& artist_file);
	void songlist_init(ifstream& song_file);

//Function to change head node
	void set_artist(Artist* name);

//Function to add new artist
	void add_artist();

//Function to sort artist by alphabetical order
	void sort_artist(Artist* add);

//Function to add a song to an artist
	void add_songlist(char* parm);

//Print functions
	void print_artistlist();
	void print_songlist(char* parm);
	void print_info(char* parm);

//Misc functions to do string building
	char* get_line(ifstream& input);
	char* strbuild();

//Private data members
	private:
	Artist* head;

};
