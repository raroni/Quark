//
//  QuarkViewController.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#import <UIKit/UIKit.h>

namespace Quark {
    class Game;
    class System;
}

@interface QuarkViewController : UIViewController
{
    Quark::Game* game;
    Quark::System* system;
}
- (id)initWithGame:(Quark::Game*)aGame system:(Quark::System*)aSystem;
- (void)run;
@end
