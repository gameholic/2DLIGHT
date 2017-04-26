#pragma once
#include <Box2D\Box2D.h>
#include "GameData.h"

//
//typedef void(*collision_handler)();
//collision_handler collision_table[10][10] = { nullptr, };

//
/////////////////////////////////
////Why thses functions should place here
/////////////////////////////////
//void human_zombie_collide();
//void human_ground_collide();
//void zombie_ground_collide();
//
//class MyContactListener : public b2ContactListener
//{
//public:
//	void BeginContact(b2Contact* contact);
//	void EndContact(b2Contact* contact);
//
//};

class Collision_Detaction:public b2ContactListener
{
public:
	Collision_Detaction(GameData* a_gameData);

	void human_zombie_collide();
	void human_ground_collide();
	void zombie_ground_collide();
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);


	//////////////////////////////////
	//(Collision_Detction::)�� ȣ�� �Ծ࿡�� this call �̶�°� �˷���.
	//�Ⱦ��� cdecal ���� ��. �ڼ��ѳ����� ī��Ȯ��
	//////////////////////////////////
	typedef void(Collision_Detaction::*collision_handler)();
	
	
	collision_handler collision_table[10][10] = { nullptr, };
	//////////////////////////////////
	//////////////////////////////////
private:
	GameData* game_data;
};