#pragma once
#include <SFML\Graphics.hpp>

#include "zombie.h"
#include "Player.h"
//#include "loadImage.h"

#define MAX_ZOMBIE_NUMBER 3
class GameData {
public:
	GameData();

	void setPlayer(Player* player);
	Player* getPlayer();

	void setZombie(zombie* zombie_ptr);
	zombie* getZombie(int a_index);

	void setPlayerStatus(Physical_Status a_status);
	Physical_Status getPlayerStatus();
	void setZombiePhysicalStatus(Physical_Status a_status);
	Physical_Status getZombiePhysicalStatus(int a_index);
	void setZombieActionStatus(Action_Status a_status);
	Action_Status getZombieActionStatus(int a_index);
	void setIndex(int index);
	int getIndex();
	

	static int zombie_count;

private:
	Player** _player;
	zombie** _zombie;
	//loadImage load_Image;
	int zombie_index;
	sf::Sprite tmp_Sprite;
	sf::Texture tmp_Texture;
	
};