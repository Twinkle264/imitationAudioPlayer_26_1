#include "classes.h"
#include <vector>

void createTracks(vector<Track> &playlist) {
    Track *track1 = new Track();
    track1->setName("AC/DC - TNT");
    track1->setDate("01/03/1976");
    track1->setDuration(216);
    playlist.push_back(*track1);
    delete track1;
    track1 = nullptr;

    Track *track2 = new Track();
    track2->setName("Korn - Blind");
    track2->setDate("03/07/1994");
    track2->setDuration(258);
    playlist.push_back(*track2);
    delete track2;
    track2 = nullptr;

    Track *track3 = new Track();
    track3->setName("Madonna - Like a Prayer");
    track3->setDate("15/04/1989");
    track3->setDuration(314);
    playlist.push_back(*track3);
    delete track3;
    track3 = nullptr;

}

int main() {
    srand(std::time(nullptr));
    Player *player = new Player();
    createTracks(playlist);

    string command;
    while (true) {
        cout << "Enter the command (play, pause, next, stop, exit): ";
        cin >> command;
        cout << endl;

        if (command == "play") {
            player->Play();
        } else if (command == "pause") {
            player->Pause();
        } else if (command == "next") {
            player->Next();
        } else if (command == "stop") {
            player->Stop();
        } else if (command == "exit") {
            delete player;
            player = nullptr;
            playlist.clear();
            break;
        }
    }

    return 0;
}
