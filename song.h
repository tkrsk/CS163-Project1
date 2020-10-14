//TAKA MASAGATANI
//CS260
//FALL2020
//PROJECT #1
//Header for Song Node
//song.h

#pragma once

#include <cstring>
#include <iostream>

using namespace std;

class Song{
	public:
//Constructors and Destructor
	Song();
	Song(char* name, int min, int sec, int views, int likes);
	~Song();

//Accessors
	char* get_song_name();
	//char* get_duration();
	int get_views();
	int get_likes();
	Song* get_next_song();

//Mutators to edit views and likes
	void edit_views(int views);
	void edit_likes(int likes);

//IGNORE
	//void set_duration();

//Mutator to set next song node
	void set_next_song(Song* next);

//Print song function
	void out();

private:
	char* song_name; //Name of song
	//char* duration; //Will work on fix later on own time
	int song_min;	//Songs minutes duration
	int song_sec;	//Songs seconds duration
	int song_views; //Views on song
	int song_likes; //Likes on song
	Song* next_song;//Next Song Node
};
	
