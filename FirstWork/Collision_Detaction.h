#pragma once
#include <Box2D\Box2D.h>
#include "GameData.h"

class Collision_Detaction : public b2ContactListener
{
public:
	Collision_Detaction(GameData* a_gameData);
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);


	////////////////////////////////////
	////////////////////////////////////
	void human_zombie_collide();
	void human_ground_collide();
	void zombie_ground_collide();
private:
	typedef void(*collision_handler)();
	collision_handler collision_table[10][10] = { nullptr, };
	GameData* game_data;
};