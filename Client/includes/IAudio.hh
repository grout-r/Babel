#ifndef _IAUDIO_HH_
# define _IAUDIO_HH_

# include "Sound.hpp"
# include <list>

class IAudio
{
public:
	class AudioEvent 
	{
	public:
		virtual void	SoundEvent(IAudio *soundDevice) = 0;
	};

public:
	virtual ~IAudio(void) {}
public:
	virtual void	startStream(void) = 0;
	virtual void	stopStream(void) = 0;

	virtual IAudio	&operator<<(const Sound::Decoded &soundBuffer) = 0;
	virtual IAudio	&operator>>(Sound::Decoded &soundBuffer) = 0;
	virtual void    setBuffer(std::list<Sound::Decoded>		Buffers) = 0;
	virtual std::list<Sound::Decoded>		getBuffer() = 0;

	virtual void	SetSoundEventListener(IAudio::AudioEvent *listener) = 0;

};

#endif