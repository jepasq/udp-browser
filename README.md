# udp-browser

A web browser designed like a meta server.

## Dependencies

On arch-based GNU/linux distributions :

	sudo pacman -S cmake gcc qt5-base qt5-webview boost libarchive \
	     texlive-fontutils asio

on debian-based distributions (such as Ubuntu) :

    sudo apt-get install libarchive-dev qtbase5-dev qtchooser qt5-qmake \
	     qtbase5-dev-tools libqt5webview5-dev libboost-dev libboost1.74-dev \
		 libboost-test-dev asio

The texlive-related package is only used to provide the `epstopdf` executable,
which is needed to generate *API documentation* using `doxygen`.

## Building

This project use the now-standard *cmake* build system :

	mkdir build
	cd build/
	cmake ..
	make -j4

## Unit tests

Ont your in the `build/` directory :

	./tests

## API documentation

A *Doxyfile* `doxygen` input file is created by the cmake call. You can use it
to generate API documentation

	mkdir build
	cd build/
	cmake ..
	doxygen
	<your-favorite-browser> html/index.html

Regularly, yuo may want to upgrade `doxygen` configuration to a newer version.
To upgrade the file, run :

	doxygen -u Doxyfile.in
	
then, call again `cmake	..` from the *build/* directory.

## Browser homepage

The browser homepage, you see when opening the app is located in
*media/homepage* directory.
