//
//  QuarkViewController.m
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#import "Quark/Game.h"
#import "Quark/System.h"
#import "Quark/iOS/View.h"
#import "Quark/iOS/ViewController.h"

@implementation QuarkViewController

- (id)initWithGame:(Quark::Game*)aGame system:(Quark::System*)aSystem
{
    started = false;
    game = aGame;
    system = aSystem;
    lastTimestamp = 0;
    return [self init];
}

- (void)loadView
{
    game->configure();
    self.view = [[QuarkView alloc] initWithQuarkSystem:(*system)];
    system->getScreen().setView((__bridge void*)self.view);
}

- (void)start
{
    game->initialize();
    CADisplayLink *displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(update:)];
    [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    lastTimestamp = CACurrentMediaTime();
    started = true;
}

- (void)viewDidLayoutSubviews {
    if(!started) {
        [self start];
    }
}

- (void)update:(CADisplayLink *)displayLink
{
    CFTimeInterval timeDelta = displayLink.timestamp-lastTimestamp;
    lastTimestamp = displayLink.timestamp;
    game->update(timeDelta);
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}

-(void)dealloc
{
    delete game;
    delete system;
}

@end
