#ifndef _AUDIOCONTROLLER_H_
# define _AUDIOCONTROLLER_H_

# include "IAudio.hh"
# include "AudioCodec.h"
# include "AudioInput.h"
# include "AudioOutput.h"

class AudioController : public IAudio::AudioEvent
{
public:
	AudioController();
	~AudioController();

private:
	AudioController(const AudioController &) {};
	const AudioController &operator=(const AudioController &) {};

public:
	void	SoundEvent(IAudio *audio);
	void	player(const Sound::Encoded &);

public:


public:
	void	startPlay();
	void	stopPlay();
	void	startRecord();
	void	stopRecord();

private:
	IAudio		*inputD;
	IAudio		*outputD;
	ICodec		*codec;
};


#endif
