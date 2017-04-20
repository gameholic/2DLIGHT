#include "ZombieAI_Chase.h"
ZombieAI_Chase::ZombieAI_Chase(movement a_move)
:move(a_move){

}
void ZombieAI_Chase::chase(b2Body * z_body, b2Body * p_body, zombie_status status)
{
	b2Vec2 zombie_position = z_body->GetPosition();
	b2Vec2 dest_position = p_body->GetPosition();
	moveDir tmp_x_dir, tmp_y_dir;
	do
	{
		tmp_x_dir = x_chase(zombie_position, dest_position);
		tmp_y_dir = y_chase(zombie_position, dest_position);
		move.moveZombie_default(z_body, tmp_x_dir);
		if (status.detact_wall)
			move.moveZombie_default(z_body, tmp_y_dir);
	} while (zombie_position == dest_position);
}


moveDir ZombieAI_Chase::x_chase(b2Vec2 start_position, b2Vec2 dest_position)
{
	if (dest_position.x - start_position.x > 0)
		return RIGHT;
	else if (dest_position.x - start_position.x < 0)
		return LEFT;
}

moveDir ZombieAI_Chase::y_chase(b2Vec2 start_position, b2Vec2 dest_position)
{
	if (dest_position.x - start_position.x < 32.f)
		return SAMEFLOOR;
	else
		return UP;
}