#include "AudioController.h"
#include <iostream>

AudioController::AudioController(void)
	: inputD(NULL), outputD(NULL)
{
	inputD = new AudioInput;
	outputD = new AudioOutput;
	codec = new AudioCodec;
}

AudioController::~AudioController(void)
{
	if (inputD)
		delete inputD;
	if (outputD)
		delete outputD;
}

void	AudioController::player(const Sound::Encoded &sound)
{
	*outputD << codec->decode(sound);
}

Sound::Encoded	AudioController::SoundEvent()
{
	Sound::Decoded sound;

	*inputD >> sound;
	return (codec->encode(sound));
}

void	AudioController::startRecord(void)
{
	inputD->startStream();
}

void	AudioController::stopRecord(void)
{
	inputD->stopStream();
}

void	AudioController::startPlay(void)
{
	outputD->startStream();
}

void	AudioController::stopPlay(void)
{
	outputD->stopStream();
}
