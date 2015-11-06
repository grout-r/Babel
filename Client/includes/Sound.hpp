#ifndef _SOUND_HPP_
# define _SOUND_HPP_

# include <vector>


# define CHANNEL  2
# define FRAMES 480
# define RATE 48000

namespace Sound
{	
	struct Encoded {
		std::vector<unsigned char> buffer;
		int	size;
	};

	struct Decoded {
		std::vector<float> buffer;
		int	size;
	};
};

#endif