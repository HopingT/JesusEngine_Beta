#pragma once
#include "Prerequisites.h"
class Device;
class DeviceContext;

/// <summary>
/// Represents a texture, which can be used for rendering purposes.
/// </summary>
class Texture {

public:
    Texture() = default;
    ~Texture();

    /// <summary>
    /// Initializes the texture using the provided Device and texture name.
    /// </summary>
    /// <param name="device">Device object used for initialization.</param>
    /// <param name="textureName">Name of the texture.</param>
    void init(Device device, std::string textureName);

    /// <summary>
    /// Initializes the texture with the specified width, height, format, and flags using the provided Device.
    /// </summary>
    /// <param name="device">Device object used for initialization.</param>
    /// <param name="width">Width of the texture.</param>
    /// <param name="height">Height of the texture.</param>
    /// <param name="Format">Format of the texture.</param>
    /// <param name="BlindFlags">Flags for the texture.</param>
    void init(Device device,
        unsigned width,
        unsigned height,
        DXGI_FORMAT Format,
        unsigned int BlindFlags);

    /// <summary>
    /// Updates the texture.
    /// </summary>
    void update();

    /// <summary>
    /// Renders the texture using the specified device context and slot.
    /// </summary>
    /// <param name="deviceContext">DeviceContext object used for rendering.</param>
    /// <param name="StarSlot">Starting slot for rendering.</param>
    void render(DeviceContext& deviceContext, unsigned int StarSlot);

    /// <summary>
    /// Destroys the texture instance.
    /// </summary>
    void destroy();

public:
    // The variable is responsible for handling a texture resource as data.
    ID3D11Texture2D* m_texture = nullptr;

    // This variable is responsible for handling a texture resource as image data.
    ID3D11ShaderResourceView* m_textureFromImg;

};
