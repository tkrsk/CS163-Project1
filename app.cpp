//TAKA MASAGATANI
//CS260
//FALL2020
//PROJECT #1
//CPP FILE FOR MAIN APP
//app.cpp
//SORRY FOR USING BREAKS, WILL CHANGE FROM SWITCHCASE TO IF ELSE NEXT TIME

#include "app.h"

using namespace std;

int main(int argc, char** argv, char** envp){

	ArtistList record; //Artist Linked List
	ifstream artist_file, song_file; //Data Files

	artist_file.open("artist.txt");	
	
	while(artist_file.peek() != '~'){
		record.artist_init(artist_file);
	}
	
	artist_file.close();

	song_file.open("song.txt");
	
	while(song_file.peek() != '~'){
		record.songlist_init(song_file);
	}
	
	song_file.close();

	cout << "(0): To Exit.\n(1): Show all artist.\n(2): Display all songs from an artist.\n(3): Display info on an artist.\n(4): Add a new artist." << endl;
	cout << "(5): Add a new song to an artist's list.\n(6): Edit views and likes for a song.\n(7): Remove all songs with less than a certain amount of views." << endl;
	cout << "Please enter a number for one of the listed commands: ";
	
	int command; //Int to store user input for command options
	
	cin >> command;
	
	while(command >= 1 && command <= 7){
	
		cin.ignore();
		
		switch(command){
			case 1:{
				record.print_artistlist();
				
				break;
			}
			case 2:{
				cout << "Please enter artist whose songs you want to see: ";
				
				char* temp = record.strbuild(); //Temp cstring for artist name search to print songs
				
				record.print_songlist(temp);
				
				delete [] temp;
				
				break;
			}
			case 3:{
				cout << "Please enter artist whose info you want to see: ";
				
				char* temp = record.strbuild(); //Temp cstring to search for artist whose info to print
				
				record.print_info(temp);
				
				delete [] temp;
				
				break;
			}
			case 4:{
				record.add_artist();
				
				break;
			}
			case 5:{
				cout << "Please enter artist to add new song: ";
				
				char* temp = record.strbuild(); //Temp cstring for artist to add song to
				
				record.add_songlist(temp);
				
				delete [] temp;
				
				break;
			}
			case 6:{
				cout << "Please enter artist whose song you want to edit: ";
				
				char* temp = record.strbuild(); //Temp cstring to search for artist whose song to edit
				
				record.edit_song(temp);
				
				delete [] temp;
				
				break;
			}
			case 7:{
				int remove; //Int amount of views to delete less than 'remove'
				
				cout << "Please enter a number to remove all songs with less than that many views: ";
				
				cin >> remove;
				
				record.del_song(remove);
				
				break;
			}
		}

	cout << "(0): To Exit.\n(1): Show all artist.\n(2): Display all songs from an artist.\n(3): Display info on an artist.\n(4): Add a new artist." << endl;
	cout << "(5): Add a new song to an artist's list.\n(6): Edit views and likes for a song.\n(7): Remove all songs with less than a certain amount of views." << endl;
	cout << "Please enter a number for one of the listed commands: ";
	
	cin >> command;
	}
}
