#include "ModelLoader.h"
#include "OBJ_Loader.h"

// M�todos de inicializaci�n, actualizaci�n, renderizado y destrucci�n
// que actualmente est�n vac�os pero pueden ser implementados seg�n sea necesario.
void ModelLoader::init()
{
}

void ModelLoader::update()
{
}

void ModelLoader::render()
{
}

void ModelLoader::destroy()
{
}

/// <summary>
/// Carga un modelo desde un archivo OBJ y lo convierte en una estructura Mesh personalizada.
/// Esta funci�n lee la geometr�a de un modelo 3D (v�rtices y texturas) desde un archivo OBJ,
/// utilizando la biblioteca OBJ_Loader para facilitar la carga de datos, y luego organiza
/// estos datos en una estructura Mesh propia de la aplicaci�n, que incluye posiciones de v�rtices,
/// coordenadas de texturas y un conjunto de �ndices para renderizar el modelo.
/// </summary>
/// <param name="objFileName">El nombre del archivo OBJ a cargar.</param>
/// <returns>Una estructura Mesh que contiene toda la geometr�a y datos del modelo cargado.</returns>
Mesh
ModelLoader::Load(std::string objFileName)
{
    // Datos temporales para cargar
    Mesh mesh;
    objl::Loader Loader;
    Loader.LoadFile(objFileName); // Utiliza objl::Loader para cargar el archivo OBJ.

    mesh.name = objFileName; // Guarda el nombre del archivo como referencia en la malla.

    WARNING("ModelLoader::Load() [Load of file: " << objFileName.c_str() << "] \n");

    // Carga y establece datos en la estructura personalizada SimpleVertex.
    mesh.vertex.resize(Loader.LoadedVertices.size()); // Redimensiona el vector para los v�rtices.

    // Itera sobre cada v�rtice cargado y lo asigna a la estructura de malla.
    for (int i = 0; i < mesh.vertex.size(); i++)
    {
        // Carga las posiciones
        mesh.vertex[i].Pos.x = Loader.LoadedVertices[i].Position.X;
        mesh.vertex[i].Pos.y = Loader.LoadedVertices[i].Position.Y;
        mesh.vertex[i].Pos.z = Loader.LoadedVertices[i].Position.Z;

        // Carga las texturas
        mesh.vertex[i].Tex.x = Loader.LoadedVertices[i].TextureCoordinate.X;
        mesh.vertex[i].Tex.y = Loader.LoadedVertices[i].TextureCoordinate.Y;
    }

    // Carga y establece datos en el vector de �ndices para la malla.
    mesh.index.resize(Loader.LoadedIndices.size()); // Redimensiona el vector para los �ndices.
    for (int i = 0; i < mesh.index.size(); i++)
    {
        mesh.index[i] = Loader.LoadedIndices[i]; // Asigna cada �ndice.
    }

    // Guarda la cantidad de v�rtices y de �ndices en la estructura de la malla.
    mesh.numVertex = mesh.vertex.size();
    mesh.numIndex = mesh.index.size();

    return mesh; // Retorna la malla cargada y preparada para ser utilizada.
}
