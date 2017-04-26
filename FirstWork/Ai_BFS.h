#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include "Avatar_Status.h"
class Ai_BFS {
public:
	void raycasting(b2Vec2 origin_point, b2Vec2 end_point);
	void change_status(int a_obj_id, Action_Status &action_status);
	int* getObjId();
private:
	int* detacted_obj_id;
	sf::VertexArray bfs_verticies;
};