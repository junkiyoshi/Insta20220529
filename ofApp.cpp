#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateZ(ofGetFrameNum() * 0.66);

	float v_step = 2;

	for (float v = 0; v < 360; v += v_step) {

		for (int i = 0; i < 4; i++) {

			auto u = ofMap(ofNoise(cos(v * DEG_TO_RAD) * 0.75, sin(v * DEG_TO_RAD) * 0.75, ofGetFrameNum() * 0.005), 0, 1, -360, 360) + i * 90;
			auto location = this->make_point(300, 60, u, v);

			ofPushMatrix();
			ofTranslate(location);

			ofSetColor(0);
			ofFill();
			ofDrawBox(10.5);

			ofSetColor(255);
			ofNoFill();
			ofDrawBox(10.5);

			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.31

	u *= DEG_TO_RAD;
	v *= DEG_TO_RAD;

	auto x = (R + r * cos(u)) * cos(v);
	auto y = (R + r * cos(u)) * sin(v);
	auto z = r * sin(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}