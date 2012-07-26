cmake_minimum_required (VERSION 2.6)
project (PONG)

set (PONG_SRCS Pong.cpp Event.cpp Pong_Events.cpp FPS.cpp Surface.cpp Ball.cpp Bar.cpp AI.cpp)

Find_Package ( SDL REQUIRED )
Find_Package ( SDL_image REQUIRED )

link_libraries (
   ${SDL_LIBRARY}
   ${SDLIMAGE_LIBRARY}
   SDLmain # Sadly not included in SDL_LIBRARY variable
)

add_executable (Pong
	       WIN32
	       MACOSX_BUNDLE     
	       ${PONG_SRCS})

