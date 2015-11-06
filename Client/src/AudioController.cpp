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

void	AudioController::SoundEvent(IAudio *audio)
{
//	Sound::Decoded sound;
	outputD->setBuffer((inputD->getBuffer()));
//	*inputD >> sound;
//	std::cout << sound.size << std::endl;
//	player(codec->encode(sound));
//	if (sound.size)
//		AudioController::SoundEvent(codec.encode(sound));
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