#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofDisableArbTex();
    //ofSetFrameRate(30);
    ofSetVerticalSync(true);
    ofSetWindowShape(1280, 720);
   
    sphere = sphere.sphere(1.0f, 480, OF_PRIMITIVE_TRIANGLE_STRIP);

    shader.setGeometryInputType(GL_TRIANGLES);
	shader.setGeometryOutputType(GL_TRIANGLES);
	shader.setGeometryOutputCount(3);
    shader.load("shaders/noise.vs", "shaders/noise.fs", "shaders/noise.gs");

    camera.setFov(30.0f);
    
    light.setPosition(0, 0, 200);
    light.lookAt(ofVec3f());
    light.setAmbientColor( ofFloatColor( 0.1f, 0.1f, 0.1f, 1.0f ) );
    light.setSpecularColor( ofColor(255, 255, 255));
	light.setDiffuseColor( ofColor(224, 224, 224));
    light.setPointLight();

    material.setAmbientColor(ofFloatColor(0.19225,  0.19225,  0.19225));
    material.setDiffuseColor(ofFloatColor(0.50754,  0.50754,  0.50754));
    material.setSpecularColor(ofFloatColor(0.508273, 0.508273, 0.508273));
    material.setShininess( 51.2 );

    ofLoadImage(tex, "textures/white.png");
    
    img[0].loadImage("textures/grandcanyon_positive_x.jpg");
    img[1].loadImage("textures/grandcanyon_negative_x.jpg");
    img[2].loadImage("textures/grandcanyon_positive_y.jpg");
    img[3].loadImage("textures/grandcanyon_negative_y.jpg");
    img[4].loadImage("textures/grandcanyon_positive_z.jpg");
    img[5].loadImage("textures/grandcanyon_negative_z.jpg");
    cube.setFromImages(512, img[0], img[1], img[2], img[3], img[4], img[5]);
    
    np = 0.0f;
}

//--------------------------------------------------------------
void testApp::update(){
    cameraPosition = ofVec3f( 559.0f*sin(ofGetFrameNum() / 180.0f * PI ), 0.0f, 559.0f*cos(ofGetFrameNum() / 180.0f * PI ) );
    camera.setGlobalPosition( cameraPosition );
    camera.lookAt( ofVec3f( 0.0f, 0.0f, 0.0f ) );
    
    np+=1.0f;
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableDepthTest();
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    ofEnableLighting();
    ofDisableAlphaBlending();
    ofSetSmoothLighting(true);

    camera.begin();

    light.enable();
    material.begin();

    cube.bind();
    
    shader.begin();
    shader.setUniformTexture("tex0", tex, tex.getTextureData().textureID);
    shader.setUniform1f("noiseParam", np);
    shader.setUniform3f("cameraPosition", cameraPosition.x, cameraPosition.y, cameraPosition.z);
    
    sphere.draw();
    
    shader.end();
    
    cube.unbind();
    
    material.end();
    light.disable();
    ofDisableLighting();

    int width = 256;

    img[0].bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(width, width, width);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(width, -width, width);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, -width, -width);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, width, -width);
    glEnd();
    img[0].unbind();

    img[1].bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-width, width, -width);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-width, -width, -width);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-width, -width, width);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-width, width, width);
    glEnd();
    img[1].unbind();

    img[2].bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-width, width, -width);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-width, width, width);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, width, width);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, width, -width);
    glEnd();
    img[2].unbind();

    img[3].bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-width, -width, width);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-width, -width, -width);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, -width, -width);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, -width, width);
    glEnd();
    img[3].unbind();

    img[4].bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-width, width, width);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-width, -width, width);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, -width, width);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, width, width);
    glEnd();
    img[4].unbind();

    img[5].bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(width, width, -width);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(width, -width, -width);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-width, -width, -width);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-width, width, -width);
    glEnd();
    img[5].unbind();


    camera.end();
    
    ofDisableDepthTest();
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
