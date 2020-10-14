#include "song.h"

using namespace std;

Song::Song(){
	song_name = nullptr;
	//duration = nullptr;
	song_min = 0;
	song_sec = 0;
	song_views = 0;
	song_likes = 0;
	next_song = nullptr;
}

Song::Song(char* name, int min, int sec, int views, int likes){
	song_name = new char[strlen(name) + 1];
	for(int idx = 0; idx < strlen(name) + 1; idx++) song_name[idx] = '\0';
	strcpy(song_name, name);
	song_min = min;
	song_sec = sec;
	//set_duration();
	song_views = views;
	song_likes = likes;
	next_song = nullptr;

}

Song::~Song(){
if(song_name != nullptr){
		if(song_name[0] != '\0'){
	  		for(int idx = 0; song_name[(idx) + 1] != '\0'; idx++) song_name[idx] = '\0';
		}	
		delete [] song_name;
	}
	/*if(duration != nullptr){
		delete [] duration;
	}*/
	song_min = 0;
	song_sec = 0;
	song_views = 0;
	song_likes = 0;
}

//ACCESSORS//
char* Song::get_song_name(){
	return song_name;
}

/*char* Song::get_duration(){
	return duration;
}*/

int Song::get_views(){
	return song_views;
}

int Song::get_likes(){
	return song_likes;
}

Song* Song::get_next_song(){
	return next_song;
}

//MUTATORS//
void Song::edit_views(int views){
	song_views = views;
}

void Song::edit_likes(int likes){
	song_likes = likes;
}

//FUNCTION MYSTERIOUSLY PULLS RANDOM INFO OFF ISTREAM
/*void Song::set_duration(){
	if(song_min < 10){
		duration = new char[5];
		duration[0] = song_min + '0';
		duration[1] = ':';
		if(song_sec < 10){
			duration[2] = '0';
			duration[3] = song_sec + '0';
		}
		else{
			duration[2] = (song_sec / 10) + '0';
			duration[3] = (song_sec % 10) + '0';
		}
		cout << duration << endl;
	}
	else{
		duration = new char[6];
		duration[0] = (song_min / 10) + '0';
		duration[1] = (song_min % 10) + '0';
		duration[2] = ':';
		if(song_sec < 10){
			duration[3] = '0';
			duration[4] = song_sec + '0';
		}
		else{
			duration[3] = (song_sec / 10) + '0';
			duration[4] = (song_sec % 10) + '0';
		}
		cout << duration << endl;
	}
}*/

void Song::set_next_song(Song* next){
	next_song = next;
}

void Song::out(){
	cout << "Song Title: " << song_name << endl;
	if(song_sec >= 10)cout << "Duration: " << song_min << ":" << song_sec <<  endl;
	else cout << "Duration: " << song_min << ":0" << song_sec << endl;
	cout << "Views: " << song_views << endl;
	cout << "Likes: " << song_likes << endl;
	cout << "---" << endl;
}
