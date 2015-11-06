#ifndef _AUDIOOUTPUT_H_
# define _AUDIOOUTPUT_H_

# include <list>
# include "portaudio.h"
# include "IAudio.hh"

class AudioOutput : public IAudio 
{
public:
	AudioOutput(void);
	~AudioOutput(void);

private:
	AudioOutput(const AudioOutput &) {}
	const AudioOutput &operator=(const AudioOutput &) { return *this; }

public:
	void	initOutputDevice(void);
	void	startStream(void);
	void	stopStream(void);

	IAudio  &operator<<(const Sound::Decoded &soundBuffer);
	IAudio  &operator>>(Sound::Decoded &soundBuffer);
	static int		callback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags Flags, void *userData);
	void			setBuffer(std::list<Sound::Decoded> obj);
	std::list<Sound::Decoded>		getBuffer() { return (this->Buffers); };

public:
	void	SetSoundEventListener(IAudio::AudioEvent *);

public:
	std::list<Sound::Decoded>		Buffers;
	PaStreamParameters				OutputParam;
	PaStream						*Stream;
	bool							start;
};

#endif