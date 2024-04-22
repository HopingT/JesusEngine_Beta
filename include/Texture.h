#pragma once
#include "Prerequisites.h"
class Device;
class DeviceContext;

/// <summary>
/// This class is in charge of generatting the textures to model (in this case in the cube)
/// </summary>
class
    Texture {

public:
    Texture() = default;
    ~Texture();
    /// <summary>
    /// The metod get the texture name 
    /// </summary>
    /// <param name="device"> look your device? </param>
    /// <param name="textureName"> look and get the texture name </param>
    void
        init(Device device, std::string textureName);

    /// <summary>
    /// The metod is in charge to establishing the dimensions and format of the textures 
    /// </summary>
    /// <param name="device"> look your device? </param>
    /// <param name="width"> Establish width textures</param>
    /// <param name="height"> Establish height textures</param>
    /// <param name="Format"> Establish format textures</param>
    /// <param name="BlindFlags"> ??? </param>
    void
        init(Device device,
            unsigned width,
            unsigned height,
            DXGI_FORMAT Format,
            unsigned int BlindFlags);

    void
        update();

    /// <summary>
    /// The metod renders the texture
    /// </summary>
    /// <param name="deviceContext"> The device context to be used for rendering </param>
    /// <param name="StarSlot"> The starting slot for rendering </param>
    void
        render(DeviceContext& deviceContext, unsigned int StarSlot, unsigned int NumViews);

    void
        destroy();

public:
    //The variable is in charge from handle a texture resource as data
    ID3D11Texture2D* m_texture = nullptr;

    //This variable is in charge of a handle texture resource as image data
    ID3D11ShaderResourceView* m_textureFromImg;

};