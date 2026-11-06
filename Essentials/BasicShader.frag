#version 330 core

out vec4 FragColor;
uniform sampler2D u_Texture;
in vec2 v_TexCoord;

void main() {
	vec4 TexColor = texture(u_Texture, v_TexCoord);
	FragColor = TexColor;
}
