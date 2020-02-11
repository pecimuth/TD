## Installation

### Build SFML

1.  Clone SFML repo: `git clone https://github.com/SFML/SFML.git`
2.  Checkout the 2.5.x tag, on which the game was developed: `cd SFML && git checkout 2.5.x`
1.  Open the folder in Visual Studio
2.  Click on the `CMakeLists.txt` file in Solution Explorer and build

### Build the game

1.  Open .sln file in Visual Studio
2.  In project properties:
*  In C++/General edit Additional Include Directiories, e.g. `C:\Users\Andrej\Documents\SFML-2.5.x\include;%(AdditionalIncludeDirectories)`
*  In Linker/General edit Additional Library Directories, e.g. `C:\Users\Andrej\Documents\SFML-2.5.x\out\build\x64-Debug\lib;%(AdditionalLibraryDirectories)`
3.  Either copy the SFML DLLs to a directory in PATH or edit Properties/Debugging/Environment like this `PATH=%PATH%;C:\Users\Andrej\Documents\SFML-2.5.x\out\build\x64-Debug\lib;C:\Users\Andrej\Documents\SFML-2.5.x\extlibs\bin\x64
$(LocalDebuggerEnvironment)`
4.  Hit F5 to build & launch
