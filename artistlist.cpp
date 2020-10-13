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

//MUTATOR
void ArtistList::set_artist(Artist* name){
	head = name;
}

void ArtistList::add_artist(){
	Artist* add = new Artist;
	add->set_artist(add);
	add->set_news(add);
	add->set_desc(add);

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
	

//OSTREAM
void ArtistList::print_artistlist(){
	Artist* curr = head;
	while(curr != nullptr){
		cout << curr->get_name() << endl;
		curr = curr->get_next_artist();
	}
}

void ArtistList::print_songlist(char* parm){
	Artist* temp = head;
	bool found = false;

	if(temp == nullptr) cout << "There are no artist listed." << endl;
	else{
		while(temp != nullptr){
			if(strcmp(parm, temp->get_name()) == 0){
				temp->print_songs();
				found = true;
			}
			temp = temp->get_next_artist();
		}
	}
	if(found == false) cout << "Artist could not be found." << endl;
}

void ArtistList::add_songlist(char* parm){
	Artist* temp = head;
	bool found = false;

	if(temp == nullptr) cout << "There are no artist listed." << endl;
	else{
		while(temp != nullptr){
			if(strcmp(parm, temp->get_name()) == 0){
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

				temp->add_song(name, min, sec, views, likes);
				found = true;
				return;
			}
			temp = temp->get_next_artist();
		}
		if(found == false){
		 cout << "Artist not found!" << endl;
		}
	}
}

//MISC
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
