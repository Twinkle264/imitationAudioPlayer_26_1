#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

class Track {
private:
    string name;
    tm date;
    int duration;

public:
    void setName(const string& name_track){
        name = name_track;
    }

    void setDate(const string& date_str){
        istringstream iss(date_str);
        iss >> get_time(&date, "%d/%m/%Y");
    }

    void setDuration(int sec){
        duration = sec;
    }

    string getName(){
        return name;
    }

    void showTrackInfo(){
        cout << "Name: " << name << endl;
        cout << "Date of creation: " << put_time(&date, "%d/%m/%Y") << endl;
        cout << "Duration: " << duration << " sec." << endl;
    }
};

vector<Track> playlist;

class Player {
private:
    bool isPlay = false;
    int idCurrentTrack;

public:
    void Play(){
        if (!isPlay) {
            string name_target_track;

            cout << "Enter the name of track: ";
            cin.ignore();
            getline(cin, name_target_track);

            if (!playlist.empty()){
                for (int i = 0; i < playlist.size(); ++i) {
                    if (playlist[i].getName() == name_target_track){
                        idCurrentTrack = i;
                        playlist[idCurrentTrack].showTrackInfo();
                        isPlay = true;
                        break;
                    }
                }
            } else {
                cout << "Playlist is empty!" << endl;
            }
        } else {
            cout << "The track is playing now." << endl;
        }
    }

    void Next(){
        idCurrentTrack = rand() % playlist.size();
        playlist[idCurrentTrack].showTrackInfo();
        isPlay = true;
    }

    void Pause(){
        if (isPlay){
            isPlay = false;
            cout << "Track \"" << playlist[idCurrentTrack].getName() << "\" on pause" << endl;
        }
    }

    void Stop(){
        if (isPlay){
            isPlay = false;
            cout << "Track \"" << playlist[idCurrentTrack].getName() << "\" stopped" << endl;
        }
    }

};
