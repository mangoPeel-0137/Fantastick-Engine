#pragma once



// Engine architecture structs in one file
// Nvm im switching to ECS


struct Vector2
{
	float x, y;
};

struct Vector3
{
	float x, y, z;
};

struct Color3
{
	float r, g, b;
};

struct Vertex
{
	Vector2 position;
	Vector2 uvs;
	Color3 color;
};


struct Transform
{
	Vector2 Position;
	Vector2 Scale;
	Vector2 Rotation;

};








