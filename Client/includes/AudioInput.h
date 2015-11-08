#ifndef _AUDIOINPUT_H_
# define _AUDIOINPUT_H_

# include <list>
# include "portaudio.h"
# include "IAudio.hh"

class AudioInput : public IAudio
{
public:
	AudioInput(void);
	~AudioInput(void);

private:
	AudioInput(const AudioInput &) {}
	const AudioInput &operator=(const AudioInput &) { return *this; }

public:
	void	initInputDevice(void);
	void	startStream(void);
	void	stopStream(void);

	IAudio  &operator<<(const Sound::Decoded &soundBuffer);
	IAudio  &operator>>(Sound::Decoded &soundBuffer);
	static int		callback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags Flags, void *userData);
	std::list<Sound::Decoded>		getBuffer();
	void							setBuffer(std::list<Sound::Decoded>) {};
	Sound::Decoded					getSound();

public:
	void	SetSoundEventListener(IAudio::AudioEvent *);

private:
	std::list<Sound::Decoded>		Buffers;
	PaStreamParameters				InputParam;
	PaStream						*Stream;
	bool							start;
	IAudio::AudioEvent				*Listen;
};

#endif
