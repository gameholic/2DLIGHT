#pragma once
#include <Box2D\Box2D.h>
#include "movement.h"
#include "Avatar_Status.h"

class ZombieAI_Chase {
public:
	ZombieAI_Chase(movement a_move);
	void chase(b2Body* z_body, b2Body* p_body, zombie_status status);
	moveDir x_chase(b2Vec2 start_position, b2Vec2 dest_position);
	moveDir y_chase(b2Vec2 start_position, b2Vec2 dest_position);
private:
	movement move;

};