#pragma once

#include <cstring>
#include <iostream>

using namespace std;

class Song{
	public:
//Constructor and Destructor
	Song();
	Song(char* name, int min, int sec, int views, int likes);
	~Song();

//Accessor
	char* get_song_name();
	//char* get_duration();
	int get_views();
	int get_likes();
	Song* get_next_song();

//Mutator
	void edit_views(int views);
	void edit_likes(int likes);
	//void set_duration();
	void set_next_song(Song* next);
	void out();
private:
	char* song_name;
	//char* duration;
	int song_min;
	int song_sec;
	int song_views;
	int song_likes;
	Song* next_song;
};
	
