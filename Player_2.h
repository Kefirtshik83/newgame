#pragma once
#include "Player1.h"
class Player2: public Player1
{
public:
	Player2();
	void control() override;
};