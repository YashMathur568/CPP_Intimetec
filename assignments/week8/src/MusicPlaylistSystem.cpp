#include "MusicPlaylistSystem.h"
#include <iostream>
#include "Song.h"

MusicPlaylistSystem::MusicPlaylistSystem(IPlaylistManager *manager, IMusicPlayer *player)
    : manager(manager), player(player) {}

void MusicPlaylistSystem::showMainMenu()
{
    while (true)
    {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. View all playlists\n";
        std::cout << "2. Create new playlist\n";
        std::cout << "3. Select playlist\n";
        std::cout << "4. Exit\n";
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            manager->viewAllPlaylists();
        }
        else if (choice == 2)
        {
            std::cout << "Enter playlist name: ";
            std::string name;
            std::cin.ignore();
            std::getline(std::cin, name);
            if (manager->createPlaylist(name))
            {
                std::cout << "Playlist created.\n";
            }
            else
            {
                std::cout << "Playlist already exists.\n";
            }
        }
        else if (choice == 3)
        {
            std::cout << "Enter playlist name: ";
            std::string name;
            std::cin.ignore();
            std::getline(std::cin, name);
            IPlaylist *playlist = manager->getPlaylist(name);
            if (playlist)
            {
                showPlaylistMenu(playlist);
            }
            else
            {
                std::cout << "Playlist not found.\n";
            }
        }
        else if (choice == 4)
        {
            break;
        }
    }
}

void MusicPlaylistSystem::showPlaylistMenu(IPlaylist *selectedPlaylist)
{
    player->selectPlaylist(selectedPlaylist);

    while (true)
    {
        std::cout << "\n--- Playlist Menu ---\n";
        std::cout << "1. Display All Songs\n";
        std::cout << "2. Play any song\n";
        std::cout << "3. Play/Pause\n";
        std::cout << "4. Next Song\n";
        std::cout << "5. Previous Song\n";
        std::cout << "6. Add Song\n";
        std::cout << "7. Remove Song\n";
        std::cout << "8. Move song up\n";
        std::cout << "9. Move song down\n";
        std::cout << "10. Back\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            displaySongs(selectedPlaylist);
        }
        else if (choice == 2)
        {
            std::string songName;
            std::cout << "Enter song name: ";
            std::cin.ignore();
            std::getline(std::cin, songName);
            const auto &songs = selectedPlaylist->getSongs();
            int foundIndex = -1;
            for (size_t i = 0; i < songs.size(); ++i)
            {
                if (songs[i]->getName() == songName)
                {
                    foundIndex = static_cast<int>(i);
                    break;
                }
            }
            if (foundIndex != -1)
            {
                player->playAtIndex(songs, foundIndex);
            }
            else
            {
                std::cout << "Song not found.\n";
            }
        }
        else if (choice == 3)
        {
            player->playOrPause();
        }
        else if (choice == 4)
        {
            player->nextSong();
        }
        else if (choice == 5)
        {
            player->prevSong();
        }
        else if (choice == 6)
        {
            std::string name;
            std::cout << "Enter song name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::string path = "./audio/" + name;
            selectedPlaylist->addSong(new Song(path, name));
        }
        else if (choice == 7)
        {
            int idx;
            std::cout << "Enter song index: ";
            std::cin >> idx;
            std::cin.ignore();
            selectedPlaylist->removeSongAt(idx);
        }
        else if (choice == 8)
        {
            int idx;
            std::cout << "Enter song index to move up: ";
            std::cin >> idx;
            std::cin.ignore();
            selectedPlaylist->moveSongUp(idx);
        }
        else if (choice == 9)
        {
            int idx;
            std::cout << "Enter song index to move down: ";
            std::cin >> idx;
            std::cin.ignore();
            selectedPlaylist->moveSongDown(idx);
        }
        else if (choice == 10)
        {
            break;
        }
    }
}

void MusicPlaylistSystem::displaySongs(const IPlaylist *playlist)
{
    const auto &songs = playlist->getSongs();
    std::cout << "Playlist: " << playlist->getName() << "\n";
    std::cout << "------------------------\n";
    if (songs.empty())
    {
        std::cout << "(no songs in this playlist)\n";
    }
    else
    {
        for (size_t i = 0; i < songs.size(); ++i)
        {
            std::cout << "[" << i << "] "
                      << songs[i]->getName() << "\n";
        }
    }
    std::cout << "------------------------\n";
}