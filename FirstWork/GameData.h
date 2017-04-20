#pragma once
#include <SFML\Graphics.hpp>

#include "zombie.h"
#include "Player.h"
//#include "loadImage.h"

#define MAX_ZOMBIE_NUMBER 3
class GameData {
public:
	GameData();
	GameData(int i);

	void setPlayer(Player* player);
	Player* getPlayer();

	void setZombie(zombie* zombie_ptr);
	zombie* getZombie(int a_index);

	void setPlayerStatus(Avatar_Status a_status);
	Avatar_Status getPlayerStatus();
	void setZombieStatus(Avatar_Status a_status);
	Avatar_Status getZombieStatus(int a_index);
	void setIndex(int index);

	int getIndex();
	

	static int zombie_count;

private:
	Avatar_Status player_status;
	Avatar_Status zombie_status;
	Player** _player;
	zombie** _zombie;
	//loadImage load_Image;
	int zombie_index;
	sf::Sprite tmp_Sprite;
	sf::Texture tmp_Texture;
	
};