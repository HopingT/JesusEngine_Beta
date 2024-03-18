#include "Buffer.h"
#include "Device.h"
#include "DeviceContext.h"

void Buffer::init(Device device, Mesh mesh, unsigned int bindFlag)
{
    // Revisamos si el dispositivo es nulo
    if (device.m_device == nullptr)
    {
        WARNING("ERROR: Buffer::init : Error en los datos de los parámetros [VERIFICAR Device device]\n");
        exit(1);
    }

    // Definimos el descriptor de la estructura vertex o index
    HRESULT hr = S_OK;
    D3D11_BUFFER_DESC desc;
    D3D11_SUBRESOURCE_DATA InitData;

    memset(&desc, 0, sizeof(desc));
    memset(&InitData, 0, sizeof(InitData));

    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.CPUAccessFlags = 0;
    m_bindFlag = bindFlag;

    // Validamos el tipo de buffer a ser utilizado
    if (bindFlag == D3D11_BIND_VERTEX_BUFFER)
    {
        if (mesh.vertex.size() == 0 || mesh.numVertex == 0)
        {
            WARNING("ERROR: Buffer::init : Error en los datos de los parámetros [VERIFICAR Mesh mesh VERTEX]\n");
            exit(1);
        }
        // Inicializamos el descriptor para el buffer de vértices
        m_stride = sizeof(SimpleVertex);
        desc.ByteWidth = m_stride * mesh.numVertex;
        desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        // Inicializamos el Subresource con los datos de los vértices
        InitData.pSysMem = mesh.vertex.data();
    }
    else if (bindFlag == D3D11_BIND_INDEX_BUFFER)
    {
        if (mesh.index.size() == 0 || mesh.numIndex == 0)
        {
            WARNING("ERROR: Buffer::init : Error en los datos de los parámetros [VERIFICAR Mesh mesh INDEX]\n");
            exit(1);
        }
        // Inicializamos el descriptor para el buffer de índices
        m_stride = sizeof(unsigned int);
        desc.ByteWidth = m_stride * mesh.numIndex;
        desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
        // Inicializamos el Subresource con los datos de los índices
        InitData.pSysMem = mesh.index.data();
    }

    // Creamos el Buffer
    hr = device.CreateBuffer(&desc, &InitData, &m_buffer);

    if (FAILED(hr))
    {
        WARNING("ERROR: Buffer::init : Error en los datos del método [VERIFICAR CreateBuffer()]\n");
        exit(1);
    }
}

void Buffer::init(Device device, unsigned int ByteWidth)
{
    if (device.m_device == nullptr)
    {
        WARNING("ERROR: Buffer::init : Error en los datos de los parámetros [VERIFICAR Device device]\n");
        exit(1);
    }
    else if (ByteWidth == 0)
    {
        WARNING("ERROR: Buffer::init : Error en los datos de los parámetros [VERIFICAR unsigned int ByteWidth]\n");
        exit(1);
    }

    m_stride = ByteWidth;

    // Definimos el descriptor para el buffer constante
    HRESULT hr = S_OK;
    D3D11_BUFFER_DESC desc;
    memset(&desc, 0, sizeof(desc));
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.CPUAccessFlags = 0;
    desc.ByteWidth = m_stride;
    desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    desc.CPUAccessFlags = 0;

    // Creamos el buffer
    hr = device.CreateBuffer(&desc, nullptr, &m_buffer);
    if (FAILED(hr))
    {
        WARNING("ERROR: Buffer::init : Error en los datos del método [VERIFICAR CreateBuffer()]\n");
        exit(1);
    }
}

void Buffer::update(DeviceContext& deviceContext,
    unsigned int DstSubresource,
    const D3D11_BOX* pDstBox,
    const void* pSrcData,
    unsigned int SrcRowPitch,
    unsigned int SrcDepthPitch)
{
    // Actualizamos los datos del buffer
    deviceContext.UpdateSubresource(m_buffer,
        DstSubresource,
        pDstBox,
        pSrcData,
        SrcRowPitch,
        SrcDepthPitch);
}

void Buffer::render(DeviceContext& deviceContext,
    unsigned int StarSlot,
    unsigned int NumBuffers)
{
    // Renderizamos el buffer de vértices
    if (m_bindFlag == D3D11_BIND_VERTEX_BUFFER)
    {
        deviceContext.IASetVertexBuffer(StarSlot, NumBuffers, &m_buffer, &m_stride, &m_offset);
    }
    else
    {
        // Advertencia si se intenta renderizar un buffer que no es de vértices
        WARNING("WARNING: Buffer::render : Intentando renderizar en D3D11_IND_INDEX_BUFFER BindFlag, Verificar métodos render()\n");
    }
}

void Buffer::render(DeviceContext& deviceContext, DXGI_FORMAT format)
{
    // Renderizamos el buffer de índices
    if (m_bindFlag == D3D11_BIND_INDEX_BUFFER)
    {
        deviceContext.IASetIndexBuffer(m_buffer, format, m_offset);
    }
    else
    {
        // Advertencia si se intenta renderizar un buffer que no es de índices
        WARNING("WARNING: Buffer::render : Intentando renderizar en D3D11_IND_VERTEX_BUFFER BindFlag, Verificar métodos render()\n");
    }
}

void Buffer::destroy()
{
    // Liberamos el buffer
    SAFE_RELEASE(m_buffer);
}
