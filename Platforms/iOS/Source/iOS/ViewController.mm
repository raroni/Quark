//
//  QuarkViewController.m
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Game.h"
#import "Quark/iOS/View.h"
#import "Quark/iOS/ViewController.h"

@implementation QuarkViewController

- (id)initWithGame:(Quark::Game*)aGame
{
    game = aGame;
    return [self initWithNibName:nil bundle:nil];
}

- (void)loadView
{
    Quark::TouchSurface& touchSurface = game->getTouchSurface();
    Quark::Screen& screen = game->getScreen();
    QuarkView *view = [[QuarkView alloc] initWithQuarkScreen:screen QuarkTouchSurface:touchSurface];
    self.view = view;
}

- (void)run
{
    game->initialize();
    CADisplayLink *displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(tick:)];
    [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
}

- (void)tick:(CADisplayLink *)displayLink
{
    game->update(displayLink.duration);
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}

-(void)dealloc
{
    delete game;
}

@end
