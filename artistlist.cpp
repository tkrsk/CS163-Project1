//TAKA MASAGATANI
//CS260
//FALL2020
//PROJECT #1
//CPP FILE FOR ARTIST LINKED LIST
//artistlist.cpp
//VERY MESSY, LONG


#include "artistlist.h"

using namespace std;

//CONSTRUCTOR
ArtistList::ArtistList(){
	head = nullptr;
}



//DESTRUCTOR
ArtistList::~ArtistList(){
	while(head != nullptr){
		Artist* next = head->get_next_artist(); //Temporary Artist Node to not change the real head while traversing through list
		
		delete head;
		
		head = next;
	}
}




//HEAD ARTIST NODE ACCESSOR
Artist* ArtistList::get_artist(){
	return head;
}



//FUNCTIONS TO TAKE IN FILE DATA
void ArtistList::artist_init(ifstream& artist_file){
	char *name, *news, *desc; //Temporary cstrings to create artist values

	name = get_line(artist_file); 

	news = get_line(artist_file); 

	desc = get_line(artist_file); 

	Artist* add = new Artist(name, news, desc); //New artist node to be added to artist linked list
	sort_artist(add);
	
	if(artist_file.peek() == '\n') artist_file.get();

	delete [] name;
	delete [] news;
	delete [] desc;
}



void ArtistList::songlist_init(ifstream& song_file){
	Artist* curr = head;  //Temporary Artist Node to not change the real head while traversing through list
	char* artist = get_line(song_file); //Temporary cstring to search for correct artist to add song to
	bool found = false; //Boolean to check if artist to add song to exists

	if(curr == nullptr) cout << "Songs could not be added due to missing artist list." << endl;
	else{
		while(curr != nullptr){
			if(strcmp(artist, curr->get_name()) == 0){
				found = true;
				break;
			}
			curr = curr->get_next_artist();
		}
		if(found == false){
		 cout << "Artist not found!" << endl;
		 return;
		}
	}
	char* title; //Temp cstring to store title of new song to be added
	int min = 0, //Int values to store song info
		sec = 0, 
		views = 0, 
		likes = 0;	

	title = get_line(song_file);

	song_file >> min;

	song_file >> sec;

	song_file >> views;

	song_file >> likes;

	curr->add_song(title, min, sec, views, likes);

	song_file.ignore();
	
	delete [] title;
	delete [] artist;
}



//ARTIST HEAD NODE MUTATOR
void ArtistList::set_artist(Artist* name){
	head = name;
}



//FUNCTION TO ADD NEW ARTIST
void ArtistList::add_artist(){
	Artist* add = new Artist; //New artist node to be added to list for user to define

	cout << "Please enter the artist's name: " << endl;
	add->set_artist(add);
	
	cout << "Please enter recent news about the artist: " << endl;
	add->set_news(add);

	cout << "Please enter a description about the artist: " << endl;
	add->set_desc(add);
	
	sort_artist(add);
}



//FUNCTION TO SORT ARTIST NODES INTO LINKED LIST IN ALPHABETICAL ORDER
void ArtistList::sort_artist(Artist* add){
	Artist* curr = head; //Temporary Artist Node to not change the real head while traversing through list

	while(curr != nullptr){
		if(strcmp(curr->get_name(), add->get_name()) == 0){
			break;
		}
		if(strcmp(curr->get_name(), add->get_name()) > 0){
			break;
		}
		curr = curr->get_next_artist();
	}
	if(curr == head){
		add->set_next_artist(curr);
		
		head = add;
	}
	else if(curr == nullptr){
		curr = head;
		
		while(curr->get_next_artist() != nullptr){
			curr = curr->get_next_artist();
		}
		
		curr->set_next_artist(add);
	}	
	else{
		add->set_next_artist(curr);
		
		Artist* temp = head;  //Temporary Artist Node to not change the real head while traversing through list
		
		while(temp->get_next_artist() != curr){
			temp = temp->get_next_artist();
		}
		
		temp->set_next_artist(add);
	}	
}



//FUNCTION TO ADD SONGS TO AN ARTIST
void ArtistList::add_songlist(char* parm){
	Artist* curr = head;  //Temporary Artist Node to not change the real head while traversing through list
	bool found = false; //Boolean to check if artist to add song to exists

	if(curr == nullptr) cout << "There are no artist listed." << endl;
	else{
		while(curr != nullptr){
			if(strcmp(parm, curr->get_name()) == 0){
				cout << "Please enter the name of the song: ";
				
				char* name = strbuild(); //Temp cstring that calls cstring builder function to make song title

				int min, sec, views, likes; //Ints for song details
				
				cout << "Please enter the minutes duration of the song: "; 
				cin >> min;

				cout<< "Please enter the seconds duration of the song: ";
				cin >> sec;

				cout << "Please enter the song's view amount: ";
				cin >> views;

				cout << "Please enter the song's likes amount: ";
				cin >> likes;

				curr->add_song(name, min, sec, views, likes);
				
				found = true;

				return;
			}
			curr = curr->get_next_artist();
		}
		if(found == false){
		 cout << "Artist not found!" << endl;
		}
	}
}



