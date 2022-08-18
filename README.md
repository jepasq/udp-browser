# udp-browser

A web browser designed like a meta server

## Dependencies

On arch-based GNU/linux distributions :

	sudo pacman -S cmake gcc qt5-base qt5-webview boost

on  debian-based distributions (such as Ubuntu) :

    sudo apt-get install qt5-default qtbase5-dev

## Building

	mkdir build
	cd build/
	cmake ..
	make -j4
