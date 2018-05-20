#pragma once
#include <vector>
#include <SFML/Graphics/Rect.hpp>

#include "Animation.h"

class AnimationHandler
{
private:
	std::vector<Animation> animations;

	float t;

	int currentAnim;

public:
	AnimationHandler()
	{
		this->t = 0.0f;
		this->currentAnim = -1;
	}

	AnimationHandler(const sf::IntRect& frameSize) : AnimationHandler()
	{
		this->frameSize = frameSize;
	}

	~AnimationHandler();

	void addAnim(Animation& anim);

	/* Update the current frame of animation. dt is the time since
	 * the update was last called (i.e. the time for one frame to be
	 * executed) */
	void update(const float dt);

	void changeAnim(unsigned int animNum);

	/* Current section to the texture that should be displayed */
	sf::IntRect bounds;

	/* Pixel dimensions of each individual frame */
	sf::IntRect frameSize;
};

