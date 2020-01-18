#include "Player.hpp"

Player::Player(){
	up = left = down = right = fire = die = false;
	reload = 0;
	speed = 10;
	bulletType = ammo = enterGame = 0;
}

void Player::move(){
	if(up && left){
		dx = dy = -speed;
	}else if(up && right){
		dx = speed;
		dy = -speed;
	}else if(down && left ){
		dx = -speed;
		dy = speed;
	}else if(down && right){
		dx = dy = speed;
	}else if(up){
		dy = -speed;
	}else if(down){
		dy = speed;
	}else if(left){
		dx = -speed;
	} else if(right){
		dx = speed;
	}
	x = (x + dx < 0 ? 0 : (x + dx > 950 ? 950 : x + dx));
	y = (y + dy < 0 ? 0 : (y + dy > 396 ? 396 : y + dy));
	dx = dy = 0;
}

void Player::keyDown(SDL_KeyboardEvent *event){
	if(!(event->repeat)){
		switch(event->keysym.scancode){
		case SDL_SCANCODE_W:
		case SDL_SCANCODE_UP:
			up = true;
			break;
		case SDL_SCANCODE_S:
		case SDL_SCANCODE_DOWN:
			down = true;
			break;
		case SDL_SCANCODE_A:
		case SDL_SCANCODE_LEFT:
			left = true;
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			right = true;
			break;
		case SDL_SCANCODE_LSHIFT:
			fire = true;
			break;
		}
	}
}

void Player::keyUp(SDL_KeyboardEvent *event){
	if(!(event->repeat)){
		switch(event->keysym.scancode){
		case SDL_SCANCODE_W:
		case SDL_SCANCODE_UP:
			up = false;
			break;
		case SDL_SCANCODE_S:
		case SDL_SCANCODE_DOWN:
			down = false;
			break;
		case SDL_SCANCODE_A:
		case SDL_SCANCODE_LEFT:
			left = false;
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			right = false;
			break;
		case SDL_SCANCODE_LSHIFT:
			fire = false;
			break;
		}
	}
}

void Player::updateAmmo(int ammo){
	this->ammo += ammo;
}

void Player::setReload(int reload){
	this->reload = reload;
}

void Player::setBulletType(int type){
	this->bulletType = type;
}

void Player::setEnterStatus(bool status){
	this->enterGame = status;
}

void Player::setDieStatus(bool status){
	this->die = status;
}

int Player::getAmmo(){
	return ammo;
}

int Player::getReload(){
	return reload;
}

int Player::getBulletType(){
	return bulletType;
}

bool Player::fireStatus(){
	return fire;
}

bool Player::enterStatus(){
	return enterGame;
}

bool Player::died(){
	return die;
}

void Player::resetInput(){
	left = up = right = down = fire = false;
}