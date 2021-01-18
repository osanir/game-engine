#pragma once
#include <SFML/Window/Mouse.hpp>
#include <string>

class Mouse{
public:
	Mouse();

	/* Button bas�l� tutuldu�u s�rece true d�ner. */
	bool onButtonDown(std::string button);
	bool onLeftButtonDown();
	bool onRightButtonDown();

	/* Button bas�ld���nda bir kere true d�ner. */
	bool onButtonClicked(std::string button);
	bool onLeftButtonClicked();
	bool onRightButtonClicked();

	// TODO: eklenecek on button released, is cursor over object vs 
private:

};

