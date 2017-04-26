#include "Player.h"
#include "global.h"

/*
Player.cpp
Descript: Include all data about player using AvatarProperty.cpp and enable other classes to get information.
*/
Player::Player( float _x, float _y, float _density, float _friction) 
{
 	plySprite = imageLoad.getPlyrSprite();
	plyTexture = imageLoad.getCharTexture();
	
	float _width = plySprite.getScale().x*plyTexture.getSize().x / 2;
	float _height = plySprite.getScale().y*plyTexture.getSize().y / 2;
	p_txt.setFont(font);
	p_txt.setString("STATUS");
	p_txt.setScale(sf::Vector2f(0.5f, -1));
	plyProperty.setPosition(_x, _y);
	plyProperty.setBoxSize(_width, _height);
	plyProperty.setPhysics(_density, _friction);

}
Player::Player()
{

}

sf::Texture Player::getTexture() {
	return plyTexture;
}

sf::Sprite *Player::getSprite() {
	return &plySprite;
}

void Player::setBody(b2BodyType bodyType, bool fixRotation) {
	b2BodyDef bodyDef;
	b2PolygonShape dynamicBox;
	b2FixtureDef fixtureDef;

	bodyDef.type = bodyType;
	bodyDef.position.Set(plyProperty.getPosition().x, 
		plyProperty.getPosition().y);

	plyBody = world->CreateBody(&bodyDef);

	dynamicBox.SetAsBox(plyProperty.getBoxSize('w'),
		plyProperty.getBoxSize('h'));
	fixtureDef.shape = &dynamicBox;

	fixtureDef.density = plyProperty.getPhysics('d');
	fixtureDef.friction = plyProperty.getPhysics('f');

	plyBody->CreateFixture(&fixtureDef);

	plyBody->SetUserData((int*)1);
	if (fixRotation)
		plyBody->SetFixedRotation(0x0010);
}

b2Body* Player::getBody() {
	return plyBody;

}

void Player::setStatus(Physical_Status a_status)
{
	currentStatus = a_status;
}
Physical_Status Player::getStatus()
{
	return currentStatus;
}

sf::Text *Player::getText()
{
	return &p_txt;
}