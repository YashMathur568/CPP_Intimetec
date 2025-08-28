#include "PlaylistManager.h"
#include "MusicPlayer.h"
#include "MusicPlaylistSystem.h"
#include <iostream>

int main()
{
    std::cout << "=== Simple Music Player ===\n";

    PlaylistManager manager;
    MusicPlayer player;

    manager.loadAllPlaylistsFromDisk();

    MusicPlaylistSystem system(&manager, &player);
    system.showMainMenu();

    manager.saveAllPlaylistsToDisk();

    std::cout << "Hope You Like Our Music!\n";
    return 0;
}
