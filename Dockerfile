FROM epitechcontent/epitest-docker

WORKDIR /Bomberman

COPY cmake/ cmake/
COPY include/ include/
COPY src/ src/
COPY CMakeLists.txt ./

RUN "mkdir build && cd build"
RUN "cmake .. -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Release"
RUN "cmake --build ."
RUN "cd -"