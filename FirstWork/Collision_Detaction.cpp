#include "Collision_Detaction.h"


Collision_Detaction::Collision_Detaction(GameData* a_gameData) :
	game_data(a_gameData)
{
	//////////////////////////////////////////
	//ERRORRRRRRRR
	//collision_table[1][0] = collision_table[0][1] = human_ground_collide;
	//collision_table[1][2] = collision_table[2][1] = human_zombie_collide;
	//////////////////////////////////////////
}

void Collision_Detaction::BeginContact(b2Contact* contact)
{
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();

	if (bodyUserData)
	{
	}

	void* bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData2)
	{
	}

	collision_handler handler = collision_table[(int)bodyUserData][(int)bodyUserData2];

	if (handler != nullptr)
		handler();
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();
	b2Body* body1 = fixtureA->GetBody();
	b2Body* body2 = fixtureB->GetBody();
}

void Collision_Detaction::EndContact(b2Contact* contact)
{

}

/////////////////////////////////

void Collision_Detaction::human_zombie_collide()
{
	game_data->getPlayer()->setStatus(DEAD);
}

void Collision_Detaction::human_ground_collide()
{
	game_data->getPlayer()->setStatus(GROUND);
}

void Collision_Detaction::zombie_ground_collide()
{
	//game_data->getZombie()->setStatus(GROUND);
}