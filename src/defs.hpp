#pragma once

/*	
	-> Gameplay speed = 25 loop ticks/sec
*/

#define WIDTH 1024
#define HEIGHT 500

#define playerTexture "sprites/playerShip.png"
#define playerHP 10
#define playerBulletSpeed 30

#define enemyTexture "sprites/enemyShip.png"
#define enemyHP 5
#define enemySpeed -5
#define enemyBulletSpeed -15

#define bulletHP 1

#define normalBulletTexture "sprites/blueLaser.png"
#define waveBulletTexture "sprites/waveBullet.png"
#define enemyBulletTexture "sprites/redLaser.png"


#define powerUpSPD 6
#define bonusHPTexture "sprites/bonusHP.png"
#define enchanceAttackTexture "sprites/enchanceATK.png"

#define explosionTexture "sprites/explosion.png"

#define titleScreenTexture "sprites/titleScreen.png"
#define endScreenTexture "sprites/endScreen.png"
#define icon "sprites/icon.png"
#define backgroundTexture "sprites/background2.jpg"//background.jpg for shorter background

#define soundChannel 5
#define fireSound "sound/laser.ogg"
#define explosionSound "sound/explosion.ogg"
#define bgSound "sound/background.mp3"
#define btSound "sound/button.ogg"

enum{
	pPlane,
	ePlane,
	ePlane2,
	eBullet,
	shipDebris,
	bonusHP,
	enchanceATK,
};

enum{
	normalBullet,
	waveBullet
};

enum{
	CH_MUSIC,
	CH_MENU,
	CH_PLAYER,
	CH_ENEMY,
	CH_OTHER
};

enum{
	SOUND_FIRE,
	SOUND_EXPLOSION,
	SOUND_BUTTON
};