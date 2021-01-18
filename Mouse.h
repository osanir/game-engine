#pragma once
#include <SFML/Window/Mouse.hpp>
#include <string>

class Mouse{
public:
	Mouse();

	/* Button basýlý tutulduðu sürece true döner. */
	bool onButtonDown(std::string button);
	bool onLeftButtonDown();
	bool onRightButtonDown();

	/* Button basýldýðýnda bir kere true döner. */
	bool onButtonClicked(std::string button);
	bool onLeftButtonClicked();
	bool onRightButtonClicked();

	// TODO: eklenecek on button released, is cursor over object vs 
private:

};

