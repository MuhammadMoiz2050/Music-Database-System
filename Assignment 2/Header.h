//Muhammad Moiz Sajid
//19I-0692
//CS-B

//Assignment No.2

#pragma once
#include<fstream>
#include<string>
#include<sstream>
#include <iostream>
using namespace std;

//Class Prototypes
template<typename t1, typename t2, typename t3>
class AD;
template<typename t1, typename t2>
class AMD;
template<typename t1>
class ADP;
//Music Metadata DataBase (A doubly linked list)
template<typename t1, typename t2, typename t3>
class MMD
{
public:
	//data members
	t1 mbid;
	AD<t1, t2, t3>* album;

	t2 songName;
	t2 writer;
	t3 length;
	//connections
	MMD<t1, t2, t3>* next;
	MMD<t1, t2, t3>* previous;

};

////Author Metadata DataBase (A circular linked list)
template<typename t1, typename t2>
class AMD
{
public:
	//data members
	t1 aid;
	AD<t1, t2, float>* albums;
	ADP<t1>* adp;

	t2 name;
	t2 band;
	t2 gender;
	t1 dateOfBirth;
	t1 date;
	t2 genre;
	//connections
	AMD<t1, t2>* next;

	//Constructor
	AMD() {
		albums = NULL;

	}
};

//Tracks (A singly linked list)
template<typename t1>
class Tracks
{
public:
	//data members
	t1 trackNumber;
	MMD<t1, string, float>* trackRef;

	//int mbid;
	//connections
	Tracks<t1>* next;
};

//Album DataBase (A circular linked list)
template<typename t1, typename t2, typename t3>
class AD
{
public:
	//data members
	t1 abid;
	AMD<t1, t2>* author;
	Tracks<int>* tracks;
	ADP<t1>* adp;

	t2 albumName;
	t1 aid;
	t2 publisher;
	t1 numberOfTracks;
	t3 totalDuration;

	//connections
	AD<t1, t2, t3>* next;
};

//Albums (A singly linked list)
template<typename t1>
class Albums
{
public:
	//data members
	t1 year;
	AD<t1, string, float>* albumRef;

	//connections
	Albums<t1>* next;
};

//Author Discography Playlist (A circular linked list)
template<typename t1>
class ADP
{
public:
	//data members
	t1 did;
	AMD<t1, string>* author;
	Albums<t1>* albums;

	t1 aid;

	//connections
	ADP<t1>* next;
};

template<typename t1, typename t2, typename t3>
MMD<int, string, float>* mhead = NULL;

template<typename t1, typename t2>
AMD<int, string>* ahead = NULL;

template<typename t1, typename t2, typename t3>
AD<int, string, float>* head = NULL;

template<typename t1>
ADP<int>* dhead = NULL;




//Functions Prototypes
template<typename t1, typename t2, typename t3>
MMD<t1, t2, t3>* Create_MMD(string path) {


	MMD<t1, t2, t3>* tail = NULL;
	MMD<t1, t2, t3>* current = mhead<t1, t2, t3>;


	ifstream myFile;
	myFile.open(path);

	bool first = true;


	int j = 0;
	string line = "";
	string info = "";
	while (getline(myFile, line) && j < 157) {
		//myFile.good()
		stringstream ss(line);
		if (first) {
			first = false;
		}
		else {

			if (mhead<t1, t2, t3> == NULL) {
				MMD<t1, t2, t3>* temp = new MMD<t1, t2, t3>;
				getline(ss, info, ',');
				temp->mbid = stoi(info);
				if (info == "100") {
					getline(ss, info, ',');
					getline(ss, info, ',');
				}
				getline(ss, info, ',');
				temp->songName = info;
				getline(ss, info, ',');
				temp->writer = info;
				getline(ss, info, ',');
				temp->length = stod(info);
				temp->next = NULL;
				temp->previous = NULL;
				mhead<t1, t2, t3> = temp;
				tail = temp;
				current = temp;
			}
			else {
				//MMD* temp = new MMD();
				MMD<t1, t2, t3>* temp = new MMD<t1, t2, t3>;
				getline(ss, info, ',');
				temp->mbid = stoi(info);
				if (info == "100") {
					getline(ss, info, ',');
					getline(ss, info, ',');
				}
				getline(ss, info, ',');
				temp->songName = info;
				getline(ss, info, ',');
				temp->writer = info;
				getline(ss, info, ',');
				temp->length = stod(info);

				temp->next = NULL;
				temp->previous = current;
				//current->next = temp;
				temp->previous->next = temp;
				//temp->next->previous = temp;

				tail = temp;
				current = temp;

			}

		}


		j++;


	}

	myFile.close();
	return mhead<t1, t2, t3>;
	cout << mhead<int, string, float> << endl;
}

