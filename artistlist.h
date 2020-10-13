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

//Accessor
	Artist* get_artist();

//Mutator
	void set_artist(Artist* name);
	void add_artist();
	void add_songlist(char* parm);
	void artist_init(ifstream& input_file);
//FIXME: ADD PRINT ARTIST LIST, COMMANDS

//Ostream
	void print_artistlist();
	void print_songlist(char* parm);
	
//Misc
	char* get_line(ifstream& input);
	char* strbuild();
	private:
	Artist* head;

};
