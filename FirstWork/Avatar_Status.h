#pragma once

enum Physical_Status {
	DEAD,
	GROUND,
	JUMP,
	TEST
};
enum Action_Status {
	DEFAULT,
	CHASE,
	RETURN
};
struct zombie_status {
	bool detact_player = false;
	bool detact_wall = false;


};