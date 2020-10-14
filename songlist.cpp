//TAKA MASAGATANI
//CS260
//FALL2020
//PROJECT #1
//CPP FOR SONG LINKED LIST
//songlist.cpp

#include "songlist.h"
	
using namespace std;

//CONSTRUCTOR
SongList::SongList(){
	first_song = nullptr;
}



//DESTRUCTOR
SongList::~SongList(){
	while(first_song != nullptr){
		Song* next = first_song->get_next_song(); //Song Node to store the next node so it is not loss on head deletion
		delete first_song;
		first_song = next;
	}
}



//ACCESSOR FOR HEAD NODE
Song* SongList::get_songlist(){
	return first_song;
}



//FUNCTION FOR INSERTION OF SONGS, ALSO ORDERS BY VIEWS(HIGHEST TO LOWEST)
void SongList::insert_song(char* input, int min, int sec, int views, int likes){
	Song* add = new Song(input, min, sec, views, likes); //Creation of new Song to add to list
	
	if(first_song == nullptr){
		first_song = add;
	}
	else{
		Song* curr = first_song; //Temporary Song Node to not change the real head while traversing
		
		while(curr != nullptr){
			if(curr->get_views() < add->get_views()){
				break;
			}
			curr = curr->get_next_song();
		}
		if(curr == first_song){
			add->set_next_song(first_song);
			first_song = add;
		}
		else if(curr == nullptr){
			curr = first_song;
			while(curr->get_next_song() != nullptr) curr = curr->get_next_song();
			curr->set_next_song(add);
		}
		else{
			add->set_next_song(curr);
			Song* temp = first_song; //Temporary Song Node to not change the real head while traversing
			while(temp->get_next_song() != curr) temp = temp->get_next_song();
			temp->set_next_song(add);
		}
	}
}



//FUNCTION TO SEARCH FOR AND EDIT VIEWS AND LIKES ON A SONG
void SongList::edit(char* parm){
	Song* curr = first_song; //Temporary Song Node to not change the real head while traversing through list
	bool found = false; //Boolean to check if song to change exists

	if(curr == nullptr) cout << "This artist has no songs listed." << endl;
	else{
		while(curr != nullptr){
			if(strcmp(parm, curr->get_song_name()) == 0){
				int views, likes; //New values for changed views and likes
				
				cout << "Please enter the new amount of views: ";
				cin >> views;
				curr->edit_views(views);
				
				cout << "Please enter the new amount of likes: ";
				cin >> likes;
				curr->edit_likes(likes);

				found = true;
			}
			curr = curr->get_next_song();
		}
	}
	if(found == false) cout << "Invalid song name." << endl;
}



//FUNCTION TO SEARCH AND DELETE SONG NODES WITH LOWER THAN x VIEWS
void SongList::remove_song(int views){
	Song* curr = first_song;  //Temporary Song Node to not change the real head while traversing through list
	Song* next = curr->get_next_song(); //Temporary Song Node to store next pointer so it doesn't get lost
	
	while(next != nullptr){
		if(curr->get_views() < views){
			delete curr;
			first_song = next;
			curr = first_song;
			next = curr->get_next_song();
			continue;
		}
		if(next->get_views() < views){
			curr->set_next_song(next->get_next_song());
			delete next;
			next = curr->get_next_song();
		}
		else{
			curr = curr->get_next_song();
			next = curr->get_next_song();
		}
	}
	if(first_song->get_views() < views){
		next = first_song->get_next_song();
		delete first_song;
		first_song = next;
	}
}



//MUTATOR FOR TO CHANGE SONG HEAD NODE
void SongList::set_first_song(Song* new_head){
	first_song = new_head;
}



//MY WEAK RECURSIVE PRINT FUNCTION
void SongList::print(Song* parm){
	if(parm == nullptr) return;
	parm->out();
	print(parm->get_next_song());
}
