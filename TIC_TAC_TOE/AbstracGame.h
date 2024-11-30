#pragma once

class AbstractGame {
public:
	/*Pure Virtual Function*/
	virtual void Play() = 0;

	/*Virtual Destructor for Polymorphism*/
	virtual ~AbstractGame() = default; 
};