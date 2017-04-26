/*
AI and BFS

Descrpt: BFS table.
Change zombie's action status and run different function
*/

#include "Ai_BFS.h"
#include "global.h"
void Ai_BFS::raycasting(b2Vec2 origin_p, b2Vec2 end_p)
{

	//set up input
	b2RayCastInput input;
	input.p1 = origin_p;
	input.p2 = end_p;
	input.maxFraction = 1;

	//check every fixture of every body to find closest
	float closestFraction = 1; //start with end of line as p2
	b2Vec2 intersectionNormal(0, 0);
	b2Vec2 intersectionPoint(0, 0);
	for (b2Body* b = world->GetBodyList(); b; b = b->GetNext()) {
		for (b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext()) {

			b2RayCastOutput output;
			if (!f->RayCast(&output, input, 0))
				continue;
			if (output.fraction < closestFraction) {
				closestFraction = output.fraction;
				intersectionNormal = output.normal;
			}

			detacted_obj_id = (int*)(b->GetUserData());

		}
	}
	intersectionPoint = origin_p + closestFraction * (end_p - origin_p);

	bfs_verticies.append(sf::Vertex(sf::Vector2f(origin_p.x, origin_p.y)));
	bfs_verticies.append(sf::Vertex(sf::Vector2f(intersectionPoint.x, intersectionPoint.y)));
	if (closestFraction == 1)
		return; //ray hit nothing so we can finish here
	if (closestFraction == 0)
		return;	//still some ray left to reflect
}

void Ai_BFS::change_status(int a_obj_id, Action_Status &status_address) {
	Action_Status *status_ptr = &status_address;
	switch (a_obj_id)
	{
	case 1:
		*status_ptr = CHASE;
	case 2:
		*status_ptr = RETURN;
	}
}


int* Ai_BFS::getObjId() { return detacted_obj_id; }
