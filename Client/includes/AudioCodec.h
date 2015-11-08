#ifndef _AUDIOCODEC_H_
# define _AUDIOCODEC_H_

# include "ICodec.h"
# include "opus.h"
# include "Sound.hpp"

class AudioCodec : public ICodec
{
public:
	AudioCodec();
	~AudioCodec();

private:
	AudioCodec(const AudioCodec &) {};
	const AudioCodec &operator=(const AudioCodec &) { return *this; };

public:
	Sound::Encoded	encode(const Sound::Decoded &sound);
	Sound::Decoded	decode(const Sound::Encoded &sound);

private:
	OpusEncoder *encoder;
	OpusDecoder *decoder;
};

#endif