////should return head of the MMD linkedlist

template<typename t1, typename t2>
AMD<t1, t2>* Create_AMD(string path) {

	//AMD* head = NULL;
	AMD<t1, t2>* tail = NULL;
	AMD<t1, t2>* current = ahead<t1, t2>;


	ifstream myFile;
	myFile.open(path);

	bool first = true;

	int j = 0;
	string line = "";
	string info = "";
	while (getline(myFile, line) && j < 6) {
		stringstream ss(line);
		if (first) {
			first = false;
		}
		else {
			if (ahead<t1, t2> == NULL) {
				AMD<t1, t2>* temp = new AMD<t1, t2>;
				getline(ss, info, ',');
				temp->aid = stoi(info);
				getline(ss, info, ',');
				temp->name = info;
				getline(ss, info, ',');
				temp->band = info;
				getline(ss, info, ',');
				temp->gender = info;
				getline(ss, info, ',');
				temp->dateOfBirth = stoi(info);
				getline(ss, info, ',');
				temp->date = stoi(info);
				getline(ss, info, ',');
				temp->genre = info;

				temp->next = NULL;
				ahead<t1, t2> = temp;
				tail = temp;
				current = temp;


			}
			else {
				AMD<t1, t2>* temp = new AMD<t1, t2>;
				getline(ss, info, ',');
				temp->aid = stoi(info);
				getline(ss, info, ',');
				temp->name = info;
				getline(ss, info, ',');
				temp->band = info;
				getline(ss, info, ',');
				temp->gender = info;
				getline(ss, info, ',');
				temp->dateOfBirth = stoi(info);
				getline(ss, info, ',');
				temp->date = stoi(info);
				getline(ss, info, ',');
				temp->genre = info;

				temp->next = ahead<t1, t2>;
				current->next = temp;
				tail = temp;
				current = temp;
			}

		}
		j++;
	}
	return ahead<t1, t2>;
}; //should return head of the AMD linkedlist

