uniform float total_time;

void main()
{
    // transform the vertex position
	vec4 scaled = gl_Vertex;
	scaled.x += cos(total_time) * 200;
	scaled.y += sin(total_time) * 200;
    gl_Position = gl_ModelViewProjectionMatrix * scaled;

    // transform the texture coordinates
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

    // forward the vertex color
    gl_FrontColor = gl_Color;
}