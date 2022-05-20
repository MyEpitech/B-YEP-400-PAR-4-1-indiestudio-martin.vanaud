/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-martin.vanaud
** File description:
** Audio
*/

#include "Audio.hpp"

RayLib::Audio::Audio()
{
}

RayLib::Audio::~Audio()
{
}

void RayLib::Audio::initAudioDevice()
{
    InitAudioDevice();
}

void RayLib::Audio::closeAudioDevice()
{
    CloseAudioDevice();
}

bool RayLib::Audio::isAudioDeviceReady()
{
    return (IsAudioDeviceReady());
}

void RayLib::Audio::setMasterVolume(float volume)
{
    SetMasterVolume(volume);
}

void RayLib::Audio::setAudioVolume(float volume)
{
    _audioVolume = volume;
}

float RayLib::Audio::getAudioVolume(void)
{
    return (_audioVolume);
}

void RayLib::Audio::setSoundVolume(float volume)
{
    _soundVolume = volume;
}

float RayLib::Audio::getSoundVolume(void)
{
    return (_soundVolume);
}