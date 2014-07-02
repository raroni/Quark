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
}

@interface QuarkViewController : UIViewController
{
    Quark::Game* game;
}
- (id)initWithGame:(Quark::Game*)aGame;
- (void)run;
@end
