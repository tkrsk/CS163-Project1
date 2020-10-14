#include "artistlist.h"

using namespace std;

//CONSTRUCTOR
ArtistList::ArtistList(){
	head = nullptr;
}

//DESTRUCTOR
ArtistList::~ArtistList(){
	while(head != nullptr){
		Artist* next = head->get_next_artist();
		delete head;
		head = next;
	}
}

//ACCESSOR
Artist* ArtistList::get_artist(){
	return head;
}

//FILE INIT
void ArtistList::artist_init(ifstream& artist_file){
	char *name, *news, *desc;

	name = get_line(artist_file); 

	news = get_line(artist_file); 

	desc = get_line(artist_file); 

	Artist* add = new Artist(name, news, desc);
	sort_artist(add);

	if(artist_file.peek() == '\n') artist_file.get();
}

void ArtistList::songlist_init(ifstream& song_file){
	Artist* curr = head;
	char* artist = get_line(song_file);
	bool found = false;

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
	char* title;
	int min = 0, 
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
}

//MUTATOR
void ArtistList::set_artist(Artist* name){
	head = name;
}

void ArtistList::add_artist(){
	Artist* add = new Artist;
	cout << "Please enter the artist's name: " << endl;
	add->set_artist(add);
	
	cout << "Please enter recent news about the artist: " << endl;
	add->set_news(add);

	cout << "Please enter a description about the artist: " << endl;
	add->set_desc(add);
	
	sort_artist(add);
}

void ArtistList::sort_artist(Artist* add){
	Artist* curr = head;

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
		Artist* temp = head;
		while(temp->get_next_artist() != curr){
			temp = temp->get_next_artist();
		}
		temp->set_next_artist(add);
	}	
}

void ArtistList::add_songlist(char* parm){
	Artist* curr = head;
	bool found = false;

	if(curr == nullptr) cout << "There are no artist listed." << endl;
	else{
		while(curr != nullptr){
			if(strcmp(parm, curr->get_name()) == 0){
				cout << "Please enter the name of the song: ";
				char* name = strbuild();
				int min, sec, views, likes;
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
	Artist* curr = head;
	bool found = false;

	if(curr == nullptr) cout << "There are no artist listed." << endl;
	else{
		while(curr != nullptr){
			if(strcmp(parm, curr->get_name()) == 0){
				SongList* temp = curr->get_songlist();
				curr->print_songs();
				cout << "Please enter the name of the song you want to edit: ";
				char* song = strbuild();
				temp->edit(song);
				found = true;
			}
			curr = curr->get_next_artist();
		}
	}
	if(found == false) cout << "Artist could not be found." << endl;
}

//REMOVAL FUNCTIONS
void ArtistList::del_song(int views){
	Artist* curr = head;
	while(curr != nullptr){
		SongList* temp = curr->get_songlist();
		temp->remove_song(views);
		curr = curr->get_next_artist();
	}
}

//PRINT FUNCTIONS
void ArtistList::print_artistlist(){
	Artist* curr = head;
	while(curr != nullptr){
		cout << curr->get_name() << endl;
		curr = curr->get_next_artist();
	}
}

void ArtistList::print_songlist(char* parm){
	Artist* curr = head;
	bool found = false;

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
	Artist* curr = head;
	bool found = false;

	if(curr == nullptr) cout << "There are no artist listed. " << endl;
	else{
		while(curr != nullptr){
			if(strcmp(parm, curr->get_name()) == 0){
				cout << "---" << endl;
				cout << "Artist Name: " << curr->get_name() << endl;
				cout << "-\nDescription: " << curr->get_desc() << endl;
				cout << "-\nRecent News: " << curr->get_news() << endl;
				cout << "---" << endl;
				found = true;
			}
			curr = curr->get_next_artist();
		}
	}
	if(found == false) cout << "Artist could not be found." << endl;
}

//MISC
char* ArtistList::get_line(ifstream& input){
	char buffer = '\0';
	char * output = nullptr;

	while(input.peek() != ';'){
		buffer = input.get();
		if(output == nullptr){
			output = new char[2];
			output[0] = buffer;
			output[1] = '\0';
		}
		else{
			char * temp = new char[strlen(output) + 2];
			strcpy(temp, output);
			temp[strlen(temp)] = buffer;
			temp[strlen(output) + 1] = '\0';
			delete [] output;
			output = temp;
		}
	}
	input.ignore();
	return output;
}

char* ArtistList::strbuild(){
	char buffer = '\0';
	char * string = nullptr;

	while(cin.peek() != '\n'){
		buffer = cin.get();
		if(string == nullptr){
			string = new char[2];
			string[0] = buffer;
			string[1] = '\0';
		}
		else{
			char * temp = new char[strlen(string) + 2];
			strcpy(temp, string);
			temp[strlen(temp)] = buffer;
			temp[strlen(string) + 1] = '\0';
			delete [] string;
			string = temp;
		}
	}
	cin.ignore();
	return string;
}
