#include "MusicPlayer.h"
#include "SFMLAudioPlayer.h"
#include "PlaylistManager.h"
#include "MusicPlaylistSystem.h"

int main()
{
    IAudioPlayer *audioPlayer = new SFMLAudioPlayer();
    MusicPlayer *musicPlayer = new MusicPlayer(audioPlayer, true);
    PlaylistManager *playlistManager = new PlaylistManager();

    playlistManager->loadAllPlaylistsFromDisk();

    MusicPlaylistSystem system(playlistManager, musicPlayer);
    system.showMainMenu();

    delete musicPlayer;
    delete playlistManager;

    return 0;
}