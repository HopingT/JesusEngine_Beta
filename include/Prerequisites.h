#pragma once
// std lib
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>

//External lib
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

//Windows 
#include <windows.h>

//Internal Includes
#include "Resource.h"

// MACRO for safe release of resources
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

// * To check monster
#define OutputLOG(_ClassName, _FunctionName, _OutputMessage)           \
OutputDebugStringA(_ClassName);                                        \
OutputDebugStringA(" : In Function : ");                               \
OutputDebugStringA(_FunctionName);                                     \
OutputDebugStringA(" : ");                                             \
OutputDebugStringA(OutputMessage);                                    \
OutputDebugStringA("\n");

#define WARNING( s )                         \
{                                            \
   std::wostringstream os;                  \
   os << s;                                 \
   OutputDebugStringW( os.str().c_str() );  \
}

struct SimpleVertex

{

    XMFLOAT3 Pos;

    XMFLOAT2 Tex;

};

struct LoadData
{
    std::string name;
    std::vector <SimpleVertex> vertex;
    std::vector <unsigned int> index;
    int numVertex;
    int numIndex;
};



struct Mesh {

    std::string name;

    std::vector <SimpleVertex> vertex;

    std::vector <unsigned int> index;

    int numVertex;

    int numIndex;

};