template<typename t1, typename t2, typename t3>
AD<t1, t2, t3>* Create_AD(string path) {
	//AD* head = NULL;
	AD<t1, t2, t3>* tail = NULL;
	AD<t1, t2, t3>* current = head<t1, t2, t3>;

	MMD<t1, t2, t3>* index = NULL;

	Tracks<t1>* thead = NULL;
	Tracks<t1>* tcurr = NULL;
	Tracks<t1>* tprev = NULL;

	ifstream myFile;
	myFile.open(path);

	bool first = true;

	int number = 0;
	int mbid1 = 0;

	int j = 0;
	string line = "";
	string info = "";

	string abid = "";
	string name = "";
	string aid = "";
	string publisher = "";
	string ntracks = "";
	string duration = "";
	string trackNo = "";
	string trackId = "";

	while (getline(myFile, line) && j < 157) {
		stringstream ss(line);
		if (first) {
			first = false;
		}
		else {
			if (head<t1, t2, t3> == NULL) {
				AD<t1, t2, t3>* temp = new AD<t1, t2, t3>;
				Tracks<t1>* temp1 = new Tracks<t1>;


				getline(ss, info, ',');
				temp->abid = stoi(info);
				getline(ss, info, ',');
				temp->albumName = info;
				getline(ss, aid, ',');
				temp->aid = stoi(aid);
				getline(ss, info, ',');
				temp->publisher = info;
				getline(ss, info, ',');
				temp->numberOfTracks = stoi(info);
				getline(ss, info, ',');
				temp->totalDuration = stof(info);



				getline(ss, info, ',');
				number = stoi(info);

				getline(ss, info, ',');
				mbid1 = stoi(info);


				temp1->trackNumber = number;


				index = mhead<t1, t2, t3>;

				for (int i = 1; i < mbid1; i++)
					index = index->next;

				temp1->trackRef = index;

				temp1->next = NULL;
				thead = temp1;
				tcurr = temp1;

				temp->next = NULL;
				head<t1, t2, t3> = temp;
				tail = temp;
				current = temp;
				temp->tracks = thead;

				//linking direct access from MMD to AD
				temp1->trackRef->album = current;
				cout << temp1->trackRef->album << endl;


				//2-WAY RELATIONSHIPS BETWEEN AD AND AMD

				temp->author = ahead<t1, t2>;
				for (int i = 1; i < stoi(aid); i++)
					temp->author = temp->author->next;

				temp->author->albums = current;
			}
			else {
				//AD* temp = new AD;

				getline(ss, abid, ',');
				getline(ss, name, ',');
				getline(ss, aid, ',');
				getline(ss, publisher, ',');
				getline(ss, ntracks, ',');
				getline(ss, duration, ',');
				getline(ss, trackNo, ',');
				getline(ss, trackId, ',');


				//CONDITION I INPUTED TO CUT OF THE TRACKST LIST
				if (stoi(trackNo) == 1) {
					tprev->next = NULL;
					thead->next = NULL;
				}
				Tracks<t1>* temp1 = new Tracks<t1>;
				//getline(ss, info, ',');
				number = stoi(trackNo);
				//getline(ss, info, ',');
				mbid1 = stoi(trackId);
				//temp1->trackRef->mbid = stoi(info);


				temp1->trackNumber = number;
				//temp1->trackRef->mbid = mhead->mbid;

				//MMD* index = NULL;
				index = mhead<t1, t2, t3>;

				for (int i = 1; i < mbid1; i++)
					index = index->next;

				//temp1->trackRef->mbid = index->mbid;
				temp1->trackRef = index;
				//temp1->trackRef->next = index->next;

				temp1->next = NULL;
				thead->next = temp1;
				tprev = thead;
				thead = temp1;


				//getline(ss, info, ',');
				if (stoi(abid) != current->abid) {
					AD<t1, t2, t3>* temp = new AD<t1, t2, t3>;


					temp->abid = stoi(abid);
					//getline(ss, info, ',');
					temp->albumName = name;
					//getline(ss, info, ',');
					temp->aid = stoi(aid);
					//getline(ss, info, ',');
					temp->publisher = publisher;
					//getline(ss, info, ',');
					temp->numberOfTracks = stoi(ntracks);
					//getline(ss, info, ',');
					temp->totalDuration = stof(duration);

					temp->next = head<t1, t2, t3>;
					//temp->next = NULL;
					current->next = temp;
					tail = current;
					current = temp;
					temp->tracks = thead;

					/*temp->author = ahead;
					if (temp->author->albums->next->abid != 1)
						temp->author->albums = temp->author->albums->next;*/

						////linking direct access from MMD to AD
						//temp1->trackRef->album = current;
						//cout << temp1->trackRef->album << endl;

						//2-WAY RELATIONSHIPS BETWEEN AD AND AMD
					//temp->author = ahead;
					//for (int i = 1; i < stoi(aid); i++)
					//	temp->author = temp->author->next;

					////if (stoi(abid) > 2) {
					////	temp->author->albums = current;
					////	temp->author->albums = temp->author->albums->next;
					////}
					//if (temp->author->albums == NULL) {
					//	temp->author->albums = current;
					//}
					//else {
					//	AD* newP = temp->author->albums;
					//	while (temp->author->albums->next != temp->author->albums) {
					//		temp->author->albums = temp->author->albums->next;
					//	}
					//	temp->author->albums->next = current;
					//	temp->author->albums = temp->author->albums->next;

					//}
					//	cout << temp->author->albums << endl;
					//	//AD* newP = new AD;
					//	//newP = current;
					//	//temp->author->albums->next = newP;
					//	temp->author->albums->next = temp->author->albums;

					//temp->author->albums = current;
					//temp->author->albums = temp->author->albums->next;
					//cout << temp->author->albums->next << endl;

					//2-WAY RELATIONSHIPS BETWEEN AD AND AMD

					AMD<t1, t2>* temp6 = ahead<t1, t2>;
					while (temp6->aid != stoi(aid))
						temp6 = temp6->next;

					current->author = temp6;
					AD<t1, t2, t3>* newAlbum = new AD<t1, t2, t3>;
					*newAlbum = *current;

					if (temp6->albums == NULL) {
						temp6->albums = newAlbum;
						newAlbum->next = temp6->albums;
					}
					else {
						AD<t1, t2, t3>* cAlbum = temp6->albums;
						while (cAlbum->next != temp6->albums) {
							cAlbum = cAlbum->next;
						}
						cAlbum->next = newAlbum;
						newAlbum->next = temp6->albums;
					}

				}
				//linking direct access from MMD to AD
				temp1->trackRef->album = current;
				cout << temp1->trackRef->album << endl;


			}

		}
		j++;
	}
	return head<t1, t2, t3>;
}; //should return head of the AD linkedlist

