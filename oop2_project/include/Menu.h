#include "Resources.h"
#include "MenuCommand.h"
#include "Button.h"

//#include <pair>


//typedef pair<int, unique_ptr<MenuCommand>> option;

class Menu {

public:
	Menu();
	~Menu() {}

	void activate(sf::RenderWindow &window);

private:
	//vector<option> m_options;
	std::vector<std::unique_ptr<Button>> m_buttons;

	void show(sf::RenderWindow &window);
	//int getOptionFromUser();
	//bool performAction(unsigned n);

};