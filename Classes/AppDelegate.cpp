#include "AppDelegate.h"
#include "extensions/cocos-ext.h"
#include "ECS/ECS_Engine.h"
#include "Scenes/MainScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() : m_ECS_Engine(nullptr)
{
}

AppDelegate::~AppDelegate()
{
	ECS::ECS_Engine::destroyInstance();
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
	// set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8, 0 };

	GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview)
	{
		glview = GLViewImpl::create("Industria Argentina");
		director->setOpenGLView(glview);
	}

	// turn on display FPS
	director->setDisplayStats(true);

	//Turn OF VSync
	glview->setSwapInterval(0);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0f / 60);

	glview->setFrameSize(800.0f, 600.0f);
	//auto screenSize = glview->getFrameSize();
	auto designSize = Size(800, 600);

	auto fileUtils = FileUtils::getInstance();
	std::vector<std::string> searchPaths;

	//auto resourceSize = Size(960, 640);
	//director->setContentScaleFactor(resourceSize.height / designSize.height);

	searchPaths.push_back("fonts");
	searchPaths.push_back("Graphics");
	searchPaths.push_back("Images");
	searchPaths.push_back("Interface");
	searchPaths.push_back("Map");
	searchPaths.push_back("mp3");
	searchPaths.push_back("WAV");

	fileUtils->setSearchPaths(searchPaths);

	// Set the design resolution
	glview->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::EXACT_FIT);

	//Enable Remote Console
	//auto console = director->getConsole();
	//console->listenOnTCP(5678);

	m_ECS_Engine = ECS::ECS_Engine::getInstance();

	auto mainScene = MainScene::createScene();
	if (!mainScene)
		return false;

	director->runWithScene(mainScene);

	return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground()
{
	m_ECS_Engine->applicationDidEnterBackground();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
	m_ECS_Engine->applicationWillEnterForeground();
}
