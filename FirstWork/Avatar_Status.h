#pragma once

enum Avatar_Status {
	DEAD,
	GROUND,
	JUMP,
	CHASE,
	RETURN
};

struct zombie_status {
	bool detact_player = false;
	bool detact_wall = false;


};