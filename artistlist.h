#pragma once

#include <cstring>
#include <iostream>

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
//FIXME: ADD PRINT ARTIST LIST, COMMANDS

//Ostream
	void print_artistlist();
	void print_songlist(char* parm);
	
//Misc
	char* strbuild();
	private:
	Artist* head;

};
