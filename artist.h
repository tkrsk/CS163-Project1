#pragma once

#include <cstring>
#include <iostream>

#include "songlist.h"

using namespace std;

class Artist{
	public:
//Constructor and Destructor
	Artist();
	Artist(char* name, char* news, char* desc);
	~Artist();

//Accessors
	char* get_name();
	char* get_news();
	char* get_desc();
	Artist* get_next_artist();
	SongList* get_songlist();

//Mutators
	void set_artist(Artist* parm);
	void set_news(Artist* parm);
	void set_desc(Artist* parm);
	void set_next_artist(Artist* next);

//Function to add new songs to songlist
	void add_song(char* name, int min, int sec, int views, int likes);

//Print Function
	void print_songs();

	private:
	char* artist_name;
	char* artist_news;
	char* artist_desc;
	SongList discog; //Short for discography
	Artist* next_artist;
};
