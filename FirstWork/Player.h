#pragma once
/*
player.h
*/
#include "AvatarProperty.h"
#include "loadImage.h"
#include "Avatar_Status.h"


class Player {

public:
	Player(float _x, float _y, float _density, float _friction);
	Player();
	sf::Sprite *getSprite();
	sf::Texture getTexture();
	void setBody(b2BodyType bodyType, bool fixRotation);
	b2Body* getBody();
	void setStatus(Avatar_Status a_Status);
	Avatar_Status getStatus();

private:
	b2Body* plyBody;
	AvatarProperty plyProperty;
	Avatar_Status currentStatus;
	loadImage imageLoad;
	sf::Sprite plySprite;
	sf::Texture plyTexture;
};