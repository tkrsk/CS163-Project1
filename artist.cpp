//TAKA MASAGATANI
//CS260
//FALL2020
//PROJECT #1
//CPP FILE FOR ARTIST NODE
//artist.cpp

#include "artist.h"

using namespace std;

//CONSTRUCTORS
Artist::Artist(){
	artist_name = nullptr;
	artist_news = nullptr;
	artist_desc = nullptr;
	next_artist = nullptr;
}



Artist::Artist(char* name, char* news, char* desc){
	artist_name = new char[strlen(name) + 1];
	strcpy(artist_name, name);

	artist_news = new char[strlen(news) + 1];
	strcpy(artist_news, news);

	artist_desc = new char[strlen(desc) + 1];
	strcpy(artist_desc, desc);
	
	next_artist = nullptr;
}



//DESTRUCTORS
Artist::~Artist(){
	if(artist_name != nullptr){
		if(artist_name[0] != '\0'){
			for(int idx = 0; artist_name[(idx) + 1] != '\0'; idx++) artist_name[idx] = '\0';
			
			delete [] artist_name;
		}
	}
	if(artist_news != nullptr){
		if(artist_news[0] != '\0'){
			for(int idx = 0; artist_news[(idx) + 1] != '\0'; idx++) artist_news[idx] = '\0';
			
			delete [] artist_news;
		}
	}
	if(artist_desc != nullptr){
		if(artist_desc[0] != '\0'){
			for(int idx = 0; artist_desc[(idx) + 1] != '\0'; idx++) artist_desc[idx] = '\0';
			
			delete [] artist_desc;
		}
	}
}	



//ACCESSORS
char* Artist::get_name(){
	return artist_name;
}



char* Artist::get_news(){
	return artist_news;
}



char* Artist::get_desc(){
	return artist_desc;
}



Artist* Artist::get_next_artist(){
	return next_artist;
}



SongList* Artist::get_songlist(){
	return &discog;
}



//MUTATORS(PRETTY REPETITIVE CODE TO CREATE DYNAMIC CSTRINGS, .ignore() WAS USED TO TEST BUFFER FLUSHING)
void Artist::set_artist(Artist* parm){
	char buffer = '\0'; //Buffer character to append to cstring 

	while(cin.peek() != '\n'){
		buffer = cin.get();
	
		if(artist_name == nullptr){
			
			artist_name = new char[2];
			
			artist_name[0] = buffer;
			
			artist_name[1] = '\0';
		}
		else{
			char * temp = new char[strlen(artist_name) + 2]; //Temporary cstring to change artist name to right size
			
			strcpy(temp, artist_name);
			
			temp[strlen(temp)] = buffer;
			
			temp[strlen(artist_name) + 1] = '\0';
			
			delete [] artist_name;
			
			artist_name = temp;
		}
	}
	cin.ignore();
}



void Artist::set_news(Artist* parm){
	char buffer = '\0'; //Buffer char to append to cstring
	
	while(cin.peek() != '\n'){
		buffer = cin.get();
		if(artist_news == nullptr){
			
			artist_news = new char[2];
			
			artist_news[0] = buffer;
			
			artist_news[1] = '\0';
		}
		else{
			char * temp = new char[strlen(artist_news) + 2]; //Temporary cstring to change artist news to right size char array
			
			strcpy(temp, artist_news);
			
			temp[strlen(temp)] = buffer;
			
			temp[strlen(artist_news) + 1] = '\0';
			
			delete [] artist_news;
			
			artist_news = temp;
		}
	}
	cin.ignore();
}



void Artist::set_desc(Artist* parm){
	char buffer = '\0'; //Buffer char to append to cstring

	while(cin.peek() != '\n'){
		buffer = cin.get();
		
		if(artist_desc == nullptr){
			artist_desc = new char[2];
			
			artist_desc[0] = buffer;
			
			artist_desc[1] = '\0';
		}
		else{
			char * temp = new char[strlen(artist_desc) + 2]; //Temporary cstring to change artist description to right size char array
			
			strcpy(temp, artist_desc);
			
			temp[strlen(temp)] = buffer;
			
			temp[strlen(artist_desc) + 1] = '\0';
			
			delete [] artist_desc;
			
			artist_desc = temp;
		}
	}
	cin.ignore();
}



//MUTATOR TO CHANGE NEXT ARTIST NODE
void Artist::set_next_artist(Artist* next){
	next_artist = next;
}



//FUNCTION TO ADD A NEW SONG, CALLS FUNCTION IN SONGLIST
void Artist::add_song(char* name, int min, int sec, int views, int likes){
	discog.insert_song(name, min, sec, views, likes);
}




//PRINT FUNCTION, CALLS FUNCTION IN SONGLIST
void Artist::print_songs(){
	cout << "---" << endl;
	
	discog.print(discog.get_songlist());
}
