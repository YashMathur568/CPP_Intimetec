#include "MusicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer()
    : currentPlaylist(nullptr), currentIndex(-1), isPlaying(false) {}

void MusicPlayer::selectPlaylist(IPlaylist *playlist)
{
    currentPlaylist = playlist;
    currentIndex = 0;
    isPlaying = false;
}

void MusicPlayer::playOrPause()
{
    if (sfMusic.getStatus() == sf::Music::Playing)
    {
        sfMusic.pause();
        isPlaying = false;
        std::cout << "Paused\n";
    }
    else if (sfMusic.getStatus() == sf::Music::Paused)
    {
        sfMusic.play();
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
        return;
    auto &songs = currentPlaylist->getSongs();

    if (currentIndex + 1 < (int)songs.size())
    {
        currentIndex++;
        if (sfMusic.openFromFile(songs[currentIndex]->getPath()))
        {
            sfMusic.play();
            isPlaying = true;
            std::cout << "Playing: " << songs[currentIndex]->getName() << "\n";
        }
    }
}

void MusicPlayer::prevSong()
{
    if (!currentPlaylist)
        return;
    auto &songs = currentPlaylist->getSongs();

    if (currentIndex - 1 >= 0)
    {
        currentIndex--;
        if (sfMusic.openFromFile(songs[currentIndex]->getPath()))
        {
            sfMusic.play();
            isPlaying = true;
            std::cout << "Playing: " << songs[currentIndex]->getName() << "\n";
        }
    }
}

ISong *MusicPlayer::getCurrentSong() const
{
    if (!currentPlaylist)
        return nullptr;
    auto &songs = currentPlaylist->getSongs();
    if (currentIndex >= 0 && currentIndex < (int)songs.size())
    {
        return songs[currentIndex];
    }
    return nullptr;
}

void MusicPlayer::playAtIndex(const std::vector<ISong *> &songs, int index)
{
    if (index < 0 || index >= (int)songs.size())
    {
        std::cout << "Invalid song index.\n";
        return;
    }
    const std::string &path = songs[index]->getPath();
    if (!sfMusic.openFromFile(path))
    {
        std::cout << "Failed to open sound file '" << path << "' (couldn't open stream)\n";
        isPlaying = false;
        return;
    }
    sfMusic.play();
    currentIndex = index;
    isPlaying = true;
    std::cout << "Playing: " << songs[index]->getName() << "\n";
}

int MusicPlayer::getCurrentIndex() const
{
    return currentIndex;
}

bool MusicPlayer::isCurrentlyPlaying() const
{
    return isPlaying;
}