template<typename t1>
ADP<t1>* Create_ADP(string path) {

	ADP<t1>* tail = NULL;
	ADP<t1>* current = dhead<t1>;

	AD<t1, string, float>* index = NULL;

	Albums<t1>* Ahead = NULL;
	Albums<t1>* Aprev = NULL;

	ifstream myFile;
	myFile.open(path);

	bool first = true;

	int j = 0;
	string line = "";
	string info = "";

	int year = 0;
	int abid1 = 0;

	string DID = "";
	string AID = "";
	string albumABID = "";
	string YEAR = "";

	while (getline(myFile, line) && j < 15) {
		stringstream ss(line);
		if (first) {
			first = false;
		}
		else {
			if (dhead<t1> == NULL) {
				ADP<t1>* temp = new ADP<t1>;
				Albums<t1>* temp1 = new Albums<t1>;

				getline(ss, DID, ',');
				temp->did = stoi(DID);
				getline(ss, AID, ',');
				temp->aid = stoi(AID);

				getline(ss, info, ',');
				abid1 = stoi(info);
				getline(ss, info, ',');
				year = stoi(info);

				temp1->year = year;
				index = head<t1, string, float>;

				for (int i = 1; i < abid1; i++)
					index = index->next;

				temp1->albumRef = index;

				temp1->next = NULL;
				Ahead = temp1;

				temp->next = NULL;
				dhead<t1> = temp;
				tail = temp;
				current = temp;
				temp->albums = Ahead;

				//linking direct access from AD to ADP
				temp1->albumRef->adp = current;


				//2-WAY RELATIONSHIPS BETWEEN ADP AND AMD

				temp->author = ahead<t1, string>;
				for (int i = 1; i < stoi(AID); i++)
					temp->author = temp->author->next;

				temp->author->adp = current;
			}
			else {
				getline(ss, DID, ',');
				getline(ss, AID, ',');
				getline(ss, albumABID, ',');
				getline(ss, YEAR, ',');

				//CONDITION I INPUTED TO CUT OF THE ALBUMS LIST
				if (stoi(DID) != current->did) {
					Ahead->next = NULL;
				}

				Albums<t1>* temp1 = new Albums<t1>;
				abid1 = stoi(albumABID);
				year = stoi(YEAR);

				temp1->year = year;

				index = head<t1, string, float>;

				for (int i = 1; i < abid1; i++)
					index = index->next;

				temp1->albumRef = index;

				temp1->next = NULL;
				Ahead->next = temp1;
				Aprev = Ahead;
				Ahead = temp1;

				if (stoi(DID) != current->did) {
					ADP<t1>* temp = new ADP<t1>;
					temp->did = stoi(DID);
					temp->aid = stoi(AID);


					temp->next = dhead<t1>;
					current->next = temp;
					tail = temp;
					current = temp;
					temp->albums = Ahead;


					//2-WAY RELATIONSHIPS BETWEEN ADP AND AMD


					AMD<t1, string>* temp69 = ahead<t1, string>;
					while (temp69->aid != stoi(AID))
						temp69 = temp69->next;

					temp69->adp = current;
					current->author = temp69;

					cout << temp->author->adp->did << endl;

				}
				//linking direct access from AD to ADP
				temp1->albumRef->adp = current;
			}
		}
		j++;
	}

	return dhead<t1>;
}; //should return head of the ADP linkedlist

template<typename t1, typename t2, typename t3>
MMD<t1, t2, t3>* Search_Music(int MBID) {
	MMD<t1, t2, t3>* temp = new MMD<t1, t2, t3>;
	temp = mhead<t1, t2, t3>;
	for (int i = 1; i < MBID; i++) {
		temp = temp->next;
	}
	return temp;

}; //should return pointer to track having mbid = MBID

template<typename t1, typename t2>
AMD<t1, t2>* Search_Author(int AID) {
	AMD<t1, t2>* temp = ahead<t1, t2>;
	while (temp->aid != AID) {
		temp = temp->next;
	}
	return temp;
}; //should return pointer to author having aid = AID

template<typename t1, typename t2, typename t3>
AD<t1, t2, t3>* Search_Album(int ABID) {
	AD<t1, t2, t3>* temp = new AD<t1, t2, t3>;
	temp = head<t1, t2, t3>;
	for (int i = 1; i < ABID; i++) {
		temp = temp->next;
	}
	return temp;
}; //should return pointer to album having abid = ABID

template<typename t1>
ADP<t1>* Search_Discography(int DID) {
	ADP<t1>* temp = new ADP<t1>;
	temp = dhead<t1>;
	for (int i = 1; i < DID; i++) {
		temp = temp->next;
	}
	return temp;
}; //should return pointer to discography having did = DID

template<typename t1>
Tracks<t1>* Search_Music_By_Album(int ABID) {
	AD<t1, string, float>* temp = new AD<t1, string, float>;
	temp = head<t1, string, float>;
	for (int i = 1; i < ABID; i++) {
		temp = temp->next;
	}
	cout << temp->tracks->trackRef->mbid;
	return temp->tracks;
}; //should return singly linklist of "Tracks" in given album

template<typename t1>
Albums<t1>* Search_Music_By_Author(int DID) {
	ADP<t1>* temp = dhead<t1>;
	while (temp->did != DID) {
		temp = temp->next;
	}

	return temp->albums;
}; //should return singly linklist of "Albums" in given discography
//