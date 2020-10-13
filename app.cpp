#include "app.h"

using namespace std;

int main(int argc, char** argv, char** envp){
	ArtistList record;
	
	record.artist_init();
	cout << "Please enter a number for one of the following commands: " << endl;
	cout << "(0): To Exit.\n(1): Show all artist.\n(2): Display all songs from an artist.\n(3): Add a new artist." << endl;
	cout << "(4): Add a new song to an artist's list.\n(5): Edit views and likes for a song.\n(6): Remove all songs with less than a certain amount of views." << endl;
	
	int command;
	cin >> command;
	while(command >= 1 && command <= 6){
		cin.ignore();	
		switch(command){
			case 1:{
				record.print_artistlist();
				break;
			}
			case 2:{
				cout << "Please enter artist whose songs you want to see: ";
				char* temp = record.strbuild();
				record.print_songlist(temp);
				break;
			}
			case 3:{
				record.add_artist();
				break;
			}
			case 4:{
				cout << "Please enter artist to add new song: ";
				char* temp = record.strbuild();
				record.add_songlist(temp);
				break;
			}
			case 5:{
				cout << "Please enter artist whose song you want to edit: ";
				char* temp = record.strbuild();
				//FIXME: ADD ARTIST SEARCH FUNCTION
				break;
			}
			case 6:{
				int remove;
				cout << "Please enter a number to remove all songs with less than that many views: ";
				cin >> remove;
				//FIXME: ADD REMOVAL FUNCTION
				break;
			}
		}
	cout << "Please enter a number for one of the following commands: " << endl;
	cout << "(0): To Exit.\n(1): Show all artist.\n(2): Display all songs from an artist.\n(3): Add a new artist." << endl;
	cout << "(4): Add a new song to an artist's list.\n(5): Edit views and likes for a song.\n(6): Remove all songs with less than a certain amount of views." << endl;
	cin >> command;
	}
}
