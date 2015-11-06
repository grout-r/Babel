#include "AudioOutput.h"
#include <iostream>

AudioOutput::AudioOutput() : Stream(NULL), start(false)
{
	if (Pa_Initialize() != paNoError)
		std::cout << "fail Initial" << std::endl;
	initOutputDevice();
}

AudioOutput::~AudioOutput()
{
	stopStream();
	Pa_Terminate();
}

void					AudioOutput::initOutputDevice()
{
	OutputParam.device = Pa_GetDefaultOutputDevice();
	if (OutputParam.device == paNoDevice)
		std::cout << "error no device" << std::endl;
	OutputParam.channelCount = CHANNEL;
	OutputParam.hostApiSpecificStreamInfo = NULL;
	OutputParam.suggestedLatency = Pa_GetDeviceInfo(OutputParam.device)->defaultLowOutputLatency;
	OutputParam.sampleFormat = paFloat32;
}

void					AudioOutput::startStream()
{
	if (start == false)
	{
		if (Pa_OpenStream(&Stream, NULL, &OutputParam, RATE, FRAMES, paClipOff, AudioOutput::callback, this) != paNoError)
			std::cout << "error open stream fail" << std::endl;
		if (Pa_StartStream(Stream) != paNoError)
			std::cout << "error start stream fail" << std::endl;
		start = true;
	}
}

void					AudioOutput::stopStream()
{
	if (start == true)
	{
		if (Pa_CloseStream(Stream) != paNoError)
			std::cout << "error close stream fail" << std::endl;
		start = false;
	}
}

IAudio					&AudioOutput::operator<<(const Sound::Decoded &sound)
{
	if (sound.size)
	{
		Sound::Decoded obj;
		obj.buffer = sound.buffer;
		obj.size = sound.size;
		Buffers.push_back(obj);
	}
	return (*this);
}

IAudio					&AudioOutput::operator>>(Sound::Decoded &) { return (*this); }

void					AudioOutput::setBuffer(std::list<Sound::Decoded> obj)
{
	this->Buffers = obj;
}


int						AudioOutput::callback(const void *inputBuffer, void *outputBuffer, unsigned long frameCount, const PaStreamCallbackTimeInfo *timInfo, PaStreamCallbackFlags Flags, void *data)
{
	AudioOutput *obj = reinterpret_cast<AudioOutput *>(data);

	if (obj->Buffers.size() == 0)
	{
		return paContinue;
	}
	Sound::Decoded sound = obj->Buffers.front();
	float *pt = static_cast<float *>(outputBuffer);

	for (int i = 0; i < sound.size; i++)
		*pt++ = sound.buffer[i];
	obj->Buffers.pop_front();
	return paContinue;
}

void					AudioOutput::SetSoundEventListener(IAudio::AudioEvent *) {}