#include "MusicPlaylistSystem.h"
#include "InputValidation.h"
#include "filesystem"
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
        std::cout << "4. Delete playlist\n";
        std::cout << "5. Exit\n";

        std::cout << "Enter your choice: ";
        int choice = InputValidation::getValidatedInt();

        if (choice == 1)
        {
            manager->viewAllPlaylists();
        }
        else if (choice == 2)
        {
            std::cout << "Enter playlist name: ";
            std::string name;
            std::getline(std::cin, name);
            if (manager->createPlaylist(name))
            {
                std::cout << "Playlist created successfully.\n";
            }
            else
            {
                std::cout << "Playlist already exists.\n";
            }
        }
        else if (choice == 3)
        {
            manager->viewAllPlaylists();
            std::string name;
            std::cout << "Enter playlist name: ";
            std::getline(std::cin, name);
            IPlaylist *playlist = manager->getPlaylist(name);
            if (playlist)
            {
                std::cout << "Selected playlist: " << name << "\n";
                showPlaylistMenu(playlist);
            }
            else
            {
                std::cout << "Playlist not found.\n";
            }
        }
        else if (choice == 4)
        {
            manager->viewAllPlaylists();
            std::string name;
            std::cout << "Enter playlist name to delete: ";
            std::getline(std::cin, name);
            if (manager->deletePlaylist(name))
            {
                std::cout << "Playlist deleted successfully.\n";
            }
            else
            {
                std::cout << "Playlist not found.\n";
            }
        }
        else if (choice == 5)
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
        std::cout << "\n--- Playlist Menu: " << selectedPlaylist->getName() << " ---\n";
        std::cout << "1. Display All Songs\n";
        std::cout << "2. Play any song\n";
        std::cout << "3. Play/Pause\n";
        std::cout << "4. Next Song\n";
        std::cout << "5. Previous Song\n";
        std::cout << "6. Add Song\n";
        std::cout << "7. Remove Song\n";
        std::cout << "8. Move song up\n";
        std::cout << "9. Move song down\n";
        std::cout << "10. Back to Main Menu\n";

        std::cout << "Enter your choice: ";
        int choice = InputValidation::getValidatedInt();

        if (choice == 1)
        {
            displaySongs(selectedPlaylist);
        }
        else if (choice == 2)
        {
            displaySongs(selectedPlaylist);
            const auto &songs = selectedPlaylist->getSongs();
            if (songs.empty())
            {
                std::cout << "No songs in playlist to play.\n";
                continue;
            }

            std::string songName;
            std::cout << "Enter song name: ";
            std::getline(std::cin, songName);
            int foundIndex = -1;
            for (int i = 0; i < songs.size(); ++i)
            {
                if (songs[i]->getName() == songName)
                {
                    foundIndex = i;
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
            std::cout << "Enter Song name: ";
            std::string name;
            std::getline(std::cin, name);
            std::string path = "../audio/" + name + ".ogg";
            if (!std::filesystem::exists(path))
            {
                std::cout << "Song file does not exist: " << path << "\n";
                return;
            }
            selectedPlaylist->addSong(new Song(path, name));
            std::cout << "Song added to playlist.\n";
        }
        else if (choice == 7)
        {
            displaySongs(selectedPlaylist);
            const auto &songs = selectedPlaylist->getSongs();
            if (songs.empty())
            {
                std::cout << "No songs to remove.\n";
                continue;
            }

            std::cout << "Enter song index to remove: ";
            int index = InputValidation::getValidatedInt();
            if (index != -1)
            {
                std::string songName = songs[index]->getName();
                selectedPlaylist->removeSongAt(index - 1);
                std::cout << "Song removed.\n";
            }
            else
            {
                std::cout << "Invalid index.\n";
            }
        }
        else if (choice == 8)
        {
            displaySongs(selectedPlaylist);
            const auto &songs = selectedPlaylist->getSongs();

            std::cout << "Enter song index to move up: ";
            int index = InputValidation::getValidatedInt();
            if (index > 0)
            {
                if (index == 1)
                {
                    std::cout << "Song is already at the top.\n";
                }
                else
                {
                    selectedPlaylist->moveSongUp(index - 1);
                    std::cout << "Song moved up.\n";
                }
            }
            else
            {
                std::cout << "Invalid index.\n";
            }
        }
        else if (choice == 9)
        {
            displaySongs(selectedPlaylist);
            const auto &songs = selectedPlaylist->getSongs();

            std::cout << "Enter song index to move down: ";
            int index = InputValidation::getValidatedInt();
            if (index > 0)
            {
                if (index == songs.size())
                {
                    std::cout << "Song is already at the bottom.\n";
                }
                else
                {
                    selectedPlaylist->moveSongDown(index - 1);
                    std::cout << "Song moved down.\n";
                }
            }
            else
            {
                std::cout << "Invalid index.\n";
            }
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
    std::cout << "\nPlaylist: " << playlist->getName() << "\n";
    std::cout << "------------------------\n";
    if (songs.empty())
    {
        std::cout << "(no songs in this playlist)\n";
    }
    else
    {
        for (int i = 0; i < (int)songs.size(); ++i)
        {
            std::cout << "[" << (i + 1) << "] " << songs[i]->getName() << "\n";
        }
    }
    std::cout << "------------------------\n";
}