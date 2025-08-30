#include "MusicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer(IAudioPlayer *audio, bool takeOwnership)
    : currentPlaylist(nullptr), currentIndexPlaying(-1), isPlaying(false),
      audioPlayer(audio), ownsAudioPlayer(takeOwnership) {}

MusicPlayer::~MusicPlayer()
{
    if (ownsAudioPlayer)
    {
        delete audioPlayer;
    }
}

void MusicPlayer::selectPlaylist(IPlaylist *playlist)
{
    currentPlaylist = playlist;
    currentIndexPlaying = -1;
    isPlaying = false;
}

void MusicPlayer::playOrPause()
{
    AudioStatus status = audioPlayer->getStatus();

    if (status == AudioStatus::Playing)
    {
        audioPlayer->pause();
        isPlaying = false;
        std::cout << "Paused\n";
    }
    else if (status == AudioStatus::Paused)
    {
        audioPlayer->play();
        isPlaying = true;
        std::cout << "Resumed\n";
    }
    else
    {
        std::cout << "No track is currently playing.\n";
    }
}

void MusicPlayer::nextSong()
{
    if (!currentPlaylist)
    {
        return;
    }
    auto &songs = currentPlaylist->getSongs();
    if (songs.empty())
    {
        std::cout << "No songs available in the playlist.\n";
        return;
    }
    if (currentIndexPlaying == -1)
    {
        std::cout << "No track is currently playing.\n";
        return;
    }
    else if (currentIndexPlaying + 1 < songs.size())
    {
        currentIndexPlaying++;
    }
    else
    {
        std::cout << "No next song available.\n";
        return;
    }

    if (audioPlayer->openFromFile(songs[currentIndexPlaying]->getPath()))
    {
        audioPlayer->play();
        isPlaying = true;
        std::cout << "Playing: " << songs[currentIndexPlaying]->getName() << "\n";
    }
}

void MusicPlayer::prevSong()
{
    if (!currentPlaylist)
    {
        return;
    }
    auto &songs = currentPlaylist->getSongs();
    if (songs.empty())
    {
        std::cout << "No songs available in the playlist.\n";
        return;
    }
    if (currentIndexPlaying == -1)
    {
        std::cout << "No previous song available.\n";
        return;
    }
    else if (currentIndexPlaying - 1 >= 0)
    {
        currentIndexPlaying--;
    }
    else
    {
        std::cout << "No previous song available.\n";
        return;
    }

    if (audioPlayer->openFromFile(songs[currentIndexPlaying]->getPath()))
    {
        audioPlayer->play();
        isPlaying = true;
        std::cout << "Playing: " << songs[currentIndexPlaying]->getName() << "\n";
    }
}

ISong *MusicPlayer::getCurrentSong() const
{
    if (!currentPlaylist)
        return nullptr;
    auto &songs = currentPlaylist->getSongs();
    if (currentIndexPlaying >= 0 && currentIndexPlaying < songs.size())
    {
        return songs[currentIndexPlaying];
    }
    return nullptr;
}

void MusicPlayer::playAtIndex(const std::vector<ISong *> &songs, int index)
{
    if (index < 0 || index >= songs.size())
    {
        std::cout << "Invalid song index.\n";
        return;
    }

    const std::string &path = songs[index]->getPath();
    if (!audioPlayer->openFromFile(path))
    {
        std::cout << "Failed to open sound file '" << path << "' (couldn't open stream)\n";
        isPlaying = false;
        return;
    }

    audioPlayer->play();
    currentIndexPlaying = index;
    isPlaying = true;
    std::cout << "Playing: " << songs[index]->getName() << "\n";
}

int MusicPlayer::getCurrentIndex() const
{
    return currentIndexPlaying;
}

bool MusicPlayer::isCurrentlyPlaying() const
{
    return isPlaying;
}