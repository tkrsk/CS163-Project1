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

//SONG INSERTION FUNCTION
	void insert_song(char* input, int min, int sec, int views, int likes);

//FUNCTION TO SEARCH FOR SONG TO EDIT VIEWS AND LIKES
	void edit(char* parm);

//FUNCTION TO REMOVE SONGS WITH LESS THAN x LIKES
	void remove_song(int likes);

//MUTATOR FOR CHANGING HEAD TO REORDER LL	
	void set_first_song(Song* new_head);

//Print 
	void print(Song* parm);

	private:
	Song* first_song; //Head Song Node
};
