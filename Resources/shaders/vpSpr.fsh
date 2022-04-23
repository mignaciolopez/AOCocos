#ifdef GL_ES
precision mediump float;
#endif

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
varying vec4 v_ecPos;

uniform float u_ambientIntensity;
uniform vec3 u_ambientColor;

uniform vec2 u_pos;
uniform vec3 u_color;
uniform float u_intensity;
uniform vec3 u_att;
uniform int u_lightCount;

void main(void)
{
	vec4 texture = texture2D(CC_Texture0, v_texCoord);
	
	gl_FragColor.xyz = texture.xyz * u_ambientIntensity * u_ambientColor;
	gl_FragColor.w = texture.w;
       
	float dist = distance(gl_FragCoord.xy, u_pos.xy);
	float att = 1.0 / (u_att.x + u_att.y * dist + u_att.z * dist * dist);
	gl_FragColor += texture * vec4(vec3(att) * u_color, 1.0) * u_intensity;
}