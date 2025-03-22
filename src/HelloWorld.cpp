#include <iostream>
#include "Window.h"

int main() {
	Window* window = new Window(1000, 1000, "HelloWorld", WindowMode::WINDOWED);
	while (window->isOpen()) {
		window->display();
	}

	delete window;
}