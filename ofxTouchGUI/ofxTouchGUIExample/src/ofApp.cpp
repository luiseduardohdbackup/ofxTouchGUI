#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofBackground(20);
    
    // defaults
    mouseX = mouseY = 0;
    sliderValX = 0.69f;
    sliderValY = 30;
    toggleValA = true;
    toggleValB = false;
    selectListIndex = 1;
    string ddOptions[] = {"Oranges", "Bananas", "Apples", "Kiwis", "Mangoes"};
    string description = "ofxTouchGUI includes slider, dropdown list, button/image button, toggle button, text/title fields, input text (ios only atm), and general fixed variables. All items are custom positioned/sized on creation. Colours, fonts, etc can be changed. Settings can be saved to XML. Values can be sent via OSC.";
    
    
    // settings
    settings.loadSettings("settings.xml", false, true); // savefile, default font, use mouse
    settings.loadFonts("stan0755.ttf", "VAGRoundedStd-Light.otf", 6, 14, true); // optional
    settings.setupSendOSC("127.0.0.1", 4444); // optional
    
    // add controls
    settings.addTitleText("ofxTouchGUI");
    settings.addSlider("SLIDER X", &sliderValX, 0.0f, 1.0f);
    settings.addSlider("SLIDER Y", &sliderValY, 0, 100);
    settings.addDropDown("DROPDOWN LIST A", 5, ddOptions);
    settings.addDropDown("DROPDOWN LIST B", 4, &selectListIndex, ddOptions);
    settings.addToggleButton("TOGGLE A", &toggleValA);
    settings.addToggleButton("TOGGLE B", &toggleValB);
    settings.setItemSize(200, 100);
    graph= settings.addTimeGraph("GRAPH MOUSE X", 500);
    graph->setCustomRange(0, ofGetWidth());
    settings.setItemSize(200, 25);
    settings.addText(description);
    settings.addButton("SAVE");
    settings.addButton("RESET");    
    
    
    // adds a listener to all gui items, pointing to onGuiChanged();
    settings.addEventListenerAllItems(this);
}


void ofApp::onGuiChanged(const void* sender, string &buttonLabel) {
    
    // could use the pointer to item that was pressed? eg.
    ofxTouchGUIBase * guiItem = (ofxTouchGUIBase*)sender;
    
    // or just use the label as the identifier
    if(buttonLabel == "SAVE") {
        settings.saveSettings();
    }
    else if(buttonLabel == "RESET") {
        settings.resetDefaultValues();
    }    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    settings.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    graph->insertValue(x);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}