/**
 * @package  3dmixer
 * @author  Andrew Sliwinski <andrew@unitedworkshop.com>
 */
 
/**
 * Includes
 */
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

/**
 * Primary application init. GLUT and GL context setup passed to instance of OF.
 *
 * @param  void
 *
 * @return  void
 */
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1024,768, OF_WINDOW);

	ofRunApp( new testApp() );

}
