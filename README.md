# Basic OpenCV FMT by using VCPKG packet manager

I try to convert my python opencv, flask to CXX codebases. This is the basic project template.

**Requirement:**
- Package Manager: VCPKG
- Compiler: MSVC 17 2022
- Generator: Ninja 
- Build Tools: CMake
- Text Editor: VS Code
    - Extension: CMake by Microsoft 
- Code Completion: Clangd (optional but i use this)

### On Ubuntu or Debian
1. Install Build Essentials: Get the C++ compiler (g++), make, and CMake itself.
    ```bash
    sudo apt update
    sudo apt install build-essential cmake pkg-config
    ```
2. Install OpenCV: Install the development headers and libraries for the modules your project uses (core, highgui, videoio).
    ```bash
    sudo apt install libopencv-dev
    ```
3. Install fmt: Install the development files for the fmt library.
    ```bash
    sudo apt install libfmt-dev
    ```