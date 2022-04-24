/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "AppDelegate.h"
#include "Scenes/MainScene.h"
#include "ECS/ECS_Log.h"

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(800, 600);
//static cocos2d::Size smallResolutionSize = cocos2d::Size(640, 480);
//static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
//static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);
//this is used in case you have more assets to load them for different resolutions

AppDelegate::AppDelegate() : m_ECS_Engine(nullptr)
{
	
}

AppDelegate::~AppDelegate() 
{
	if (m_ECS_Engine)
	{
		m_ECS_Engine->shutdown();
	}

	ECS_Log::shutdown();
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching()
{
	ECS_Log::init();
	ECS_Log::s_logger->debug("AppDelegate applicationDidFinishLaunching");
	ECS_Log::s_logger->flush();
    // initialize director
    auto director = Director::getInstance();

	if (!director)
	{
#ifdef _DEBUG
		cocos2d::log("[AppDelegate] director is nullptr");
#endif
		return false;
	}

    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("AOG", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("AOG");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::EXACT_FIT);
    auto frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
   /* if (frameSize.height > mediumResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {        
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }*/

	director->setContentScaleFactor(1.0f);

    register_all_packages();

	auto fileUtils = FileUtils::getInstance();
	std::vector<std::string> searchPaths;

	searchPaths.push_back("fonts");
	searchPaths.push_back("ogg");
	searchPaths.push_back("music");
	searchPaths.push_back("interface");
	searchPaths.push_back("map");
	searchPaths.push_back("graphics");
	searchPaths.push_back("ini");
	searchPaths.push_back("images");
	searchPaths.push_back("json");
	
	fileUtils->setSearchPaths(searchPaths);


	m_ECS_Engine = ECS::ECS_Engine::getInstance();
	if (m_ECS_Engine)
	{
		if (!m_ECS_Engine->start())
		{
#ifdef _DEBUG
			cocos2d::log("[AppDelegate] ECS Engine Failed to start");
#endif
			return false;
		}
	}
	else
	{
#ifdef _DEBUG
		cocos2d::log("[AppDelegate] m_ECS_Engine is nullptr");
#endif
		return false;
	}
	

	// create a scene. it's an autorelease object
	auto scene = MainScene::createScene();

	// run
	director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

	m_ECS_Engine->applicationDidEnterBackground();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

	m_ECS_Engine->applicationWillEnterForeground();
}
