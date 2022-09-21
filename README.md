# udp-browser

A web browser designed like a meta server.

## Dependencies

On arch-based GNU/linux distributions :

	sudo pacman -S cmake gcc qt5-base qt5-webview boost libarchive

on debian-based distributions (such as Ubuntu) :

    sudo apt-get install qt5-default qtbase5-dev libarchive-dev

## Building

This project use the now-standard *cmake* build system :

	mkdir build
	cd build/
	cmake ..
	make -j4
