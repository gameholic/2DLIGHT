#pragma once
/*
zombieAI.h
*/
#include <Box2D\Box2D.h>

#include "GameData.h"
#include "zombie.h"
#include "movement.h"
#include "zombieRule.h"
#include "ZombieAI_Chase.h"
//struct zombie_status {
//	bool detact_player = false;
//	bool detact_wall = false;
//	
//
//};

class zombieAI {
public:
	zombieAI(GameData* gamedata, movement move);
	void defaultPatrol(b2Body* z_body, zombie* zombie, b2Vec2 speed);
	
	void rayCasting(b2Vec2 p1, b2Vec2 p2);


	void zombie_AI(b2Body* p_body);
	void chase(b2Body* z_body, b2Body* p_body);
	sf::VertexArray* getVertices();

	void runToGoal(b2Body* zombie, b2Vec2 position);
	//void zombieStatus(b2Body* z_body, b2Body* p_body);
	//void setIndex(int index);
	int* get_value();
	zombie_status status;


private:
	movement move;
	zombieRule rule;
	GameData* gameData;
	float rayLength = 50;
	sf::VertexArray vertices;
	int* _value = (int*)5;
	ZombieAI_Chase _Chase;
};