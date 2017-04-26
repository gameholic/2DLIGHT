#include "movement.h"
#include "global.h"
#include <SFML\Graphics.hpp>
/*
movement.cpp
Descript: Codes that moves the avatar. Basic orders are written and helps
other functions to move characters easily. Made to avoid redundancy*/

movement::movement() {}
movement::movement(GameData* gamedata)
	:gameData(gamedata){}
void movement::movePlayer(b2Body* body, moveDir dir)
{
	if (dir == LEFT)
	{
		if (body->GetLinearVelocity().x == HAULT)
			body->SetLinearVelocity(b2Vec2(-10, body->GetLinearVelocity().y));
		if (body->GetLinearVelocity().x < -(MAX_SPEED))
			body->SetLinearVelocity(b2Vec2(-(MAX_SPEED), body->GetLinearVelocity().y));
		else
			body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x - 1, body->GetLinearVelocity().y));

	}
	else if (dir == RIGHT)
	{
		if (body->GetLinearVelocity().x == HAULT)
			body->SetLinearVelocity(b2Vec2(NORMAL_SPEED, body->GetLinearVelocity().y));
		else if (body->GetLinearVelocity().x > MAX_SPEED)
			body->SetLinearVelocity(b2Vec2(MAX_SPEED, body->GetLinearVelocity().y));
		else
			body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x + 1, body->GetLinearVelocity().y));
	}
	else if(dir == UP)
	{
		body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, _JUMP));
	}

}


void movement::moveZombie(b2Body*body, b2Vec2 speed)
{
	body->SetLinearVelocity(speed);
}
void movement::jumpZombie(b2Body * body)
{
	moveZombie(body, b2Vec2(body->GetLinearVelocity().x, 60));
}
void movement::moveZombie_default(b2Body* body, moveDir dir)
{

	sf::Text* txt = gameData->getZombie(_index)->getText();
	switch (dir)
	{
	case LEFT:
		moveZombie(body,(b2Vec2(-(MAX_SPEED), body->GetLinearVelocity().y)));
		txt->setString("MOVE_LEFT");
		break;
	case RIGHT:
		moveZombie(body, (b2Vec2(MAX_SPEED, body->GetLinearVelocity().y)));
		txt->setString("MOVE_RIGHT");
		break; 
	case UP:
		jumpZombie(body);
		txt->setString("JUMP");
		break;
	}
}

void movement::moveZombie_chase(b2Body* body, moveDir dir)
{

	sf::Text* txt = gameData->getZombie(_index)->getText();
	switch (dir)
	{
	case LEFT:
		moveZombie(body,(b2Vec2(-(CHASE_PLAYER), body->GetLinearVelocity().y)));
		txt->setString("CHASE_LEFT");
		break;
	case RIGHT:
		moveZombie(body, (b2Vec2(CHASE_PLAYER, body->GetLinearVelocity().y)));
		txt->setString("CHASE_RIGHT");
		break; 
	case UP:
		jumpZombie(body);
		txt->setString("CHASE_JUMP");
		break;
	}
}

void movement::moveZombie_setSpeed(b2Body * body, moveDir dir, b2Vec2 speed)
{
	sf::Text* txt = gameData->getZombie(_index)->getText();
	switch (dir)
	{
	case LEFT:
		speed.x = -(speed.x);
		moveZombie(body,speed);
		txt->setString("MOVE_LEFT_BOOST");
		break;
	case RIGHT:
		moveZombie(body, speed);
		txt->setString("MOVE_RIGHT_BOOST");
		break;
	}
}

void movement::setIndex(int index)
{
	_index = index;
}