//VIEWS/LIKES EDITOR FUNCTION
void ArtistList::edit_song(char* parm){
	Artist* curr = head;  //Temporary Artist Node to not change the real head while traversing through list
	bool found = false; //Boolean to check if artist whose song to edit exists

	if(curr == nullptr) cout << "There are no artist listed." << endl;
	else{
		while(curr != nullptr){

			if(strcmp(parm, curr->get_name()) == 0){
				SongList* temp = curr->get_songlist(); //Temporary Song list for easier readbility for next function
				
				curr->print_songs();
				
				cout << "Please enter the name of the song you want to edit: ";
				
				char* song = strbuild(); //Temporary cstring for song title to search for
				
				temp->edit(song);
				
				found = true;
				
				delete [] song;
			}
			curr = curr->get_next_artist();
		}
	}
	if(found == false) cout << "Artist could not be found." << endl;
}



//FUNCTION FOR SONGS WITH LOWER THAN x VIEWS COMMAND
void ArtistList::del_song(int views){
	Artist* curr = head; //Temporary Artist Node to not change the real head while traversing through list

	while(curr != nullptr){
		SongList* temp = curr->get_songlist(); //Temporary songlist for easier readability for next function

		temp->remove_song(views);

		curr = curr->get_next_artist();
	}
}



//PRINT FUNCTIONS
void ArtistList::print_artistlist(){
	Artist* curr = head; //Temporary Artist Node to not change the real head while traversing through list

	while(curr != nullptr){
		cout << curr->get_name() << endl;

		curr = curr->get_next_artist();
	}
}



void ArtistList::print_songlist(char* parm){
	Artist* curr = head; //Temporary Artist Node to not change the real head while traversing through list
	bool found = false; //Boolean to check if artist whose song to print exists

	if(curr == nullptr) cout << "There are no artist listed." << endl;
	else{
		while(curr != nullptr){
			if(strcmp(parm, curr->get_name()) == 0){
				
				curr->print_songs();
				
				found = true;
			}
			curr = curr->get_next_artist();
		}
	}
	if(found == false) cout << "Artist could not be found." << endl;
}



void ArtistList::print_info(char* parm){
	Artist* curr = head; //Temporary Artist Node to not change the real head while traversing through list
	bool found = false; //Boolean to check if artist whose info to print exists

	if(curr == nullptr) cout << "There are no artist listed. " << endl;
	else{
		while(curr != nullptr){
			if(strcmp(parm, curr->get_name()) == 0){
				cout << "---" << endl;

				cout << "Artist Name: " << curr->get_name() << endl;

				cout << "-\nRecent News: " << curr->get_news() << endl;
				
				cout << "-\nDescription: " << curr->get_desc() << endl; //This is to make the printed info nice and easy to read
				
				cout << "---" << endl;
				
				found = true;
			}
			curr = curr->get_next_artist();
		}
	}
	if(found == false) cout << "Artist could not be found." << endl;
}



//DYNAMIC CSTRING BUILDER COMMANDS
char* ArtistList::get_line(ifstream& input){
	char buffer = '\0'; //Buffer character to append to cstring
	char * output = nullptr; //Buffer cstring to return to function where this function was called

	while(input.peek() != ';'){
		buffer = input.get();

		if(output == nullptr){
			output = new char[2];

			output[0] = buffer;
			
			output[1] = '\0';
		}
		else{
			char * temp = new char[strlen(output) + 2]; //Temporary cstring to change output cstring to right size char array
			
			strcpy(temp, output);
			
			temp[strlen(temp)] = buffer;
			
			temp[strlen(output) + 1] = '\0';
			
			delete [] output;
			
			output = temp;
		}
	}
	input.ignore(); //Clear any hanging chars in istream
	
	return output;
}



char* ArtistList::strbuild(){
	char buffer = '\0'; //Buffer char to append to end of cstring
	char * string = nullptr; //Buffer cstring to return to where function was called

	while(cin.peek() != '\n'){
		buffer = cin.get();
		
		if(string == nullptr){
			
			string = new char[2];
			
			string[0] = buffer;
			
			string[1] = '\0';
		}
		else{
			char * temp = new char[strlen(string) + 2]; //Temporary cstring to change output string to right size CArray
			
			strcpy(temp, string);
			
			temp[strlen(temp)] = buffer;
			
			temp[strlen(string) + 1] = '\0';
			
			delete [] string;
			
			string = temp;
		}
	}
	cin.ignore(); //clear buffer stream
	
	return string;
}
