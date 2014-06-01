uniform sampler2D tex0;
uniform samplerCube	EnvMap;

varying vec3 reflectDir;
varying vec4 position;
varying vec3 normal;

void main (void)
{
    vec3 nn = normalize(normal);
    
    vec4 color = texture2DProj(tex0, gl_TexCoord[0]);
    vec3 light = normalize((gl_LightSource[0].position * position.w - gl_LightSource[0].position.w * position).xyz);
    float diffuse = max(dot(light, nn), 0.0);
    
    vec3 view = -normalize(position.xyz);
    vec3 halfway = normalize(light + view);
    float specular = pow(max(dot(nn, halfway), 0.0), gl_FrontMaterial.shininess);
    vec4 base = color * (gl_LightSource[0].diffuse * diffuse
                         + gl_LightSource[0].ambient)
    + gl_FrontLightProduct[0].specular * specular;
    
	vec3 envColor = textureCube( EnvMap, normalize(reflectDir) ).rgb;
    
    gl_FragColor.rgb = mix( envColor, base.xyz, 0.0 );
}