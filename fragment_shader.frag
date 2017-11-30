uniform sampler2D texture;
uniform float total_time;

void main()
{
    // lookup the pixel in the texture
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	pixel.r = gl_FragCoord.x / 1000;

    // multiply it by the vertex color
    gl_FragColor = gl_Color * pixel;
}