uniform vec2 scale;

void main()
{
	gl_Position = ftransform();
	gl_TexCoord[0].st = gl_MultiTexCoord0.st * scale;
}