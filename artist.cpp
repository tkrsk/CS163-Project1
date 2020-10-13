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
			artist_name = nullptr;
		}
	}
	if(artist_news != nullptr){
		if(artist_news[0] != '\0'){
			for(int idx = 0; artist_news[(idx) + 1] != '\0'; idx++) artist_news[idx] = '\0';
			delete [] artist_news;
			artist_news = nullptr;
		}
	}
	if(artist_desc != nullptr){
		if(artist_desc[0] != '\0'){
			for(int idx = 0; artist_desc[(idx) + 1] != '\0'; idx++) artist_desc[idx] = '\0';
			delete [] artist_desc;
			artist_desc = nullptr;
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

//MUTATORS
void Artist::set_artist(Artist* parm){
	char buffer = '\0';

	while(cin.peek() != '\n'){
		buffer = cin.get();
		if(artist_name == nullptr){
			artist_name = new char[2];
			artist_name[0] = buffer;
			artist_name[1] = '\0';
		}
		else{
			char * temp = new char[strlen(artist_name) + 2];
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
	char buffer = '\0';
	
	while(cin.peek() != '\n'){
		buffer = cin.get();
		if(artist_news == nullptr){
			artist_news = new char[2];
			artist_news[0] = buffer;
			artist_news[1] = '\0';
		}
		else{
			char * temp = new char[strlen(artist_news) + 2];
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
	char buffer = '\0';

	while(cin.peek() != '\n'){
		buffer = cin.get();
		if(artist_desc == nullptr){
			artist_desc = new char[2];
			artist_desc[0] = buffer;
			artist_desc[1] = '\0';
		}
		else{
			char * temp = new char[strlen(artist_desc) + 2];
			strcpy(temp, artist_desc);
			temp[strlen(temp)] = buffer;
			temp[strlen(artist_desc) + 1] = '\0';
			delete [] artist_desc;
			artist_desc = temp;
		}
	}
	cin.ignore();
}

void Artist::set_next_artist(Artist* next){
	next_artist = next;
}

void Artist::add_song(char* name, int min, int sec, int views, int likes){
	discog.insert_song(name, min, sec, views, likes);
}

void Artist::print_songs(){
	discog.print(discog.get_songlist());
}
