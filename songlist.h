#pragma once

#include <cstring>
#include <iostream>

#include "song.h"

using namespace std;

class SongList{
	public:
//Constructor and Deconstructor
	SongList();
	~SongList();

//Accessor
	Song* get_songlist();

//Mutator
	void insert_song(char* input, int min, int sec, int views, int likes);
	void remove_song(int likes);
	void set_first_song(Song* new_head);
//Print 
	void print(Song* parm);

	private:
	Song* first_song;
};
