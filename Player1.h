#pragma once
class Player1
{
protected:
	int len;
	int y;
	int d;
public:
	int get_len() const;
	int get_y() const;
	int get_d() const;
	void y_up(int x);
};