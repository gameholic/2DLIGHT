#include "GameData.h"

/*
GameData.cpp
Descript: save objs int the game. kind of bridge that lead to 
different avatar or object informations and enable to use them*/
int GameData::zombie_count;
GameData::GameData()
	:  _zombie(new zombie*[MAX_ZOMBIE_NUMBER]),
	_player (new Player*){}

void GameData::setIndex(int index) { zombie_index = index; }
int GameData::getIndex() { return zombie_index; }
void GameData::setZombie(zombie* zombie_ptr)
{ 
	*(_zombie + zombie_count) = zombie_ptr; 
	zombie_count++;
}
zombie* GameData::getZombie(int index) { return *(_zombie + (index)); }

void GameData::setPlayer(Player* player_ptr) {*_player = player_ptr; }
Player* GameData::getPlayer() { return *_player; }

void GameData::setPlayerStatus(Physical_Status a_status)
{
	(*_player)->setStatus(a_status);
}
Physical_Status GameData::getPlayerStatus() { return (*_player)->getStatus(); }

void GameData::setZombiePhysicalStatus(Physical_Status a_status)
{
	(*_zombie + (zombie_index))->setPhysicalStatus(a_status);
}
Physical_Status GameData::getZombiePhysicalStatus(int a_index) { return (*_zombie+(a_index))->getPhysicalStatus(); }

void GameData::setZombieActionStatus(Action_Status a_status)
{
	(*_zombie + (zombie_index))->setActionStatus(a_status);
}
Action_Status GameData::getZombieActionStatus(int a_index) { return (*_zombie + (a_index))->getActionStatus(); }


