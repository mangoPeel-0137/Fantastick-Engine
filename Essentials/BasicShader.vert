#version 330 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec2 aTexCoords;

out vec2 v_TexCoord;

uniform mat4 u_mvp;

void main(){
	gl_Position = u_mvp * vec4(aPosition.x, aPosition.y, aPosition.z, 1.0);
	v_TexCoord = aTexCoords;
}
