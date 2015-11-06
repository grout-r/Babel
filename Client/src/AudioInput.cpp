#include "AudioInput.h"
#include <iostream>
#include <cstring>

AudioInput::AudioInput() : Stream(NULL), start(false)
{
	if (Pa_Initialize() != paNoError)
		std::cout << "fail Initial" << std::endl;
	initInputDevice();
}

AudioInput::~AudioInput()
{
	stopStream();
	Pa_Terminate();
}

void	AudioInput::initInputDevice()
{
	InputParam.device = Pa_GetDefaultInputDevice();
	std::cout << InputParam.device << std::endl;
	if (InputParam.device == paNoDevice)
		std::cout << "error no device" << std::endl;
	InputParam.channelCount = CHANNEL;
	InputParam.hostApiSpecificStreamInfo = NULL;
	InputParam.suggestedLatency = Pa_GetDeviceInfo(InputParam.device)->defaultLowInputLatency;
	InputParam.sampleFormat = paFloat32;
}

void	AudioInput::startStream()
{
	if (start == false)
	{
		if (Pa_OpenStream(&Stream, &InputParam, NULL,  RATE, FRAMES, paClipOff, AudioInput::callback, this) != paNoError)
			std::cout << "error open Stream fail" << std::endl;
		if (Pa_StartStream(Stream) != paNoError)
			std::cout << "error start stream fail" << std::endl;
		start = true;
	}
	std::cout << "startstream" << std::endl;
}

void	AudioInput::stopStream()
{
	if (start == true)
	{
		if (Pa_CloseStream(Stream) != paNoError)
			std::cout << "error stop stream fail" << std::endl;
		start = false;
	}
}

IAudio	&AudioInput::operator<<(const Sound::Decoded &sound) { return (*this); }

IAudio	&AudioInput::operator>>(Sound::Decoded &sound)
{
	if (Buffers.size())
	{
		Sound::Decoded obj = Buffers.front();

		sound.buffer = obj.buffer;
		sound.size = obj.size;
		Buffers.pop_front();
	}
	else
		sound.size = 0;
	return (*this);
}

std::list<Sound::Decoded>		AudioInput::getBuffer()
{
	return (this->Buffers);
}

int	AudioInput::callback(const void *inputBuffer, void *outputBuffer, unsigned long frameCount, const PaStreamCallbackTimeInfo *timInfo, PaStreamCallbackFlags Flags, void *data)
{
	AudioInput *obj = reinterpret_cast<AudioInput *>(data);

	Sound::Decoded sound;
	sound.size = frameCount * CHANNEL;
	sound.buffer.assign(reinterpret_cast<const float *>(inputBuffer), reinterpret_cast<const float *>(inputBuffer) + frameCount * CHANNEL);
	obj->Buffers.push_back(sound);
	return paContinue;
}

void							AudioInput::SetSoundEventListener(IAudio::AudioEvent *lst)
{
	this->Listen = lst;
}

Sound::Decoded				AudioInput::getSound()
{
	Sound::Decoded			sound;
	
	sound = this->Buffers.front();
	this->Buffers.pop_front();
	return (sound);
}